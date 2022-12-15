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
	//strcpy((char*)newnode->data.name, data.name);//���ڿ� �����ϴ� ��ɾ�
	newnode->llink = before; // [����]<-[���ο�]
	newnode->rlink = before->rlink; // [���ο�]->[����]
	before->rlink->llink = newnode; //[����]->[���ο�]<-[����������]
	before->rlink = newnode; // [����]->���ο� ���
}

void DList::ddelete(DListNode* removed)
{
	if (removed == phead) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
