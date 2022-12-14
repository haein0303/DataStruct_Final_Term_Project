
#include "LinkedList.h"


DListNode* current;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist1(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == current) {
			printf("[ %s ] <= 재생중인 노래\n ", p->data.name);
			//std::cout << p->data.name << "<= 재생중인 노래" << std::endl;
			p->data.key++;
		}
		else
			printf("[ %s ] \n", p->data.name);
	}
	printf("\n");
}

void print_dlist2(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("[ %s ]\n ", p->data.name);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy((char*)newnode->data.name, data.name);//문자열 복사하는 명령어
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}