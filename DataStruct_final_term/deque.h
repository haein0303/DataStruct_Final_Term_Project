#pragma once
#define MAX_QUEUE_SIZE 5
#include "stdafx.h"


typedef struct { // ≈• ≈∏¿‘
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;


void error(char*);

void init_deque(DequeType*);

int que_is_empty(DequeType*);

int is_full(DequeType*);

void deque_print(DequeType*);

void add_rear(DequeType*, element);

void add_front(DequeType*, element);

element delete_front(DequeType*);

element delete_rear(DequeType*);

element get_front(DequeType*);

element get_rear(DequeType*);