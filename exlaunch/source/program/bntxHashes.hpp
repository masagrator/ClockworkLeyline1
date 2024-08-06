#include <stdexcept>

struct hashTable {
	uint64_t hash;
	const char filepath[36];
};

template <typename T> constexpr uint64_t has_duplicates(const T *array, std::size_t size)
{
	for (std::size_t i = 1; i < size; i++)
		for (std::size_t j = 0; j < i; j++)
			if (array[i].hash == array[j].hash) {
				return array[i].hash;
			}
	return 0;
}

constexpr hashTable BNTX_HASHES[] = {
	{0x4029B6547B64A916lu, "allpachd/L1_ETC001A"},
	{0xC00406BA41D9A362lu, "allpachd/L1_SD002A"},
	{0xD57F30F3E3EB0F1Flu, "allpachd/L1_ETC015A"},
	{0x34CD3486EBB54F6Clu, "allpachd/L1_ETC018A"},
	{0xA8418E51C1F6BFB7lu, "allpachd/L1_ETC019A"},
	{0x4062FE1F4D2624F9lu, "allpachd/L1_ETC_T002"},
	{0xBADFE34698D8A734lu, "allui/CONF_PARTS_JA"},
	{0xB2B25F6A52C9AB86lu, "allui/DIALOG_PARTS_JA"},
	{0xD88B5C31DBFB8B64lu, "allui/DISP_PARTS_JA"},
	{0x6E98C45531D3D244lu, "allui/EXTRA_ANOTHER_PARTS_JA"},
	{0x70C3AC7AC3CD0C20lu, "allui/EXTRA_BGM_PARTS_JA"},
	{0xD90E4DC381EB2F9Blu, "allui/EXTRA_CG_PARTS_JA"},
	{0x08285A81BA34B186lu, "allui/EXTRA_DIARY_PARTS_JA"},
	{0x0D39CDD8D17B027Blu, "allui/EXTRA_MOVIE_PARTS_JA"},
	{0xACD2E0F1609C11A9lu, "allui/MANUAL_PARTS_JA"},
	{0x45F15F39339759FClu, "allui/MENU_PARTS_JA"},
	{0xBB3E807EB3C7F60Alu, "allui/MODEPNL_PARTS_JA"},
	{0x49E75D7AE3E07BDFlu, "allui/SAVE_PARTS_JA"},
	{0x04067F54E9DD8ED4lu, "allui/TITLE_PARTS_JA"}
};

static_assert(!has_duplicates(BNTX_HASHES, std::size(BNTX_HASHES)), "Detected repeated hash!");

const char* compareHashes(uint64_t hashToCompare) {
	for(size_t i = 0; i < std::size(BNTX_HASHES); i++)
		if (BNTX_HASHES[i].hash == hashToCompare) 
			return BNTX_HASHES[i].filepath;
	return nullptr;
}