

#include"UI.h"

extern int UI_control;

void BaseUI(int i) {
	
	printf(" _____  _   _  _   _____  ___             _       \n");
	printf("|_   _|| | | || | / /|  \\/  |            (_)      \n");
	printf("  | |  | | | || |/ / | .  . | _   _  ___  _   ___ \n");
	printf("  | |  | | | ||    \\ | |\\/| || | | |/ __|| | / __|\n");
	printf("  | |  | |_| || |\\  \\| |  | || |_| |\\__ \\| || (__ \n");
	printf("  \\_/   \\___/ \\_| \\_/\\_|  |_/ \\____||___/|_| \\___|\n\n");
	printf("      �޴��� �����ϼ���\n");
	printf("Ű���� �������� ������ �����մϴ�. \n");
	printf("+=============================+\n");
	printf("1.�α���Ʈ ���� ");
	if (i == 1) {
		printf(" ��");

	}
	printf("\n2.���ò���      ");
	if (i == 2) {
		printf(" ��");
	}
	printf("\n3.�ӽò���      ");
	if (i == 3) {
		printf(" ��");
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
	printf("                �α���Ʈ TOP 200 \n");
	printf("| __________________________________________________ |\n");
}

void ClearUI()
{
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 300 * 300, { 0, 0 }, &dw);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
