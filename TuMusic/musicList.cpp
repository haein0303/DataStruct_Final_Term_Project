
#include "stdafx.h"
#include "priorityQueue.h"
#include "musicList.h"
#include "util.h"


void musicListmain(const vector<MusicData> &data) {
	priorityQueue qu(data.size()); //�켱���� ť�� ����ϴ�.

	cout << "���� ��õ �˰����Դϴ�." << endl;

	cout << "������� ������ ��ȣ�Ͻó���?" << endl;
	cout << "0.US  1.UK  2.DE  3.FR  4.CA  5.AU  6.��ŷ ��� 7.�� ���Ƚ�����" << endl;
	cout << "0~5 �Է� :";
	int input;
	cin >> input;
	int i = 0;
	for (const MusicData& a : data) {
		qu.insertMaxHeap({i,calcRank(input,a) });
		//cout << "�Ǵ���" << input << " : " << a.name << " : " << calcRank(input, a) << endl;
		i++;
	}

	for (int i = 0; i < 10; ++i) {
		priortyData t = qu.deleteMaxHeap();
		cout << i << " : " << data[t.index].name << "  ��õ���� : " << t.key << endl;
	}


	char key;
	key = _getch();
	if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
		key = _getch(); //�ѹ��� �Է��� �޴´�.
	}
}