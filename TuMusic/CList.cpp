#include "stdafx.h"
#include "CList.h"


//---------------------------------------------------------------------
// 단순 연결 리스트 핵심 알고리즘
//---------------------------------------------------------------------

void CList::insert_next(Node* prev, Node* n)
{
	if (n != NULL) {
		n->link = prev->link;
		prev->link = n;
	}
}

Node* CList::remove_next(Node* prev)
{
	Node* removed = prev->link;
	if (removed != NULL)
		prev->link = removed->link;
	return removed;
}

//---------------------------------------------------------------------
// 리스트의 주요 알고리즘
//---------------------------------------------------------------------
void CList::init_list() { org.link = NULL; }
Node* CList::get_head() { return org.link; }
int CList::Is_empty()	 { return get_head() == NULL; }

//CList::CList(string name)
//{
//	listName = name;
//	phead = (Node*)malloc(sizeof(Node));
//	init_list();
//}

CList::CList(string name)
{
	listName = name;
	phead = (Node*)malloc(sizeof(Node));
	init_list();
}

Node* CList::get_elem(int pos)
{
	Node* n = &org;
	int i = -1;
	for (i = -1; i < pos; i++, n = n->link)
		if (n == NULL) break;
	return n;
}

Node* CList::find(ELEMENT val)
{
	Node* p;
	for (p = get_head(); p != NULL; p = p->link)
		if (p->data == val) return p;
	return NULL;
}

int CList::size()
{
	Node* p;
	int count = 0;
	for (p = get_head(); p != NULL; p = p->link)
		count++;
	return count;
}
void CList::replace(int pos, ELEMENT val)
{
	Node* node = get_elem(pos);
	if (node != NULL)
		node->data = val;
}

void CList::insert(int pos, ELEMENT val)
{
	Node* new_node;
	Node* prev = get_elem(pos - 1);
	if (prev != NULL) {
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = val;
		new_node->link = NULL;
		insert_next(prev, new_node);
	}
}
void CList::Delete(int pos)
{
	Node* prev = get_elem(pos - 1);
	Node* removed = remove_next(prev);
	free(removed);
}

void CList::clear_list()
{
	while (Is_empty() == 0)
		Delete(0);
}


//---------------------------------------------------------------------
void CList::print_list(char* msg)
{
	Node* p;
	printf("%s[%2d]: ", msg, size());
	for (p = get_head(); p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}

