#include "lib.hpp"
#include "ENG.hpp"
#include "nn/fs.hpp"
#include "nn/util/util_gzip.hpp"
#include "xxhash/xxhash.h"
#include "bntxHashes.hpp"
#include "OTHER.hpp"

void* jumps_buffer = 0;
void* scenario_buffer = 0;

ptrdiff_t returnInstructionOffset(uintptr_t LR) {
	return LR - exl::util::modules::GetTargetOffset(0);
}

HOOK_DEFINE_TRAMPOLINE(allscr_LoadJumpsFile) {
	static void* Callback(uint16_t ID, void* file) {
		if ((size_t)ID >= FILENAMES.size()) {
			return Orig(ID, file);
		}
		nn::fs::FileHandle filehandle;
		char filepath[128] = "";
		snprintf(&filepath[0], 128, "rom:/scenario/%s.mzx0", FILENAMES[ID]);
		if (R_FAILED(nn::fs::OpenFile(&filehandle, filepath, nn::fs::OpenMode_Read))) {
			return Orig(ID, file);
		}
		nn::fs::CloseFile(filehandle);
		snprintf(&filepath[0], 128, "rom:/scenario/JUMPS/%s.txt", FILENAMES[ID]);
		if (R_FAILED(nn::fs::OpenFile(&filehandle, filepath, nn::fs::OpenMode_Read))) {
			return Orig(ID, file);
		}
		long in_size = 0;
		nn::fs::GetFileSize(&in_size, filehandle);
		if (jumps_buffer)
			nn::util::GzipFree(jumps_buffer);
		jumps_buffer = nn::util::GzipAllocate(in_size);
		nn::fs::ReadFile(filehandle, 0, jumps_buffer, in_size);
		nn::fs::CloseFile(filehandle);
		return jumps_buffer;
	}
};

HOOK_DEFINE_TRAMPOLINE(allscr_LoadFile) {
	static void* Callback(uint16_t ID, uint32_t wbits) {
		if (ID > 3) {
			if ((size_t)(ID - 3) >= FILENAMES.size()) {
				return Orig(ID, wbits);
			}
			nn::fs::FileHandle filehandle;
			char filepath[128] = "";
			snprintf(&filepath[0], 128, "rom:/scenario/JUMPS/%s.txt", FILENAMES[ID - 3]);
			if (R_FAILED(nn::fs::OpenFile(&filehandle, filepath, nn::fs::OpenMode_Read))) {
				return Orig(ID, wbits);
			}
			nn::fs::CloseFile(filehandle);		
			snprintf(&filepath[0], 128, "rom:/scenario/%s.mzx0", FILENAMES[ID - 3]);
			if (R_FAILED(nn::fs::OpenFile(&filehandle, filepath, nn::fs::OpenMode_Read))) {
				return Orig(ID, wbits);
			}
			long in_size = 0;
			nn::fs::GetFileSize(&in_size, filehandle);
			if (scenario_buffer)
				nn::util::GzipFree(scenario_buffer);
			scenario_buffer = nn::util::GzipAllocate(in_size);
			nn::fs::ReadFile(filehandle, 0, scenario_buffer, in_size);
			nn::fs::CloseFile(filehandle);
			return scenario_buffer;
		}
		return Orig(ID, wbits);
	}
};

HOOK_DEFINE_TRAMPOLINE(get_MAIN_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::MAIN_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CONFIG_TABS_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CONFIG_TABS_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CONFIG_SOUND_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CONFIG_SOUND_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CONFIG_VOICE_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CONFIG_VOICE_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CONFIG_TEXT_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CONFIG_TEXT_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CONFIG_MODE_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CONFIG_MODE_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CONFIG_SYSTEM_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CONFIG_SYSTEM_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_FONT_NAME_item) {
	static auto Callback(uint32_t item) {
		return ENG::FONT_NAMES[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_EXTRA_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::EXTRA_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_CGMODE_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::CGMODE_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_BGMMODE_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::BGMMODE_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_MOVIEMODE_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::MOVIEMODE_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_PIECEOFDIARY_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::PIECEOFDIARY_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_ANOTHERSTORY_MENU_DESCRIPTIONS_item) {
	static auto Callback(uint32_t item) {
		return ENG::ANOTHERSTORY_MENU_DESCRIPTIONS[item];
	}
};

HOOK_DEFINE_TRAMPOLINE(get_SYSMES_TEXT_item) {
	static auto Callback(uint32_t item) {
		return ENG::SYSMES_TEXT[item];
	}
};

struct BNTX_FILE {
	char MAGIC[4];
	char reserved[0x18];
	uint32_t file_size;
};

HOOK_DEFINE_TRAMPOLINE(BNTX_MAGIC_CHECK) {
	static bool Callback(BNTX_FILE* file) {
		if (!Orig(file)) 
			return false;
		XXH64_hash_t hash_output = XXH3_64bits((void*)file, (file->file_size > 0x1000) ? 0x1000 : file->file_size);
		const char* index = compareHashes(hash_output);
		if (index != nullptr) {
			char filepath[128] = "";
			nn::fs::FileHandle filehandle;
			snprintf(&filepath[0], 128, "rom:/textures/%s.bntx.gz", index);
			if (R_FAILED(nn::fs::OpenFile(&filehandle, filepath, nn::fs::OpenMode_Read)))
				return true;
			if (nn::util::GetGzipDecompressedSizeFromFile(filehandle) > file->file_size) {
				nn::fs::CloseFile(filehandle);
				return true;				
			}
			long in_size = 0;
			nn::fs::GetFileSize(&in_size, filehandle);
			void* buffer = nn::util::GzipAllocate(in_size);
			nn::fs::ReadFile(filehandle, 0, buffer, in_size);
			nn::fs::CloseFile(filehandle);
			char gzipWorkBuffer[nn::util::DecompressGzipWorkBufferSize] = "";
			nn::util::DecompressGzip(file, file->file_size, buffer, in_size, &gzipWorkBuffer[0], sizeof(gzipWorkBuffer));
			nn::util::GzipFree(buffer);
		}
		return true;
	}
};

extern "C" void exl_main(void* x0, void* x1) {

	nn::fs::SetResultHandledByApplication(true);
	
	exl::hook::Initialize();
	allscr_LoadFile::InstallAtOffset(0xAE100);
	allscr_LoadJumpsFile::InstallAtOffset(0xAE050);
	get_MAIN_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4B10);
	get_CONFIG_TABS_DESCRIPTIONS_item::InstallAtOffset(0xC4B20);
	get_CONFIG_SOUND_DESCRIPTIONS_item::InstallAtOffset(0xC4B30);
	get_CONFIG_VOICE_DESCRIPTIONS_item::InstallAtOffset(0xC4B40);
	get_CONFIG_TEXT_DESCRIPTIONS_item::InstallAtOffset(0xC4B50);
	get_CONFIG_MODE_DESCRIPTIONS_item::InstallAtOffset(0xC4B60);
	get_CONFIG_SYSTEM_DESCRIPTIONS_item::InstallAtOffset(0xC4B70);
	get_FONT_NAME_item::InstallAtOffset(0xC4B80);
	get_EXTRA_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4B90);
	get_CGMODE_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4BA0);
	get_BGMMODE_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4BC0);
	get_MOVIEMODE_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4BE0);
	get_PIECEOFDIARY_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4C00);
	get_ANOTHERSTORY_MENU_DESCRIPTIONS_item::InstallAtOffset(0xC4C20);
	get_SYSMES_TEXT_item::InstallAtOffset(0x98990);
	BNTX_MAGIC_CHECK::InstallAtOffset(0x160480);
	
	//Function used by game to render messages: 0x3EAE0

	//Patch text rendering to not add additional space between characters and between lines for messages and backlog
	exl::patch::CodePatcher patcher{0xA22B4};
	patcher.WriteInst(0x1E2703E0);
	patcher.Seek(0xA22E4);
	patcher.WriteInst(0x1E2703E1);
	patcher.Seek(0xA2364);
	patcher.WriteInst(0x1E2703E0);
	patcher.Seek(0xA2388);
	patcher.WriteInst(0x1E2703E0);
	patcher.Seek(0xA26D8);
	patcher.WriteInst(0x1E2703E0);
	patcher.Seek(0xA2700);
	patcher.WriteInst(0x1E2703E1);

	patcher.Seek(0xA3020);
	patcher.WriteInst(0x1E2703E2);
	patcher.Seek(0xA304C);
	patcher.WriteInst(0x1E2703E1);


	///Note: Game has broken automatic break line injection, from second line it breaks line at the half of length of first line (so it's not a fixed value). 
	///Automatic break line injection can be blocked by adding break lines manually.
	//Patch text rendering to allow longer lines for messages and names
	union {
		float value_f;
		int value_i;
	} message_box_width, name_box_width;

	patcher.Seek(0x34BEC8);
	message_box_width.value_f = 480;
	patcher.WriteInst(message_box_width.value_i);

	patcher.Seek(0x34BAFC);
	name_box_width.value_f = 240;
	patcher.WriteInst(name_box_width.value_i);

}

extern "C" NORETURN void exl_exception_entry() {
	/* TODO: exception handling */
	EXL_ABORT(0x420);
}