#pragma once


//typedef struct {
//	element heap[MAX_ELEMENT];
//	int heap_size;
//} HeapType;

struct priortyData {
	int index; //������������ �ε���
	int key;//���� ��
};

class priorityQueue
{
public://�����̷��� �ȵ����� ���� �̷��� �����մϴ� ��.
	priortyData *heap;
	int heap_size;
	vector<MusicData> *_data;//�������� ���۷���
	priorityQueue(int size); // ������
	void insertMaxHeap(priortyData item);
	priortyData deleteMaxHeap();
};

