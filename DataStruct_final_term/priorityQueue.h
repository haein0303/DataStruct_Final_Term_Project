#pragma once
#include "stdafx.h"

#define MAX_ELEMENT 400 


typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create();
void init(HeapType* h);

void insertMaxHeap(HeapType* h, element item);

element deleteMaxHeap(HeapType* h);