
#include "stdafx.h"
#include "UI.h"
#include "util.h"

void ChartUI_top(){
	printf(" _____  _   _  _   _____  ___             _       \n");
	printf("|_   _|| | | || | / /|  \\/  |            (_)      \n");
	printf("  | |  | | | || |/ / | .  . | _   _  ___  _   ___ \n");
	printf("  | |  | | | ||    \\ | |\\/| || | | |/ __|| | / __|\n");
	printf("  | |  | |_| || |\\  \\| |  | || |_| |\\__ \\| || (__ \n");
	printf("  \\_/   \\___/ \\_| \\_/\\_|  |_/ \\____||___/|_| \\___|\n\n");

	printf("| __________________________________________________ |\n");

}

void ClearUI(){
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 300 * 300, { 0, 0 }, &dw);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//기본 UI입니다. Return 값은 선택한 UI의 번호입니다.
//UI의 번호는 stdafx 헤더에 작성되어있습니다.
int basicUI() {
	int select = 0;

	char key = 0;

	vector<string> UI_text;//UI 리스트의 이름을 저장합니다.
	
	UI_text.push_back("노래검색");
	UI_text.push_back("랭킹보기");
	UI_text.push_back("재생목록");
	UI_text.push_back("음악추천받기");
	UI_text.push_back("편의기능 : 재생횟수만들기");
	UI_text.push_back("편의기능 : 재생목록만들기");

	while (1) {
		ClearUI();
		ChartUI_top();
		

		switch (key) {
		case KEY_UP:
			select = (UI_text.size() + select - 1) % UI_text.size();
			break;
		case KEY_DOWN:
			select = (select + 1) % UI_text.size();
			break;
		case KEY_ENTER:
			return select;
			break;
		case KEY_ESC:
			cout << "이용해주셔서 감사합니다." << endl;
			return -1;
			break;
		}
		for (int i = 0; i < UI_text.size(); ++i) {
			printf("[");
			if (i == select) {
				printf("v");
			}
			else {
				printf(" ");
			}
			cout << "]" << UI_text[i] << endl;
		}
		cout << "esc 종료" << endl;
		//cout << "select : " << select << endl;

		key = _getch();
		if (key == -32) { //입력받은 값이 확장키 이면
			key = _getch(); //한번더 입력을 받는다.
		}
	}
}

