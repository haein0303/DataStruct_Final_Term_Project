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
	char key;
	if (input >= 0 && playList.size() > input) {//�̻��Ѱ� �Է��ϴ� ��ݵ� �־��
		cout << "  ========= ������ ========" << endl;
		cout << "  = " << playList[input].listName << " =  " << endl;
		cout << "  ========= LIST ========" << endl;
		v_index_list = playList[input].get_list();
			for(const int& a:v_index_list){
				cout << data[a].name << endl;
			}

		cout << endl;
		cout << "���ۼ��� 0:���ư��� 1:�뷡�߰� 2:����" << endl;
		int input2;
		cin >> input2;

		vector<MusicData>::iterator iter;
		MusicData tmp;
		int num;
		int i = 0;
		string input_name;
		ClearUI();
		switch (input2) {
		case 0:
			break;
		case 1:			
			fflush(stdin);
			cout << "�߰��� �뷡 �̸� �Է� : ";
			cin >> input_name;

			strcpy_s(tmp.name, sizeof(tmp.name), input_name.c_str());
			
			iter = find(data.begin(), data.end(), tmp);
			//cout << iter - data.begin()-1  << " " << iter - data.end() << " " << iter->name << endl;
			if (iter != data.begin()) {
				playList[input].insert(0, iter - data.begin()-1);
				cout << "���������� �߰��Ǿ����ϴ�" << endl;
			}
			else {
				cout << "�뷡�� �����ϴ�." << endl;
			}	

			key = _getch();
			if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
				key = _getch(); //�ѹ��� �Է��� �޴´�.
			}
			break;
		case 2:			
			cout << "������ �뷡 ��ȣ �Է� : ";
			
			for(const int& a:v_index_list){				
				cout << i++ << " : "<<data[a].name << endl;
			}
			cin >> num;		
			
			playList[input].Delete(num);
			key = _getch();
			if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
				key = _getch(); //�ѹ��� �Է��� �޴´�.
			}
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