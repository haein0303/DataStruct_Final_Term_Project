#include "stdafx.h"
#include "util.h"

//����ġ�� �������ִ� �Լ��Դϴ�.
//����ü�� ����ġ�� ��Ҹ� �Է¹޽��ϴ�.
int calcRank(int sort, const MusicData& data) {
	int calc = 0;

	if (sort == S_VIEWS) {
		calc += data.view_count;
		return calc;
	}
	for (int i = 0; i < COUNTRY_COUNT; ++i) {

		if (data.rank[i] > 0 && data.rank[i]<101) {
			if (i == sort) {
				calc += (100 - data.rank[i]) * 20;
			}
			else {
				calc += (100 - data.rank[i]);
			}
		}				
	}
	if (sort == S_RANK) {
		return calc;
	}

	//�⺻��õ������ View�� ����ġ�� ��������
	calc += data.view_count*10;

	return calc;
}

void makeVeiwCounts(vector<MusicData>& data)
{
	for (MusicData &a : data) {
		a.view_count = rand() % 10000;
	}

	cout << "������ ������Ʈ �Ϸ�" << endl;

	char key;
	key = _getch();
	if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
		key = _getch(); //�ѹ��� �Է��� �޴´�.
	}
}


