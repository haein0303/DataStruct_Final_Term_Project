

#include"UI.h"

extern int UI_control;

void BaseUI(int i) {
	ClearUI();
	printf("+=============================+\n");
	printf("      �޴��� �����ϼ���\n");
	printf("Ű���� �������� ������ �����մϴ�. \n");
	printf("+=============================+\n");
	printf("1.��ò���");
	if (i == 1) {
		printf(" ��");
	}
	printf("\n2.���ò���");
	if (i == 2) {
		printf(" ��");
	}
	printf("\n3.�ӽò���");
	if (i == 3) {
		printf(" ��");
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
