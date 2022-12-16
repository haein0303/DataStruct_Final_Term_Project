#pragma once


struct DListNode {
	int index;
	struct DListNode* llink;
	struct DListNode* rlink;
};

class DList
{
public:
	DListNode* phead;
	vector<MusicData> _data;
	string listName;//재생목록 이름

	//생성자
	
	DList(string name);

	void print_dlist();

	void init();

	void dinsert(DListNode* before,int data);

	void ddelete( DListNode* removed);
};

