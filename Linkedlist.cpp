#include <iostream>
using namespace std;
struct NODE
{
	int key;
	NODE* pNext;
};

struct List
{
	NODE* pHead;
	NODE* pTail;
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

void removeLe(List*& L, int data){
	NODE* p = createNode(data);
	if (p == NULL )
		return;
	if (L == NULL )
		return;
	L->pHead = p->key;	
	if (p->key % 2 != 0)
		removeTail(L);
	else
		delete(L->pHead);
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

//6. Remove the last NODE of a given List:
void removeTail(List*& L)
{
	if (L == NULL)
	{
		return;
	}
	if (L->pHead == L->pTail)
	{

		removeHead(L);
	}
	else
	{
		for (NODE* k = L->pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == L->pTail)
			{
				delete L->pTail;
				k->pNext = NULL;
				L->pTail = k;
			}
		}
	}
}

//7. Remove all NODE from a given List
void removeAll(List*& L)
{
	if (L == NULL)
		return;
	else
	{
		while (L->pHead != NULL)
		{
			removeHead(L);
		}
		cout << " * ";
	}
}

//8. Remove an integer before a value of a given List
void removeBefore(List*& L, int val)
{
	if (L == NULL)
		return;
	if (L->pHead == L->pTail)
		return;
	if (L->pHead->pNext->key == val)
	{
		removeHead(L);
		return;
	}
	NODE* p1 = L->pHead->pNext;
	NODE* p2 = L->pHead;
	while (p1->pNext->key != val && p1 != L->pTail) {
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	if (p1 != L->pTail) {
		p2->pNext = p1->pNext;
	}
	delete p1;
}

//9. Remove an integer after a value of a given List
void removeAfter(List*& L, int val)
{
	if (L == NULL) //danh sách rỗng
		return;
	if (L->pHead == L->pTail) //danh sách có 1 node
		return;
	NODE* q = createNode(val); //node sau node q là node cần xóa
	for (NODE* k = L->pHead; k != NULL; k = k->pNext)
	{
		if (k->key == q->key)
		{
			NODE* g = k->pNext;
			k->pNext = g->pNext;
			delete g;
		}
	}
}

//10. Insert an integer at a position of a given List
bool addPos(List*& L, int data, int pos)
{
	if (L == NULL)
		return false;
	if (pos == 0)
	{
		addHead(L, data);
		return true;
	}
	int i = 0;
	NODE* temp = L->pHead;
	while (i < pos - 1 && temp != NULL)
	{
		temp = temp->pNext;
		i++;
	}
	if (temp != NULL && temp->pNext == NULL)
	{
		addTail(L, data);
		return true;
	}
	else
	{
		NODE* p = createNode(data);
		p->pNext = temp->pNext;
		temp->pNext = p;
	}
	return true;
}

//11. Remove an integer at a position of a given List
void removePos(List*& L, int data, int pos)
{
	if (L == NULL)
		return;
	if (pos == 0)
	{
		removeHead(L);
		return;
	}
	int i = 0;
	NODE* temp = L->pHead;
	while (i < pos - 1 && temp != NULL)
	{
		temp = temp->pNext;
		i++;
	}
	if (temp != NULL && temp->pNext == L->pTail)
	{
		removeTail(L);
		return;
	}
	else
	{
		NODE* p = temp->pNext;
		temp->pNext = temp->pNext->pNext;
		delete p;
		return;
	}
}

//12. Insert an integer before a value of a given List
bool addBefore(List*& L, int data, int val)
{
	if (L == NULL)
		return false;
	NODE* ptr = L->pHead;
	//NODE* preptr = L->pHead;
	if (ptr->key == val)
	{
		addHead(L, data);
		return true;
	}
	while (ptr->pNext->key != val) //ptr trỏ đến node trước vị trí insert node
	{
		//preptr = ptr; 
		ptr = ptr->pNext; //ptr trỏ đến node sau vị trí cần insert
	}
	NODE* p = createNode(data);
	//preptr->pNext = p;
	p->pNext = ptr->pNext;
	ptr->pNext = p;
	return true;
}

//13. Insert an integer after a value of a given List
bool addAfter(List*& L, int data, int val)
{
	if (L == NULL)
		return false;
	NODE* ptr = L->pHead;
	while (ptr->key != val)
	{
		ptr = ptr->pNext;
	}
	if (L->pTail == ptr)
	{
		addTail(L, data);
		return true;
	}
	NODE* p = createNode(data);
	p->pNext = ptr->pNext;
	ptr->pNext = p;
	return true;
}

//14. Print all elements of a given List:
void printList(List* L)
{
	if (L == NULL)
		return;
	NODE* p = L->pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->pNext;
	}
	cout << endl;
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

//16. Create a new List by reverse a given List
List* reverseList(List* L)
{
	//List* L1 = createList(NULL); //tạo list rỗng
	NODE* cur = L->pHead;
	NODE* temp = new NODE;
	NODE* prev = NULL;
	while (cur != NULL)
	{
		temp = cur->pNext;
		cur->pNext = prev;
		prev = cur;
		cur = temp;
	}
	L->pHead = prev;
	return L;
}

//17. Remove all duplicates from a given List
void removeDuplicate(List*& L)
{
	NODE* ptr1, * ptr2, * dup;
	ptr1 = L->pHead;

	/* Pick elements one by one */
	while (ptr1 != NULL && ptr1->pNext != NULL)
	{
		ptr2 = ptr1;

		/* Compare the picked element with rest
		   of the elements */
		while (ptr2->pNext != NULL) {
			/* If duplicate then delete it */
			if (ptr1->key == ptr2->pNext->key) {
				/* sequence of steps is important here */
				dup = ptr2->pNext;
				ptr2->pNext = ptr2->pNext->pNext;
				delete (dup);
			}
			else /* This is tricky */
				ptr2 = ptr2->pNext;
		}
		ptr1 = ptr1->pNext;
	}
}

//18. Remove all key value from a given List
bool removeElement(List*& L, int key)
{
	if (L == NULL)
		return false;
	NODE* temp = NULL;

	for (NODE* p = L->pHead; p;)
	{
		if (p->key == key)
		{
			NODE* q = p->pNext;
			if (temp == NULL)
			{
				delete p;
				p = q;
				L->pHead = p;
			}
			else
			{
				temp->pNext = q;
				delete p;
				p = temp->pNext;
			}
		}
		else
		{
			temp = p;
			p = p->pNext;
		}
	}
	return true;
}
int main()
{
	NODE* p = createNode(1);
	List *L = createList(p);
	addTail(L, 2);
	addTail(L, 3);
	addTail(L, 4);
	addTail(L, 5);
	//addTail(L, 20);
	printList(L);
	//cout << "\n";
	/*addHead(L, 69);
	addTail(L, 179);*/
	//removeHead(L);
	//removeTail(L);
	//removeAll(L);
	//removeBefore(L, 5);
	//removeAfter(L, 10);
	//addPos(L, 69, 5);
	//addBefore(L, 101, 10);
	//addAfter(L, 1001, 2);
	//removePos(L, 50, 4);
	//reverseList(L);
	removeDuplicate(L);
	//removeElement(L, 10);
	printList(L);
	cout << 	removeLe(L, 3);
	cout << "Number of nodes: " << countElements(L) << endl;
	

	cout << "\n";
	return 0;
}