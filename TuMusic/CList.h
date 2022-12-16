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
	Node	org;	// ��� ��� (��� �����Ͱ� �ƴ�)

	CList(string name);

	// �ܼ� ���� ����Ʈ �ٽ� �˰���
	void insert_next(Node* prev, Node* n);
	Node* remove_next(Node* prev);

	// ����Ʈ�� �ֿ� �˰���
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

