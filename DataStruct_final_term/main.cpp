
#pragma _CRT_SECURE_NO_WARNINGS


#include "stdafx.h"
#include "UI.h"


using namespace std;

int main() {
	
	int i = 1;
	char key = 0;//�����ݷ��� �������� �ᵵ ������ �����
	while (1) {
		BaseUI(i);
		key = _getch();
		if (key == 0xE0 || key == 0)   //�Է¹��� ���� Ȯ��Ű �̸�
			key = _getch();            //�ѹ��� �Է��� �޴´�.
		switch (key)
		{
		case KEY_UP:
			i = (i + 1) % 3 + 1;
			break;
		case KEY_DOWN:			
			i = i % 3 + 1;
			break;
		default:
			break;
		}

	}

}

