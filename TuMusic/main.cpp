//=============================================
//=============================================
//				READ ME
// 
// VS ver : 2022(v143)
// C++ ver : c++20
// C ver : c17
//
//=============================================
//			메인 아이디어
// Vector는 동적으로 늘어날 뿐 [배열과 동일]합니다
// 배열은 가장 적은 메모리를 사용하면서 랜덤한 위치에 접근이 가능합니다.
// 
// _m_data는 데이터베이스와 유사한 기능을 한다고 생각하시면 됩니다.
// 우리는 이 데이터베이스가 가지고 있는 데이터의 인덱스만 알면은 모든 데이터를 가지고 있지 않고도
// 원하는 값을 언제나 불러다가 쓸 수 있습니다.
// 
// 즉
// 우리가 다루는 것은 데이터의 인덱스만을 다루고
// 그 인덱스를 통해서 그때그때 데이터를 가져다가 씁니다. 
//
//=============================================



#include "stdafx.h"
#include "UI.h"
#include "fileLoader.h"
#include "Show.h"
#include "util.h"

//C++ 17부터 return을 안쓰는것이 표준 문법이 되었습니다.
//cpp파일로 생성하신다면, 굳이 안써도 별도의 에러가 나지 않습니다.

int main() {
	int scene_select = 0;
	vector<MusicData> _m_data; //vector는 동적큐와 유사한 자료구조입니다. 

	//파일 로딩
	if (!read_data("chart2000.csv", _m_data)) {//파일명과 입력받을 저장공간을 레퍼런스를 인자로 넣습니다.
		cout << "프로그램을 종료합니다." << endl;
		return 0;
	}

	//scene_select = -1;
	while (scene_select != -1) {
		scene_select = basicUI();
		
		switch (scene_select) {
		case UI::UI_find:
			show_search(_m_data);
			break;
		case UI::UI_rank:
			showrank(_m_data);
			break;
		case UI::UI_Mylist:

			break;
		}
	}

	

}