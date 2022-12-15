#pragma once


//typedef struct {
//	element heap[MAX_ELEMENT];
//	int heap_size;
//} HeapType;

struct priortyData {
	int index; //원본데이터의 인덱스
	int key;//비교할 값
};

class priorityQueue
{
public://원래이러면 안되지만 저는 이런거 좋아합니다 ㅎ.
	priortyData *heap;
	int heap_size;
	vector<MusicData> *_data;//데이터의 레퍼런스
	priorityQueue(int size); // 생성자
	void insertMaxHeap(priortyData item);
	priortyData deleteMaxHeap();
};

