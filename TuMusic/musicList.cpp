
#include "stdafx.h"
#include "priorityQueue.h"
#include "musicList.h"
#include "util.h"


void musicListmain(const vector<MusicData> &data) {
	priorityQueue qu(data.size()); //우선순위 큐를 만듭니다.

	cout << "음악 추천 알고리즘입니다." << endl;

	cout << "어느지역 음악을 선호하시나요?" << endl;
	cout << "0.US  1.UK  2.DE  3.FR  4.CA  5.AU  6.랭킹 기반 7.내 재생횟수기반" << endl;
	cout << "0~5 입력 :";
	int input;
	cin >> input;
	int i = 0;
	for (const MusicData& a : data) {
		qu.insertMaxHeap({i,calcRank(input,a) });
		//cout << "되는중" << input << " : " << a.name << " : " << calcRank(input, a) << endl;
		i++;
	}

	for (int i = 0; i < 10; ++i) {
		priortyData t = qu.deleteMaxHeap();
		cout << i << " : " << data[t.index].name << "  추천점수 : " << t.key << endl;
	}


	char key;
	key = _getch();
	if (key == -32) { //입력받은 값이 확장키 이면
		key = _getch(); //한번더 입력을 받는다.
	}
}