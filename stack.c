#define _CRT_SECURE_NO_WARNINGS

/*
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

bool StackPush(Item item, Stack* ps);		//enter a element into the stack

bool StackPop(Item item, Stack* ps);		//pop a element out of the stack

bool EmptyTheStack(Stack* ps);
*/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

/*jvbu hanshu*/

void InitializeStack(Stack* ps)
{
	ps->top = NULL;
}

bool StackIsFull(Stack* ps)
{
	/*code*/
}

bool StackIsEmpty(const Stack* ps)
{
	if (ps->top == NULL)
		return true;
	else
		return false;
}

int StackItemCount(const Stack* ps)
{
	int count = 0;
	Node* pnode = ps->top;
	if (pnode == NULL)
	{
		return 0;
	}
	if (pnode != NULL)
	{
		count++;
	}
	while (pnode->next != NULL)
	{
		count++;
		pnode = pnode->next;
	}
	return count;
}

bool StackPush(Item item, Stack* ps)
{
	Node* pnew;

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		return false;
	}
	if (StackIsEmpty(ps))		//if the stack is empty
	{
		pnew->item = item;
		pnew->next = NULL;
		ps->top = pnew;
	}
	else						//if the stack is not empty
	{
		pnew->item = item;
		pnew->next = ps->top;
		ps->top = pnew;
	}

	return true;
}

bool StackPop(Stack* ps)
{
	Node* temp;
	
	if (StackIsEmpty(ps))
	{
		fprintf(stderr, "the stack is empty now");
		return false;
	}
	else
	{
		temp = ps->top;
		ps->top = ps->top->next;
		free(temp);
	}
	return true;
}

void EmptyTheStack(Stack* ps)
{
	Node* temp;
	Node* scan=ps->top;

	if (scan == NULL)
	{
		return;
	}
	while ( scan->next!= NULL)
	{
		temp = scan;
		scan = scan->next;
		free(temp);
	}
	free(scan);
}