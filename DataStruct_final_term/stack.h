#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s);

int qis_empty(StackType* s);

int is_full(StackType* s);

void push(StackType* s, element item);

element pop(StackType* s);

element peek(StackType* s);


