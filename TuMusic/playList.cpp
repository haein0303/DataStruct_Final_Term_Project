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

	if (input >= 0 && playList.size() < input) {//이상한거 입력하는 양반들 있어요
		cout << "  ========= 재생목록 ========" << endl;
		cout << "  = " << playList[input].listName << " =  " << endl;
		cout << "  ========= LIST ========" << endl;
		//playList[input].print_dlist();

		cout << endl;
		cout << "동작선택 1:노래추가  2:재생  3:삭제" << endl;
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
			cout << "값이 잘못입력되었습니다";
			break;
		}

	}
	else {
		cout << "값이 잘못입력되었습니다";
		return;
	}
}

