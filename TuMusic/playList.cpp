#include "stdafx.h"

#include "CList.h"
#include "UI.h"
#include "playList.h"

void play_list_main(vector<CList> &playList,vector<MusicData> &data) {
	if (playList.size() == 0) {//�÷��� ����Ʈ�� ���� ����
		cout << "�÷��̸���Ʈ�� �����ϴ�. �÷��̸���Ʈ�� �����մϴ�" << endl;
		cout << "�÷��̸���Ʈ ���� �Է��ϼ��� : ";
		string play_list_name_input;
		getline(cin, play_list_name_input);
		CList tmp(play_list_name_input);
	}

	

	// �÷��� ����Ʈ ��� ǥ��
	int i = 0;
	for (const CList& a : playList) {
		cout << i++ << " : " << a.listName << endl;
	}

	// �÷��� ����Ʈ ��ȣ �Է�
	cout << "0 ~" << playList.size()-1 << " �Է� :";
	int input;
	cin >> input;

	if (input >= 0 && playList.size() < input) {//�̻��Ѱ� �Է��ϴ� ��ݵ� �־��
		cout << "  ========= ������ ========" << endl;
		cout << "  = " << playList[input].listName << " =  " << endl;
		cout << "  ========= LIST ========" << endl;
		//playList[input].print_dlist();

		cout << endl;
		cout << "���ۼ��� 1:�뷡�߰�  2:���  3:����" << endl;
		cin >> input;

		vector<MusicData>::iterator iter;
		MusicData tmp;

		switch (input) {
		case 1:
			ClearUI();
			
			char input_name[128];
			cin >> input_name;			
			iter = find(data.begin(), data.end(), tmp);
			if (iter != data.end()) {
				
			}
			
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "���� �߸��ԷµǾ����ϴ�";
			break;
		}

	}
	else {
		cout << "���� �߸��ԷµǾ����ϴ�";
		return;
	}
}

