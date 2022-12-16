#pragma once

#define ELEMENT	string

struct Node {
	string data;
	struct Node* prev;
	struct Node* link;
};

class CList
{
public:
	Node* phead;
	vector<MusicData> _data;
	string listName;
	Node	org;	// 헤드 노드 (헤드 포인터가 아님)

	CList(string name);

	// 단순 연결 리스트 핵심 알고리즘
	void insert_next(Node* prev, Node* n);
	Node* remove_next(Node* prev);

	// 리스트의 주요 알고리즘
	void init_list();
	Node* get_head();
	int Is_empty();
	//CList(string name);
	Node* get_elem(int pos);
	Node* find(ELEMENT val);
	int size();
	void replace(int pos, ELEMENT val);
	void insert(int pos, ELEMENT val);
	void Delete(int pos);
	void clear_list();
	void print_list(char* msg);
	


};

