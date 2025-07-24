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

Tree initTree()
{
    Tree T = NULL;
    return T;
}

bool isEmpty(Tree T)
{
    return T == NULL;
}

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

void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}

void posOrder(Tree T)
{
    if (T != NULL)
    {
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
    }
}

Tree searchNode(int X, Tree T)
{
    if (T == NULL) return NULL;
    else if (X < T->Key) return searchNode(X, T->Left);
    else if (X > T->Key) return searchNode(X, T->Right);
    return T;
}

Tree getParent(int X, Tree T)
{

    if (T->Left != NULL && T->Left->Key == X) return T;
    if (T->Right != NULL && T->Right->Key == X) return T;
    if (X < T->Key && T->Left != NULL) return getParent(X, T->Left);
    if (X > T->Key && T->Right != NULL) return getParent(X, T->Right);
    return NULL;
}


Tree rightSibling(int X, Tree T)
{
    Tree tmp = getParent(X, T);
    if (tmp == NULL || tmp->Right == NULL || tmp->Right->Key == X) return NULL;
    return tmp->Right;
}


//CAU 10
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


//CAU 14
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
