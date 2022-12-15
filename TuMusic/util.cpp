#include "stdafx.h"
#include "util.h"

//가중치를 연산해주는 함수입니다.
//구조체와 가중치의 요소를 입력받습니다.
int calcRank(int sort, const MusicData& data) {
	int calc = 0;

	if (sort == S_VIEWS) {
		calc += data.view_count;
		return calc;
	}
	for (int i = 0; i < COUNTRY_COUNT; ++i) {

		if (data.rank[i] > 0 && data.rank[i]<101) {
			if (i == sort) {
				calc += (100 - data.rank[i]) * 10;
			}
			else {
				calc += (100 - data.rank[i]);
			}
		}				
	}
	if (sort == S_RANK) {
		return calc;
	}

	//기본추천에서는 View의 가중치는 이정도로
	calc += data.view_count*100;

	return calc;
}
