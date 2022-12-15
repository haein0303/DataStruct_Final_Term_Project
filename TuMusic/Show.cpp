#include "stdafx.h"
#include "Show.h"
#include "util.h"


void show_search(vector<MusicData>& data) {
	//set
	//set은 밸런스 이진 트리를 기반으로 하는 콘테이너 입니다.

	set < MusicData> _data;
	int _loadingBar = 0;
	int _loadingMax = data.size();
	for (const MusicData& a : data) {
		int per = (int)(((float)_loadingBar / (float)_loadingMax) * 100);
		cout << "\r로딩중 " << per << "% [";
		for (int i = 0; i < 20; ++i) {
			if ((i * 5) < per) {
				cout << "#";
			}
			else {
				cout << "-";
			}
		}
		cout << "]";
		++_loadingBar;
		_data.insert(a);
	}
	MusicData tmp;

	string line;
	cout << "\r";
	cout << "목록에 노래가 있는지 검색합니다.            " << endl;
	cout << "원하시는 노래를 입력해주세요 : ";

	getline(cin, line);

	strcpy_s(tmp.name, line.c_str());
	cout << endl;
	auto iter = _data.find(tmp);
	if (iter != _data.end()) {
		cout << "[ " << line << " ] 의 검색결과 입니다\n" << endl;
		cout << "제목 : " << iter->name << endl;
		cout << "가수 : " << iter->singer << endl;
		cout << "수익 : " << iter->evenue << endl;
		cout << "===== 지역별 최고 순위=====" << endl;
		cout << "US : ";
		if (iter->rank[US] != 0) {
			 cout << iter->rank[US];
		}
		else {
			cout << " -";
		}
		cout << " || UK : ";
		if (iter->rank[UK] != 0) {
			cout << iter->rank[UK];
		}
		else {
			cout << " -";
		}
	}
	else {
		cout << "찾는 데이터가 없습니다" << endl;
	}
	char key;
	cout << "\n\nTo Lobby << Press Any Key" << endl;
	key = _getch();
	if (key == -32) { //입력받은 값이 확장키 이면
		key = _getch(); //한번더 입력을 받는다.
	}
}



void showrank(vector<MusicData>& data) {
	int now = 0;
	int view_size = 10;

	//복사합시다.
	vector<MusicData> _data;
	_data.resize(data.size());
	copy(data.begin(),data.end(),_data.begin());

	//정렬할껀데 정렬 기준은 가중치를 기반으로 합니다.
	sort(_data.begin(), _data.end(), [](const MusicData& a, const MusicData& b) {		
			return calcRank(Sorting::S_RANK, a) > calcRank(Sorting::S_RANK, b);
		});

	for (int i = now; i < (now + view_size); ++i) {
		cout << i << " : " <<_data[i].name << " 총점 : " << calcRank(Sorting::S_RANK, _data[i]) << endl;
		/*for (int j = 0; j < COUNTRY_COUNT; ++j) {
			cout << _data[i].rank[j] << " ";
		}cout << endl;*/
	}

	char key;
	cout << "\n\nTo Lobby << Press Any Key" << endl;
	key = _getch();
	if (key == -32) { //입력받은 값이 확장키 이면
		key = _getch(); //한번더 입력을 받는다.
	}
}