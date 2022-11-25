
#pragma _CRT_SECURE_NO_WARNINGS


#include "stdafx.h"
#include "UI.h"


using namespace std;

int main() {
	
	int i = 1;
	char key = 0;//세미콜론은 여러개를 써도 문제가 없어요
	while (1) {
		BaseUI(i);
		key = _getch();
		if (key == 0xE0 || key == 0)   //입력받은 값이 확장키 이면
			key = _getch();            //한번더 입력을 받는다.
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

