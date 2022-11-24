

#include"UI.h"

extern int UI_control;

void BaseUI(int i) {
	ClearUI();
	printf("+=============================+\n");
	printf("      메뉴를 선택하세요\n");
	printf("키보드 조작으로 선택이 가능합니다. \n");
	printf("+=============================+\n");
	printf("1.모시깽이");
	if (i == 1) {
		printf(" ㅁ");
	}
	printf("\n2.저시깽이");
	if (i == 2) {
		printf(" ㅁ");
	}
	printf("\n3.머시깽이");
	if (i == 3) {
		printf(" ㅁ");
	}
	printf("\n+=============================+\n");

}

void ClearUI()
{
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 300 * 300, { 0, 0 }, &dw);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
