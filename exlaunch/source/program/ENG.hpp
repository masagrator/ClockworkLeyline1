#include <array>

namespace ENG {

	std::array MAIN_MENU_DESCRIPTIONS = {
		"Start 『The Borderline of Dusk』",
		"Start 『Daybreak of Remnants Shadow』",
		"Start 『Flowers Falling in the Morning Mist』",
		"Start 『Witch Wandering in the Heat Haze』",
		"Continue from where you left last time",
		"Load save",
		"Change the game settings",
		"Open the Extra menu",
		"Open the Operations Manual",
		"Complete first 『The Borderline of Dusk』",
		"Complete first 『Daybreak of Remnants Shadow』",
		"Complete first 『Flowers Falling in the Morning Mist』",
		"　",
		"Not available in the trial version."
	};

	static_assert(MAIN_MENU_DESCRIPTIONS.size() == 14);

	std::array CONFIG_TABS_DESCRIPTIONS = {
		"Configure sound settings",
		"Configure voice settings",
		"Configure text settings",
		"Configure operation settings",
		"Configure system settings",
		"Restore default settings"
	};

	static_assert(CONFIG_TABS_DESCRIPTIONS.size() == 6);

	std::array CONFIG_SOUND_DESCRIPTIONS = {
		"Change music volume",
		"Change voice volume",
		"Change SFX volume",
		"Change SFX system volume",
		"Fix music volume",
		"Decrease music volume during voice audio"
	};

	static_assert(CONFIG_SOUND_DESCRIPTIONS.size() == 6);

	std::array CONFIG_VOICE_DESCRIPTIONS = {
		"Disable/enable voice of Shishigatani Ushio",
		"Disable/enable voice of Karasuma Kotarou",
		"Disable/enable voice of Rito",
		"Disable/enable voice of Mibu Tsubaki",
		"Disable/enable voice of Furoyamachi Neko",
		"Disable/enable voice of Tsuduraorizaka Fuhito",
		"Disable/enable voice of Murakumo Shizuka",
		"Disable/enable voice of Yoshida Soara",
		"Disable/enable voice of Kurodani Maya",
		"Disable/enable voice of Shichiban Hina",
		"Disable/enable voice of Iba Kumiko",
		"Disable/enable voice of Kasuga Mayumi",
		"Disable/enable voice of Murakumo Kasumi",
		"アーデルハイト･リッター･フォン･ヴァインベルガーのボイス出力を設定します",
		"ルイのボイス出力を設定します",
		"諏訪 葵（すわ あおい）のボイス出力を設定します",
		"伏見 みお（ふしみ みお）のボイス出力を設定します",
		"聖護院 百花（しょうごいん ももか）のボイス出力を設定します",
		"久我 満琉（こが みちる）のボイス出力を設定します",
		"花立 睦月（はなたて むつき）のボイス出力を設定します",
		"アーリック・リッター・フォン・ヴァインベルガーのボイス出力を設定します",
		"アンデルのボイス出力を設定します",
		"シグマのボイス出力を設定します",
		"Disable/enable voice of other people",
		"システムボイスの設定を変更します",
		"Do not use the system voice",
		"Use the system voice"
	};

	static_assert(CONFIG_VOICE_DESCRIPTIONS.size() == 27);

	std::array CONFIG_TEXT_DESCRIPTIONS = {
		"Change text display speed",
		"Change the font",
		"Fix text color",
		"Change color of text you've read",
		"Remove the shadow from the text",
		"Add a shadow to the text",
		"Don't show text outline",
		"Show text outline",
		"Change window transparency"
	};

	static_assert(CONFIG_TEXT_DESCRIPTIONS.size() == 9);

	std::array CONFIG_MODE_DESCRIPTIONS = {
		"Change auto-scroll speed",
		"Make all text skippable",
		"Make all text you've read skippable",
		"Don't cancel skipping on decisions",
		"Cancel skipping on decisions",
		"Automatic quick save on selection",
		"No automatic quicksave on selection",
		"Automatic quick save at the beginning of an episode",
		"No automatic quick save at the beginning of an episode",
		"Do not stop voice when skipping text",
		"Skip voice when skipping text"
	};

	static_assert(CONFIG_MODE_DESCRIPTIONS.size() == 11);

	std::array CONFIG_SYSTEM_DESCRIPTIONS = {
		"Disable help text display for buttons",
		"Display help text for buttons",
		"Change button configuration"
	};

	static_assert(CONFIG_SYSTEM_DESCRIPTIONS.size() == 3);

	std::array FONT_NAMES = {
		"Font 1",
		"Font 2",
		"Font 3",
		"Font 4"
	};

	static_assert(FONT_NAMES.size() == 4);

	std::array EXTRA_MENU_DESCRIPTIONS = {
		"Watch the event CGs",
		"Listen to music",
		"Watch movies",
		"View diary fragments",
		"Open the door to your dreams",
		"Watch a recap of 『The Borderline of Dusk』",
		"Watch a recap of 『Daybreak of Remnants Shadow』",
		"Return to the title menu",
		"Currently not available",
		"Complete first 『The Borderline of Dusk』",
		"Complete first 『Daybreak of Remnants Shadow』"
	};

	static_assert(EXTRA_MENU_DESCRIPTIONS.size() == 11);

	std::array CGMODE_MENU_DESCRIPTIONS = {
		"CGs from 『The Borderline of Dusk』",
		"CGs from 『Daybreak of Remnants Shadow』",
		"CGs from 『Flowers Falling in the Morning Mist』",
		"CGs from 『Witch Wandering in the Heat Haze』",
		"Display the 1st page",
		"Display the 2nd page",
		"Display the 3rd page",
		"Display the 4th page",
		"Display the 5th page",
		"Display the 6th page"
	};	

	static_assert(CGMODE_MENU_DESCRIPTIONS.size() == 10);

	std::array BGMMODE_MENU_DESCRIPTIONS = {
		"ＢＧＭを再生します",
		"ＢＧＭを停止します",
		"次の曲に進みます",
		"一曲ループ／全曲ループを切り替えます"
	};

	static_assert(BGMMODE_MENU_DESCRIPTIONS.size() == 4);

	std::array MOVIEMODE_MENU_DESCRIPTIONS = {
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Watch opening movie for 『The Borderline of Dusk』",
		"Watch opening movie for 『Daybreak of Remnants Shadow』",
		"Watch opening movie for 『Flowers Falling in the Morning Mist』",
		"Watch opening movie for 『Witch Wandering in the Heat Haze』"
	};

	static_assert(MOVIEMODE_MENU_DESCRIPTIONS.size() == 8);

	std::array PIECEOFDIARY_MENU_DESCRIPTIONS = {
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Not yet available",
		"Watch Black Diary: Chapter 1",
		"Watch Black Diary: Chapter 2",
		"Watch Black Diary: Chapter 3",
		"Watch Black Diary: Chapter 4",
		"Watch Black Diary: Chapter 5",
		"Watch Black Diary: Chapter 6",
		"Watch Black Diary: Chapter 7",
		"Watch Black Diary: Chapter 8",
		"Watch Black Diary: Chapter 9",
		"Watch Black Diary: Chapter 10",
		"Watch Black Diary: Chapter 11",
		"Watch Black Diary: Chapter 12",
		"Watch Black Diary: Chapter 13",
		"Watch White Diary: Chapter 1",
		"Watch White Diary: Chapter 2",
		"Watch White Diary: Chapter 3",
		"Watch White Diary: Chapter 4",
		"Watch White Diary: Chapter 5",
		"Watch White Diary: Chapter 6",
		"Watch White Diary: Chapter 7",
		"Watch White Diary: Chapter 8",
		"Watch White Diary: Chapter 9",
		"Watch White Diary: Chapter 10",
		"Watch White Diary: Chapter 11",
		"Watch White Diary: Chapter 12",
		"Watch White Diary: Chapter 13",
		"Watch White Diary: Chapter 14",
		"Watch White Diary: Chapter 15",
		"Watch White Diary: Chapter 16"
	};

	static_assert(PIECEOFDIARY_MENU_DESCRIPTIONS.size() == 58);

	std::array ANOTHERSTORY_MENU_DESCRIPTIONS = {
		"Complete first 『Flowers Falling in the Morning Mist』",
		"Complete first 『Witch Wandering in the Heat Haze』",
		"Complete first 『Another Dream Story』",
		"Start 『Souls Created by Witches』",
		"Start 『Another Dream Story』",
		"Start 『First Cooking Challenge』"
	};

	static_assert(ANOTHERSTORY_MENU_DESCRIPTIONS.size() == 6);

	std::array SYSMES_TEXT = {
		"ja",
		"サウンドの設定を行います",
		"サウンドの設定を初期設定に戻します",
		"ＢＧＭの音量を調整します",
		"ＢＧＭの音量を下げます",
		"ＢＧＭの音量を上げます",
		"ボイスの音量を調整します",
		"ボイスの音量を下げます",
		"ボイスの音量を上げます",
		"効果音の音量を調整します",
		"効果音の音量を下げます",
		"効果音の音量を上げます",
		"システムＳＥの音量を調整します",
		"システムＳＥの音量を下げます",
		"システムＳＥの音量を上げます",
		"ムービーの音量を調整します",
		"ムービーの音量を下げます",
		"ムービーの音量を上げます",
		"テキスト送り時にボイスを停止しません",
		"テキスト送り時にボイスを停止します",
		"ＢＧＭの音量を一定にします",
		"ボイス再生中にＢＧＭの音量を下げます",
		"BGMの音源を2chにします",
		"BGMの音源を5.1chにします",
		"ボイスの設定を行います",
		"ボイスの設定を初期設定に戻します",
		"システムボイスを変更します",
		"？？？のボイス出力を設定します",
		"鹿ヶ谷 憂緒のボイス出力を設定します",
		"烏丸 小太郎のボイス出力を設定します",
		"リトのボイス出力を設定します",
		"壬生 鍔姫のボイス出力を設定します",
		"風呂屋町 眠子のボイス出力を設定します",
		"九折坂 二人のボイス出力を設定します",
		"村雲 静春のボイス出力を設定します",
		"吉田 そあらのボイス出力を設定します",
		"黒谷 真弥のボイス出力を設定します",
		"七番 雛のボイス出力を設定します",
		"射場 久美子のボイス出力を設定します",
		"春日 真由美のボイス出力を設定します",
		"村雲 春霞のボイス出力を設定します",
		"アーデルハイトのボイス出力を設定します",
		"ルイのボイス出力を設定します",
		"諏訪 葵のボイス出力を設定します",
		"伏見 みおのボイス出力を設定します",
		"聖護院 百花のボイス出力を設定します",
		"久我 満琉のボイス出力を設定します",
		"花立 睦月のボイス出力を設定します",
		"アーリックのボイス出力を設定します",
		"アンデルのボイス出力を設定します",
		"シグマのボイス出力を設定します",
		"その他のボイス出力を設定します",
		"テキストの設定を行います",
		"テキストの設定を初期設定に戻します",
		"文字の表示速度を調整します",
		"文字の表示速度を遅くします",
		"文字の表示速度を速くします",
		"オートモードの速度を調整します",
		"オートモードの速度を遅くします",
		"オートモードの速度を速くします",
		"ウィンドウの透明度を変更します",
		"ウィンドウを薄くします",
		"ウィンドウを濃くします",
		"文字に縁取りを付けません",
		"文字に縁取りを付けます",
		"文字に影を付けません",
		"文字に影を付けます",
		"文字の色を固定します",
		"既読文の文字の色を変更します",
		"ウィンドウのデザインを変更します",
		"言語を変更します",
		"動作の設定を行います",
		"動作の設定を初期設定に戻します",
		"全ての文章をスキップ可能にします",
		"既読文のみスキップ可能にします",
		"選択肢でスキップを解除しません",
		"選択肢でスキップを解除します",
		"選択肢での自動セーブを設定します",
		"選択肢で自動セーブしません",
		"選択肢で自動セーブします",
		"シーンの頭での自動セーブを設定します",
		"シーンの頭で自動セーブしません",
		"シーンの頭で自動セーブします",
		"ボタンのヘルプテキストを表示しません",
		"ボタンのヘルプテキストを表示します",
		"コントローラーの振動機能をＯＦＦにします",
		"コントローラーの振動機能をＯＮにします",
		"システム設定を行います",
		"システム設定を初期設定に戻します",
		"ボタン設定を変更します",
		"Save game",
		"Load game",
		"Change game settings",
		"Save system settings",
		"Return to Title Menu",
		"Close the System menu",
		"エクストラメニュー画面に戻ります",
		"セーブできません",
		"ロードできません",
		"選択できません",
		"Jump to the previous scene or choice",
		"Jump to the next scene or choice",
		"Rewind while pressing",
		"Fast forward while pressing",
		"Turn on/off Auto Mode",
		"Do a quick save",
		"Do a quick load",
		"Play the voice",
		"バックログを開きます",
		"Save game in this slot?",
		"Load this save?",
		"Overwrite this save?",
		"コピーしますか？",
		"削除しますか？",
		"Saving game...",
		"Loading save...",
		"チェック中です",
		"セーブデータのチェックに失敗しました。^データが破損している可能性があります",
		"コピー中です",
		"削除中です",
		"セーブに失敗しました",
		"ロードに失敗しました",
		"セーブが終了しました",
		"ロードが終了しました",
		"セーブデータがありません",
		"セーブをキャンセルしますか？",
		"ロードをキャンセルしますか？",
		"セーブを続行しますか？",
		"ロードを続行しますか？",
		"システムデータをセーブしますか？",
		"システムデータをロードしますか？",
		"システムデータを上書きしますか？",
		"システムデータをセーブ中です",
		"システムデータをロード中です",
		"システムデータがありません",
		"システムデータのセーブに失敗しました",
		"システムデータのロードに失敗しました。^データが破損している可能性があります",
		"システムデータのセーブに成功しました",
		"システムデータのロードに成功しました",
		"ファイルが壊れています",
		"データが破損しているので、上書きします",
		"空き容量が不足しています",
		"フォーマットを実行しますか？",
		"Empty save",
		"セーブデータを作成します",
		"セーブデータのバージョンが異なります",
		"システムデータのバージョンが異なります",
		"ゲームを最初から開始します",
		"最新のセーブファイルでゲームを再開します",
		"Returning to Load menu",
		"環境設定を行います",
		"鑑賞モードに入ります",
		"ＣＧを鑑賞します",
		"音楽を鑑賞します",
		"ボイスを鑑賞します",
		"Returning to Title Menu",
		"エクストラメニュー画面に戻ります",
		"追加シナリオをプレイします",
		"キャンセルしますか？",
		"Return to Title Menu?",
		"エクストラメニュー画面に戻りますか？",
		"Do a Quick Load?",
		"Do a Quick Jump?",
		"Jump to the next scene/choice?",
		"Jump to the previous scene/choice?",
		"セーブをせずに終了してもよろしいですか？",
		"ボイスを消去しますか？",
		"クイックセーブしますか？",
		"エラーが発生しました",
		"The Borderline of Dusk",
		"Daybreak of Remnants Shadow",
		"Flowers Falling in the Morning Mist",
		"Witch Wandering in the Heat Haze",
		"dummy",
		"dummy"
	};

	static_assert(SYSMES_TEXT.size() == 175);
}