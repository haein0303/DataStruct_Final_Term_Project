#pragma once
#include "stdafx.h"

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void print_dlist1(DListNode* phead);

void print_dlist2(DListNode* phead);

void init(DListNode* phead);

void dinsert(DListNode* before, element data);

void ddelete(DListNode* head, DListNode* removed);
