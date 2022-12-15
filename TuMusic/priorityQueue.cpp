#include "stdafx.h"
#include "util.h"
#include "priorityQueue.h"

priorityQueue::priorityQueue(int size)
{
	heap = (priortyData*)malloc(sizeof(priortyData) * size);
	heap_size = 0;	
}

void priorityQueue::insertMaxHeap(priortyData item)
{
	int i;
	i = ++heap_size;
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;

}

priortyData priorityQueue::deleteMaxHeap()
{
	int parent, child;
	priortyData item, temp;
	item = heap[1];
	temp = heap[heap_size--];
	parent = 1;
	child = 2;
	while (child <= heap_size) { // 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < heap_size) && (heap[child].key) < heap[child + 1].key) child++;
		if (temp.key >= heap[child].key) break;
		// 한 단계 아래로 이동 
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	} 
	heap[parent] = temp;
	return item;

}
