#include "stdafx.h"
#include "DList.h"

DList::DList(string name)
{	
	listName = name;
	phead = (DListNode*)malloc(sizeof(DListNode));
	init();
}

void DList::print_dlist()
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		cout << _data[p->index].name << endl;
	}
	printf("\n");
}

void DList::init()
{
	phead->llink = phead;
	phead->rlink = phead;
}

void DList::dinsert(DListNode* before,int data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	//strcpy((char*)newnode->data.name, data.name);//문자열 복사하는 명령어
	newnode->llink = before; // [기존]<-[새로운]
	newnode->rlink = before->rlink; // [새로운]->[기존]
	before->rlink->llink = newnode; //[기존]->[새로운]<-[기존오른쪽]
	before->rlink = newnode; // [기존]->새로운 노드
}

void DList::ddelete(DListNode* removed)
{
	if (removed == phead) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
