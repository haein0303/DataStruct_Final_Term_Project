#include "stdafx.h"

#include "CList.h"
#include "UI.h"
#include "playList.h"

void play_list_main(vector<CList> &playList,vector<MusicData> &data) {
	if (playList.size() == 0) {//플레이 리스트가 없는 상태
		cout << "플레이리스트가 없습니다. 플레이리스트를 생성합니다" << endl;
		cout << "플레이리스트 명을 입력하세요 : ";
		string play_list_name_input;
		getline(cin, play_list_name_input);
		CList tmp(play_list_name_input);
		playList.push_back(tmp);
	}	

	// 플레이 리스트 목록 표시
	int i = 0;
	for (const CList& a : playList) {
		cout << i++ << " : " << a.listName << endl;
	}

	// 플레이 리스트 번호 입력
	cout << "0 ~" << playList.size()-1 << " 입력 :";
	int input;
	cin >> input;
	vector<int> v_index_list;
	if (input >= 0 && playList.size() > input) {//이상한거 입력하는 양반들 있어요
		cout << "  ========= 재생목록 ========" << endl;
		cout << "  = " << playList[input].listName << " =  " << endl;
		cout << "  ========= LIST ========" << endl;
		v_index_list = playList[input].get_list();
			for(const int& a:v_index_list){
				cout << data[a].name << endl;
			}

		cout << endl;
		cout << "동작선택 1:노래추가 2:삭제" << endl;
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
			cout << "추가할 노래 이름 입력 : ";
			cin >> input_name;

			strcpy_s(tmp.name, sizeof(tmp.name), input_name);
			
			iter = find(data.begin(), data.end(), tmp);
			if (iter != data.end()) {
				playList[input].insert(0, iter - data.begin());
			}
			
			break;
		case 2:
			
			cout << "삭제할 노래 번호 입력 : ";
			
			for(const int& a:v_index_list){				
				cout << i++ << " : "<<data[a].name << endl;
			}
			cin >> num;		
			
			playList[input].Delete(num);

			break;
		default:
			cout << "값이 잘못입력되었습니다";
			break;
		}

	}
	else {
		cout << "값이 잘못입력되었습니다";
		return;
	}

	char key;
	key = _getch();
	if (key == -32) { //입력받은 값이 확장키 이면
		key = _getch(); //한번더 입력을 받는다.
	}
}

void make_dummy_playList(vector<CList>& playList, vector<MusicData>& data) {
	CList tmp("운전하면서 듣기 좋은 노래");
	for (int i = 0; i < 10; ++i) {
		tmp.insert(0, rand()%100);
	}	
	playList.push_back(tmp);

	CList tmp2("공부하면서 듣기 좋은 노래");
	for (int i = 0; i < 10; ++i) {
		tmp2.insert(0, rand() % 100);
	}
	playList.push_back(tmp2);
}