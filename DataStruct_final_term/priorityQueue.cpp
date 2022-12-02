#include "priorityQueue.h"
// ���� �Լ� 
HeapType* create() { 
	return (HeapType*)malloc(sizeof(HeapType));
} 
// �ʱ�ȭ �Լ� 
void init(HeapType* h) { 
	h->heap_size = 0;
}

void insertMaxHeap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ���� 
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { 
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	} 
	h->heap[i] = item; // ���ο� ��带 ���� 
}

element deleteMaxHeap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) { // ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵� 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	} h->heap[parent] = temp;
	return item;
}

