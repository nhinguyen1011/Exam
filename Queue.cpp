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

struct Queue //FIFO
{
	List* queue;
};

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

//4. Insert an integer to the tail of a given List:
bool addTail(List*& L, int data)
{
	NODE* p = createNode(data);
	if (p == NULL)
	{
		return false;
	}
	if (L == NULL)
	{
		L = createList(p);
		return true;
	}
	else
	{
		L->pTail->pNext = p;
		L->pTail = p;
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

//-------------------------------------------------
Queue* initialize(int data)
{
	Queue* Q = new Queue;
	NODE* p = createNode(data);
	Q->queue = createList(p);
	return Q;
}

void push(Queue*& Q, int data)
{
	addTail(Q->queue, data);
}

int pop(Queue*& Q)
{
	int val = Q->queue->pHead->key;
	removeHead(Q->queue);
	return val;
}

int count(Queue *& Q)
{
	return countElements(Q->queue);
}

bool isEmpty(Queue*& Q)
{
	if (Q->queue->pHead->key == NULL)
		return true;
	return false;
}

void printQueue(Queue* Q)
{
	if (isEmpty(Q) == true)
		return;

	NODE* p = Q->queue->pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->pNext;
	}
	cout << endl;
}

int main()
{
		Queue* Q = initialize(10);
		push(Q, 20);
		push(Q, 30);
		printQueue(Q);

		cout << pop(Q) << endl;
		printQueue(Q);

		cout << "Number of node: " << count(Q) << endl;

		return 0;
}