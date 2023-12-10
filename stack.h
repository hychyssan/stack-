#define _CRT_SECURE_NO_WARNINGS
#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdbool.h>

typedef int Item;	//自定义栈内容

typedef struct node {
	Item item;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
}Stack;


void InitializeStack(Stack* ps);		//initialize a stack

bool StackIsFull(Stack* ps);

bool StackIsEmpty(Stack* ps);

int StackItemCount(Stack* ps);

bool StackPush(Item item,Stack* ps);		//enter a element into the stack

bool StackPop(Stack* ps);		//pop a element out of the stack

bool EmptyTheStack(Stack* ps);

#endif