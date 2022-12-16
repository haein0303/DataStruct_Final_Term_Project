#include "stdafx.h"
#include "Show.h"
#include "util.h"
#include "BST.h"


void show_search(vector<MusicData>& data) {
	//set
	//set�� �뷱�� ���� Ʈ���� ������� �ϴ� �����̳� �Դϴ�.
	//set�� ����� ����
	// set�� �ߺ��� �����͸� ������ �ʽ��ϴ�.
	// ������ �����ε��� ���ؼ� �̸��� �������� �ߺ��� ������ �����Ͽ����ϴ�.
	// �̸��� �������� �����͸� ������ �����ϱ� ������
	// �̸��� ���ؼ� �˻��ϴ� �ӵ��� logŸ���� ������ �� �ֽ��ϴ�.
	// 

	set <MusicData> _data;
	int _loadingBar = 0;
	int _loadingMax = data.size();
	for (const MusicData& a : data) {
		int per = (int)(((float)_loadingBar / (float)_loadingMax) * 100);
		cout << "\r�ε��� " << per << "% [";
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
	cout << "��Ͽ� �뷡�� �ִ��� �˻��մϴ�.            " << endl;
	cout << "���Ͻô� �뷡�� �Է����ּ��� : ";

	getline(cin, line);

	strcpy_s(tmp.name, line.c_str());
	cout << endl;
	auto iter = _data.find(tmp);
	if (iter != _data.end()) {
		cout << "[ " << line << " ] �� �˻���� �Դϴ�\n" << endl;
		cout << "���� : " << iter->name << endl;
		cout << "���� : " << iter->singer << endl;		
	}
	else {
		cout << "ã�� �����Ͱ� �����ϴ�" << endl;
	}
	char key;
	cout << "\n\nTo Lobby << Press Any Key" << endl;
	key = _getch();
	if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
		key = _getch(); //�ѹ��� �Է��� �޴´�.
	}
}

void show_seach_bst(vector<MusicData>& data) {
	BST bst;
	int i = 0;
	for (const auto& a : data) {
		bst.insert_BST(a.name);
	}
	cout << "��Ͽ� �뷡�� �ִ��� �˻��մϴ�." << endl;
	cout << "���Ͻô� �뷡�� �Է����ּ��� : ";
	string input;
	getline(cin, input);

	if (bst.search_BST(input)) {
		cout << "[ " << input << " ] �� �ֽ��ϴ�.\n" << endl;
	}
	else {
		cout << "[ " << input << " ] �� �����ϴ�.\n" << endl;
	}	


	char key;
	cout << "\n\nTo Lobby << Press Any Key" << endl;
	key = _getch();
	if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
		key = _getch(); //�ѹ��� �Է��� �޴´�.
	}
}



void showrank(vector<MusicData>& data) {
	int now = 0;
	int view_size = 10;

	//�����սô�.
	vector<MusicData> _data;
	_data.resize(data.size());
	copy(data.begin(),data.end(),_data.begin());

	//�����Ҳ��� ���� ������ ����ġ�� ������� �մϴ�.
	sort(_data.begin(), _data.end(), [](const MusicData& a, const MusicData& b) {		
			return calcRank(Sorting::S_RANK, a) > calcRank(Sorting::S_RANK, b);
		});

	for (int i = now; i < (now + view_size); ++i) {
		cout << i << " : " <<_data[i].name << " ���� : " << calcRank(Sorting::S_RANK, _data[i]) << endl;
		/*for (int j = 0; j < COUNTRY_COUNT; ++j) {
			cout << _data[i].rank[j] << " ";
		}cout << endl;*/
	}

	char key;
	cout << "\n\nTo Lobby << Press Any Key" << endl;
	key = _getch();
	if (key == -32) { //�Է¹��� ���� Ȯ��Ű �̸�
		key = _getch(); //�ѹ��� �Է��� �޴´�.
	}
}