#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
};

struct List
{
	NODE* pHead;
	NODE* pTail;
};

struct Stack  //LIFO
{
	List* stack;
};
#include "Header.h"

//1. Initialize a NODE from a given integer:
NODE* createNode(int data)
{
	NODE* p = new NODE;
	p->key = data;
	p->pNext = NULL;
	return p;
}

//2. Initialize a List from a give NODE:
List* createList(NODE* pNode)
{
	List* L = new List;
	if (pNode == NULL)
	{
		L->pHead = NULL;
		L->pTail = NULL;
	}
	L->pHead = pNode;
	L->pTail = pNode;
	return L;
}

//3. Insert an integer to the head of a given List:
bool addHead(List*& L, int data)
{
	NODE* p = createNode(data);
	if (p == NULL)
	{
		return false;
	}
	if (L == NULL) //danh sách đang rỗng
	{
		L = createList(p); //tạo danh sách L với node p
		return false;
	}
	else
	{
		p->pNext = L->pHead; //cho p trỏ đến node đầu
		L->pHead = p; //cập nhật lại node đầu
		return true;
	}
}

//5.Remove the first NODE of a given List
void removeHead(List*& L)
{
	if (L == NULL)
		return;
	if (L->pHead == L->pTail)
	{
		L->pHead = NULL;
		L->pTail = NULL;
		delete L->pHead;
	}
	else
	{
		NODE* p = L->pHead->pNext;
		//L->pHead = L->pHead->pNext;
		delete (L->pHead);
		L->pHead = p;
	}
}

//15. Count the number of elements List
int countElements(List* L)
{
	if (L == NULL)
		return 0;
	int count = 0;
	for (NODE* p = L->pHead; p != NULL; p = p->pNext)
	{
		count++;
	}
	return count;
}

//------------------------------------------------------
Stack* initialize(int data)
{
	Stack* S = new Stack;
	NODE* p = createNode(data);
	S->stack = createList(p);
	return S;
}

void push(Stack*& S, int data)
{
	addHead(S->stack, data);
}

int pop(Stack*& S)
{
	int val = S->stack->pHead->key;
	removeHead(S->stack);
	return val;
}

int count(Stack*& S)
{
	return countElements(S->stack);
}

bool isEmpty(Stack*& S)
{
	if (S->stack->pHead->key == NULL)
		return true;
	return false;
}

void printStack(Stack* S)
{
	if (isEmpty(S) == true)
		return;

	NODE* p = S->stack->pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->pNext;
	}
	cout << endl;
}

int main()
{
	Stack* S = initialize(10);
	push(S, 20);
	push(S, 30);
	printStack(S);

	cout << pop(S) << endl;
	printStack(S);

	cout << "Number of node: " << count(S) << endl;

	return 0;
}
