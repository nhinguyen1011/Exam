#include <iostream>

using namespace std;
struct NODE
{
    int s;
    NODE* left;
    NODE* right;
};

int Height(NODE* pRoot)
{
    if (pRoot == NULL)
        return 0;
    int heightLeft = Height(pRoot->left);
    int heightRight = Height(pRoot->right);
    int heightMax = max(heightLeft, heightRight) + 1;
    return heightMax;
}

NODE* createNode(int data)
{
    NODE* p = new NODE;
    p -> s = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

void LRotate(NODE* &pRoot){
    NODE* p = pRoot ->right;
    pRoot ->right = p->left;
    p ->left = pRoot;
    pRoot = p;
}

void RRotate(NODE* &pRoot){
    NODE* p = pRoot ->left;
    pRoot ->left = p->right;
    p ->right = pRoot;
    pRoot = p;
}

void Insert(NODE* &pRoot, int x){
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return ;
    }
        
    if (pRoot ->s == x)
    {
        return ;
    }
    if (pRoot ->s > x)
    {
        Insert(pRoot->left, x);
    }
    if (pRoot ->s < x)
    {
        Insert(pRoot->right, x);
    }

    int balance = Height(pRoot->left) - Height(pRoot->right);
    
    if(balance >= 2){
        if (Height(pRoot->left->left) >= Height(pRoot->left->right)){
            RRotate(pRoot);
        }
        if (Height(pRoot->left->left) < Height(pRoot->left->right)){
            LRotate(pRoot->left);
            RRotate(pRoot);
        }
    }

    if (balance <= -2){
        if (Height(pRoot->right->right) >= Height(pRoot->right->left)){
            LRotate(pRoot);
        }
        if (Height(pRoot->right->right) < Height(pRoot->right->left)){
            RRotate(pRoot->right);
            LRotate(pRoot);
        }
    }
}
void Remove(NODE* &pRoot, int x){
    if (pRoot == NULL)
        return ;
    if (pRoot ->s < x)
        Remove(pRoot->right, x);
    if (pRoot ->s > x)
        Remove(pRoot->left, x);
    if (pRoot ->s == x)
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
            pRoot ->s = p ->s;
            Remove(pRoot ->right, pRoot ->s);
        }
    }

    if (pRoot == NULL)
        return ;

    int balance = Height(pRoot->left) - Height(pRoot->right);
    
    if(balance >= 2){
        if (Height(pRoot->left->left) >= Height(pRoot->left->right)){
            RRotate(pRoot);
        }
        if (Height(pRoot->left->left) <= Height(pRoot->left->right)){
            LRotate(pRoot->left);
            RRotate(pRoot);
        }
    }

    if (balance <= -2){
        if (Height(pRoot->right->right) >= Height(pRoot->right->left)){
            LRotate(pRoot);
        }
        if (Height(pRoot->right->right) <= Height(pRoot->right->left)){
            RRotate(pRoot->right);
            LRotate(pRoot);
        }
    }
}
void Print(NODE* &pRoot, int x){
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return ;
    }
        
    if (pRoot ->s == x && pRoot ->s % 3 != 0)
    {
        return ;
    }
    if (pRoot ->s > x && pRoot ->s % 3 == 0)
    {
        Insert(pRoot->left, x);
    }
    if (pRoot ->s < x && pRoot ->s % 3 == 0)
    {
        Insert(pRoot->right, x);
    }

    int balance = Height(pRoot->left) - Height(pRoot->right);
    
    if(balance >= 2){
        if (Height(pRoot->left->left) >= Height(pRoot->left->right)){
            RRotate(pRoot);
        }
        if (Height(pRoot->left->left) < Height(pRoot->left->right)){
            LRotate(pRoot->left);
            RRotate(pRoot);
        }
    }

    if (balance <= -2){
        if (Height(pRoot->right->right) >= Height(pRoot->right->left)){
            LRotate(pRoot);
        }
        if (Height(pRoot->right->right) < Height(pRoot->right->left)){
            RRotate(pRoot->right);
            LRotate(pRoot);
        }
    }

}
void preOrder(NODE* &pRoot)
{
    if(pRoot != NULL)
    {
        cout << pRoot->s << " ";
        preOrder(pRoot->left);
        preOrder(pRoot->right);
    }
}

int main()
{
    NODE *pRoot = NULL;
    Insert(pRoot, 2);
    Insert(pRoot, 3);
    Insert(pRoot, 10);
    preOrder(pRoot);
    Print(pRoot, 2);
    cout << endl << Height(pRoot);

}
