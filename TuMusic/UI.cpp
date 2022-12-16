
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

//�⺻ UI�Դϴ�. Return ���� ������ UI�� ��ȣ�Դϴ�.
//UI�� ��ȣ�� stdafx ����� �ۼ��Ǿ��ֽ��ϴ�.
int basicUI() {
	int select = 0;

	char key = 0;

	vector<string> UI_text;//UI ����Ʈ�� �̸��� �����մϴ�.
	
	UI_text.push_back("�뷡�˻�");
	UI_text.push_back("��ŷ����");
	UI_text.push_back("������");
	UI_text.push_back("������õ�ޱ�");
	UI_text.push_back("���Ǳ�� : ���Ƚ�������");
	UI_text.push_back("���Ǳ�� : �����ϸ����");

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
			cout << "�̿����ּż� �����մϴ�." << endl;
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
		cout << "esc ����" << endl;
		//cout << "select : " << select << endl;

		key = _getch();
		if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
			key = _getch(); //�ѹ��� �Է��� �޴´�.
		}
	}
}

