

#include"UI.h"

extern int UI_control;

void BaseUI(int i) {
	
	printf(" _____  _   _  _   _____  ___             _       \n");
	printf("|_   _|| | | || | / /|  \\/  |            (_)      \n");
	printf("  | |  | | | || |/ / | .  . | _   _  ___  _   ___ \n");
	printf("  | |  | | | ||    \\ | |\\/| || | | |/ __|| | / __|\n");
	printf("  | |  | |_| || |\\  \\| |  | || |_| |\\__ \\| || (__ \n");
	printf("  \\_/   \\___/ \\_| \\_/\\_|  |_/ \\____||___/|_| \\___|\n\n");
	printf("      메뉴를 선택하세요\n");
	printf("키보드 조작으로 선택이 가능합니다. \n");
	printf("+=============================+\n");
	printf("1.인기차트 순위 ");
	if (i == 1) {
		printf(" ㅁ");

	}
	printf("\n2.저시깽이      ");
	if (i == 2) {
		printf(" ㅁ");
	}
	printf("\n3.머시깽이      ");
	if (i == 3) {
		printf(" ㅁ");
	}
	printf("\n+=============================+\n");

}

void ChartUI_top()
{
	printf(" _____  _   _  _   _____  ___             _       \n");
	printf("|_   _|| | | || | / /|  \\/  |            (_)      \n");
	printf("  | |  | | | || |/ / | .  . | _   _  ___  _   ___ \n");
	printf("  | |  | | | ||    \\ | |\\/| || | | |/ __|| | / __|\n");
	printf("  | |  | |_| || |\\  \\| |  | || |_| |\\__ \\| || (__ \n");
	printf("  \\_/   \\___/ \\_| \\_/\\_|  |_/ \\____||___/|_| \\___|\n\n");
	printf("                인기차트 TOP 200 \n");
	printf("| __________________________________________________ |\n");
}

void ClearUI()
{
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 300 * 300, { 0, 0 }, &dw);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
