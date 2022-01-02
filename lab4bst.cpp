#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct NODE{
    int key;
    NODE* left;
    NODE* right;
};

NODE* createNode(int data){
    NODE* p = new NODE;
    p -> key = data;
    p ->left = NULL;
    p -> right = NULL;
    
    return p;
}

void Insert(NODE* &pRoot, int x){
    if (pRoot == NULL)
    {
        pRoot = createNode(x) ;
        return ;
    }
    if (pRoot ->key == x)
    {
        return ;
    }
    if (pRoot->key > x ){
        Insert(pRoot ->left,x) ;
    }
    if (pRoot->key < x )
        Insert(pRoot ->right,x) ;
    }

void LevelOrder(NODE* pRoot){
    if (pRoot == NULL){
         return ;
    }
    queue <NODE*> q;
    q.push(pRoot);
    while (!q.empty())
    {
        NODE* p = q.front();
        q.pop();
        if (p->left != NULL){
                q.push(p->left);
        }
        if (p->right != NULL){
                q.push(p->right);
        }
        cout << p->key << " ";
    }
}

void NLR(NODE* pRoot){
    if (pRoot == NULL)
    {
        return ;
    }
    else
        cout << pRoot -> key << " ";
        NLR(pRoot->left);
        NLR(pRoot->right);
}

void LNR(NODE* pRoot){
    if (pRoot == NULL)
    {
        return ;
    }
    else
        NLR(pRoot->left);
        cout << pRoot -> key <<" ";
        NLR(pRoot->right);
}

void LRN(NODE* pRoot){
    if (pRoot == NULL)
    {
        return ;
    }
    else
        NLR(pRoot->left);
        NLR(pRoot->right);
        cout << pRoot -> key <<" ";
}

int Height(NODE* pRoot)
{
    if (pRoot == NULL)
        return 0;
    int heightLeft = Height(pRoot->left);
    int heightRight = Height(pRoot->right);
    int heightMax = max(heightLeft, heightRight) + 1;
    return heightMax;
}

int countNode(NODE* pRoot){
    if (pRoot == NULL)
        return 0;
    return (countNode(pRoot->left) + countNode(pRoot->right)) + 1;
}

int sumNode(NODE* pRoot){
    if (pRoot == NULL)
        return 0;
    return ((sumNode(pRoot->left) + sumNode(pRoot->right)) + pRoot->key) ;
}

NODE* Search(NODE* pRoot, int x)
{
    if (pRoot == NULL)
        return NULL;
    if (pRoot->key == x){
        return pRoot;
    }
    if (pRoot->key < x){
        return Search(pRoot->right, x);
    }
    else if (pRoot->key > x){
        return Search(pRoot->left, x);
    }
    return pRoot;
}

void Remove(NODE* &pRoot, int x){
    if (pRoot == NULL)
        return ;
    if (pRoot->key < x)
        Remove(pRoot->right, x);
    if (pRoot->key > x)
        Remove(pRoot->left, x);
    if (pRoot->key == x)
    {
        if (pRoot->right == NULL && pRoot->left == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->right != NULL && pRoot->left == NULL){
            NODE* p = pRoot;
            pRoot = pRoot ->left ;
            delete p;
        }
        else if (pRoot->right == NULL && pRoot->left != NULL){
            NODE* p = pRoot;
            pRoot = pRoot ->right ;
            delete p;
        }
        else if (pRoot->right != NULL && pRoot->left != NULL){
            NODE* p = pRoot->right;
            while (p->left != NULL){
                p = p ->left;
            }
            pRoot ->key = p ->key;
            Remove(pRoot ->right, pRoot ->key);
        }
    }
}

NODE* createTree(int a[], int n){
    NODE* pRoot = NULL;
    for (int i = 0; i < n; i++)
    {
        Insert(pRoot, a[i]);
        cout << a[i];
    }
    return pRoot ;
}


void removeTree(NODE* &pRoot){
	if(pRoot == NULL)
		return;
	while(pRoot != NULL){
		Remove(pRoot, pRoot->key);
	}
}

int heightNode(NODE* pRoot, int val){
	if(pRoot == NULL)
		return 0;
	if(pRoot->key == val)
		return Height(pRoot);
	return Height(pRoot->left) + Height(pRoot->right);
}	

int Level(NODE* pRoot, NODE* p){
	if(pRoot == NULL)
		return 0;
	queue <NODE*> q1;
	queue <int> q2;
	q1.push(pRoot);
	q2.push(1);
	while(!q1.empty()){
		NODE* temp = q1.front();;
		q1.pop();
		int level = q2.front();
		q2.pop();
		if(temp == p){
			return level;
		}
		if(temp->left != NULL){
			q1.push(temp->left);
			q2.push(level + 1);
		}
		if(temp->right != NULL){
			q1.push(temp->right);
			q2.push(level + 1);
		}
	}
	return 0;
}


int countLeaf(NODE* pRoot){
    if (pRoot == NULL )
        return 0;
   if (pRoot->left == NULL && pRoot->right == NULL)
        return 1;
    return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}

int countLess(NODE* pRoot, int x){
	if(pRoot == NULL)
		return 0;
	if(pRoot->key < x){
		return countLess(pRoot->left, x) + countLess(pRoot->right, x) + 1 ;
	}
    return countLess(pRoot->left, x) + countLess(pRoot->right, x);
}

int countGreater(NODE* pRoot, int x){
	if (pRoot == NULL)
    {
        return 0;
    }
    if (pRoot->key > x)
    {
        return countGreater(pRoot->left, x) + countGreater(pRoot->right, x) + 1;
    }
    return countGreater(pRoot->left, x) + countGreater(pRoot->right, x);
}


int minNode(NODE* pRoot){
	if(pRoot == NULL)
		return 100000000; 
	return min(min(minNode(pRoot->left), minNode(pRoot->right)), pRoot->key);
}

int maxNode(NODE* pRoot){
	if(pRoot == NULL)
		return -100000000;
	return max(max(maxNode(pRoot->left), maxNode(pRoot->right)), pRoot->key);
}

bool isBST(NODE* pRoot){
	if(pRoot == NULL){
		return true;
	}
	if(pRoot->key > maxNode(pRoot->left) && pRoot->key < minNode(pRoot->right)){
		return isBST(pRoot->left) && isBST(pRoot->right);
	}
	return false;
}


bool isFullBST(NODE*pRoot){
	if(pRoot == NULL)
		return true;
	if(pRoot->left == NULL && pRoot->right == NULL)
		return true;
	if(pRoot->left != NULL && pRoot->right != NULL)
    {
		return isBST(pRoot) && isFullBST(pRoot->left) && isFullBST(pRoot->right);
	}
	return false;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
        NODE *pRoot = NULL;
        for(int i = 0; i < 5; i++){
                Insert(pRoot, a[i]) ;
        }
        LevelOrder(pRoot);
        cout << endl <<"so node lon hon la: " << countGreater(pRoot, 3);
        cout << endl <<"tong cac node la: " <<  sumNode(pRoot);
        cout << endl <<"node nho nhat la: " <<  minNode(pRoot);
        cout << endl <<"node lon nhat la: " <<  maxNode(pRoot);
        cout << endl <<"tong cac node la la: " << countLeaf(pRoot);
}


