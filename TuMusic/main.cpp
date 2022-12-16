//=============================================
//=============================================
//				READ ME
// 
// VS ver : 2022(v143)
// C++ ver : c++20
// C ver : c17
//
//=============================================
//			���� ���̵��
// Vector�� �������� �þ �� [�迭�� ����]�մϴ�
// �迭�� ���� ���� �޸𸮸� ����ϸ鼭 ������ ��ġ�� ������ �����մϴ�.
// 
// _m_data�� �����ͺ��̽��� ������ ����� �Ѵٰ� �����Ͻø� �˴ϴ�.
// �츮�� �� �����ͺ��̽��� ������ �ִ� �������� �ε����� �˸��� ��� �����͸� ������ ���� �ʰ�
// ���ϴ� ���� ������ �ҷ��ٰ� �� �� �ֽ��ϴ�.
// 
// ��
// �츮�� �ٷ�� ���� �������� �ε������� �ٷ��
// �� �ε����� ���ؼ� �׶��׶� �����͸� �����ٰ� ���ϴ�. 
// 
// ���� ��� �κ��� �׷��� ���� ��������, ���� ���������� �����صΰ� Ȱ���� �κе鸸 �׷��� ���̴ϴ�
// ���� �˻��̳�, ���İ����� �Ҷ��� �ӽ÷� �޸𸮸� �Ҵ� �޾Ƽ� ���� ������
// ���� ������ ������ ���� ��ư� �����͸� Ÿ�� ���� ���귮�� �ø� �ʿ�� ����.
//
//=============================================



#include "stdafx.h"
#include "UI.h"
#include "fileLoader.h"
#include "Show.h"
#include "util.h"
#include "musicList.h"
#include "CList.h"
#include "playList.h"

int main() {
	int scene_select = 0;
	vector<MusicData> _m_data; //vector�� ����ť�� ������ �ڷᱸ���Դϴ�. 
	vector<CList> _playList; //�������Դϴ�.


	//���� �ε�
	if (!read_data("chart2000.csv", _m_data)) {//���ϸ�� �Է¹��� ��������� ���۷����� ���ڷ� �ֽ��ϴ�.
		cout << "���α׷��� �����մϴ�." << endl;
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
			play_list_main(_playList,_m_data);
			break;
		case UI::UI_recommend:
			musicListmain(_m_data);
			break;
		case UI::UI_makeViewsCount:
			makeVeiwCounts(_m_data);
			break;
		}
	}
	
}