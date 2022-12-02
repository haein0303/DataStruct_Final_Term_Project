#include "stack.h"







void init_stack(StackType *s) {

	s->top = -1;
}

int qis_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {

	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러 \n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (qis_empty(s)) {
		fprintf(stderr, "스팩 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (qis_empty(s)) {
		fprintf(stderr, "스팩 포화 에러\n");
			exit(1);
	}
	else return s->data[s->top];
}


