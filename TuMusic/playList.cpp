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
		playList.push_back(tmp);
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
	vector<int> v_index_list;
	if (input >= 0 && playList.size() > input) {//�̻��Ѱ� �Է��ϴ� ��ݵ� �־��
		cout << "  ========= ������ ========" << endl;
		cout << "  = " << playList[input].listName << " =  " << endl;
		cout << "  ========= LIST ========" << endl;
		v_index_list = playList[input].get_list();
			for(const int& a:v_index_list){
				cout << data[a].name << endl;
			}

		cout << endl;
		cout << "���ۼ��� 1:�뷡�߰� 2:����" << endl;
		int input2;
		cin >> input2;

		vector<MusicData>::iterator iter;
		MusicData tmp;
		int num;
		int i = 0;
		switch (input2) {
		case 1:
			ClearUI();
			
			char input_name[128];
			cout << "�߰��� �뷡 �̸� �Է� : ";
			cin >> input_name;

			strcpy_s(tmp.name, sizeof(tmp.name), input_name);
			
			iter = find(data.begin(), data.end(), tmp);
			if (iter != data.end()) {
				playList[input].insert(0, iter - data.begin());
			}
			
			break;
		case 2:
			
			cout << "������ �뷡 ��ȣ �Է� : ";
			
			for(const int& a:v_index_list){				
				cout << i++ << " : "<<data[a].name << endl;
			}
			cin >> num;		
			
			playList[input].Delete(num);

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

	char key;
	key = _getch();
	if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
		key = _getch(); //�ѹ��� �Է��� �޴´�.
	}
}

void make_dummy_playList(vector<CList>& playList, vector<MusicData>& data) {
	CList tmp("�����ϸ鼭 ��� ���� �뷡");
	for (int i = 0; i < 10; ++i) {
		tmp.insert(0, rand()%100);
	}	
	playList.push_back(tmp);

	CList tmp2("�����ϸ鼭 ��� ���� �뷡");
	for (int i = 0; i < 10; ++i) {
		tmp2.insert(0, rand() % 100);
	}
	playList.push_back(tmp2);
}