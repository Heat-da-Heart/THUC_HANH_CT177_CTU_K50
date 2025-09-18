#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int Key;
    struct Node *Left, *Right;
};

typedef struct Node* Tree;
//#1
Tree initTree()
{
    Tree T = NULL;
    return T;
}
//#2
bool isEmpty(Tree T)
{
    return T == NULL;
}
//#3
void insertNode(int X, Tree* pT)
{
    if ((*pT) == NULL)
    {
        struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->Key = X;
        tmp->Left = NULL;
        tmp->Right = NULL;
        (*pT) = tmp;
    } else if (X < (*pT)->Key) insertNode(X, &((*pT)->Left));
    else if (X > (*pT)->Key) insertNode(X, &((*pT)->Right));
}
//#4
void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}
//#5
void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}
//#6
void posOrder(Tree T)
{
    if (T != NULL)
    {
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
    }
}
//#7
Tree searchNode(int X, Tree T)
{
    if (T == NULL) return NULL;
    else if (X < T->Key) return searchNode(X, T->Left);
    else if (X > T->Key) return searchNode(X, T->Right);
    return T;
}
//#8
Tree getParent(int X, Tree T)
{   
    
    if (T->Left != NULL && T->Left->Key == X) return T;
    if (T->Right != NULL && T->Right->Key == X) return T;
    if (X < T->Key && T->Left != NULL) return getParent(X, T->Left);
    if (X > T->Key && T->Right != NULL) return getParent(X, T->Right);
    return NULL;
}
//#9
Tree rightSibling(int X, Tree T)
{
    Tree tmp = getParent(X, T);
    if (tmp == NULL || tmp->Right == NULL || tmp->Right->Key == X) return NULL;
    return tmp->Right;
}
//#10
void printPath(int X, Tree T)
{
    Tree tmp = T;
    bool found = 0;
    while (tmp != NULL && found == 0)
    {
        if (X < tmp->Key && tmp->Left != NULL) 
        {
            printf("%d ", tmp->Key);
            tmp = tmp->Left;
        } else if (X > tmp->Key && tmp->Right != NULL) 
        {
            printf("%d ", tmp->Key);
            tmp = tmp->Right;
        } else if (X == tmp->Key) found = 1;
        else if (X > tmp->Key && tmp->Right == NULL) break;
        else if (X < tmp->Key && tmp->Left == NULL) break;
    }
    if (found == 1) printf("%d -> Tim thay", tmp->Key);
    if (found == 0) printf("%d -> Khong thay", tmp->Key);
} 
//#11 THE ALGORITHMS FOR P11 https://www.enjoyalgorithms.com/blog/inorder-predecessor-binary-search-tree
Tree GetMax(Tree T)
{
	while (T->Right != NULL) T = T->Right;
	return T;
}

Tree getPrevious(int X, Tree T)
{
	if (T == NULL) return NULL;
	Tree prev = NULL;
	while (T != NULL)
	{
		if (T->Key > X) T = T->Left;
		else if (T->Key < X) 
		{
			prev = T;
			T = T->Right;
		} 
		else 
		{
		        if (T->Left != NULL) prev = GetMax(T->Left);
				break;
		}
	}
	return prev;
}
//#12
Tree getMin(Tree T)
{
    Tree tmp = T;
    while (tmp->Left != NULL)
    {
        tmp = tmp->Left;
    }
    return tmp;
}

Tree getNext(int X, Tree T)
{
    Tree tmp = searchNode(X, T);
    if (tmp->Right != NULL) return getMin(tmp->Right);
    Tree Next = NULL;
    Tree Dummy = T;
    while (Dummy != NULL)
    {
        if (Dummy->Key > X)
        {
            Next = Dummy;
            Dummy = Dummy->Left;
        } else if (Dummy->Key < X) Dummy = Dummy->Right;
        else break;
    }
    return Next;
}
int deleteMin(Tree* pT)
{
    int K;
    if ((*pT)->Left == NULL)
    {
        K = (*pT)->Key;
        (*pT) = (*pT)->Right;
        return K;
    } else return deleteMin(&((*pT)->Left));
}
//#13
void deleteNode(int X, Tree* pT)
{
    if (*pT != NULL) 
    {
        if (X < (*pT)->Key) deleteNode(X, &((*pT)->Left));
        else if (X > (*pT)->Key) deleteNode(X, &((*pT)->Right));
        else 
        {
            if ((*pT)->Left == NULL && (*pT)->Right == NULL) (*pT) = NULL;
            else if ((*pT)->Left == NULL) (*pT) = (*pT)->Right;
            else if ((*pT)->Right == NULL) (*pT) = (*pT)->Left;
            else (*pT)->Key = deleteMin(&((*pT)->Right));
        }
    }
}
//#14 & #15
int Max(int A, int B)
{
    if (A > B) return A;
    return B;
}

int getHeight(Tree T)
{
    if (T == NULL) return -1;
        else
        {
            if (T->Left == NULL && T->Right == NULL) return 0;
            else return 1 + Max(getHeight(T->Left), getHeight(T->Right));
        }
}

int hNode(int X, Tree T)
{
    return getHeight(searchNode(X, T));
}

int main()
{
    Tree T=NULL;
    Tree p;
    int x;
    insertNode(27,&T);
    insertNode(12,&T);
    insertNode(40,&T);
    insertNode(4,&T);
    insertNode(20,&T);
    insertNode(34,&T);
    insertNode(30,&T); 
    insertNode(50,&T); 
    x=12;
    p = getPrevious(x,T);
    if (p==NULL)
    printf("%d khong co nut dung truoc",x);
        else printf("Nut dung truoc la %d",p->Key);
}
