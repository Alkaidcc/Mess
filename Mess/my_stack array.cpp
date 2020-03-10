#include<iostream>
#include<cstdlib>
#define MAXSIZE 10

typedef struct stack{
	int *data;//สýื้
	int top;
}Stack;

Stack* init_stack();
bool is_empty(Stack* s);
bool is_full (Stack* s);
void push (Stack* s,int value);
void pop (Stack* s);
int top (Stack* s);
void traverse (Stack* s);
int main(){
	Stack* s = init_stack();
	for(int i=1;i<=10;i++){
		push(s,i);
	}
	traverse(s);
	pop(s);
	pop(s);
	traverse(s);
	system("pause");
	return 0;
}

Stack* init_stack(){
	Stack* s;
	s->data = new int[MAXSIZE];
	s->top = -1;
	return s;
}

bool is_empty(Stack* s){
	if(s->top == -1)
		return true;
	else
		return false;
}

bool is_full(Stack* s){
	if(s->top == MAXSIZE-1)
		return true;
	else
		return false;
}

void push (Stack* s,int value){
	if(is_full(s))
		printf("The stack is full!\n");
	else{
		s->top++;
		s->data[s->top] = value;
	}
}

void pop (Stack* s){
	if(is_empty(s))
		printf("The stack is empty!\n");
	else
		s->top--;
}

int top (Stack* s){
	if(is_empty(s))
		printf("The stack is full!\n");
	else{
		return s->data[s->top];
	}
}

void traverse (Stack* s){
	if(is_empty(s))
		printf("The stack is empty!\n");
	else{
		for(int i=0;i<=s->top;i++)
			printf(" %d",s->data[i]);
		printf("\n");
	}
}