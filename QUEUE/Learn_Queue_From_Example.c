#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxLength 100

typedef int ElementType;

typedef struct Queue
{
    int Elements[100];
    int Front, Rear;
} Queue;

void makenullQueue(Queue* pQ)
{
    pQ->Front = -1;
    pQ->Rear = -1;
}

bool emptyQueue(Queue Q)
{
    return (Q.Front == -1);
}

bool fullQueue(Queue Q)
{
    return Q.Rear - Q.Front + 1 == MaxLength;
}

void deQueue(Queue* pQ)
{
    if (!emptyQueue(*pQ))
    {
        pQ->Front++;
        if (pQ->Front > pQ->Rear) makenullQueue(pQ);
    } else printf("Loi: Hang rong!");
}

void enQueue(ElementType X, Queue* pQ)
{
    if (!fullQueue(*pQ))
    {
        if (emptyQueue(*pQ)) pQ->Front = 0;
        if (pQ->Rear == MaxLength - 1)
        {
            for (int i = pQ->Front; i <= pQ->Rear; i++)
            {
                pQ->Elements[i - pQ->Front] = pQ->Elements[i];
            }
            pQ->Rear = MaxLength - 1 - pQ->Front;
            pQ->Front = 0;
        }
        pQ->Rear++;
        pQ->Elements[pQ->Rear] = X;
    } else printf("Loi: Hang day!");
}

ElementType FrontData(Queue Q)
{
    if (!emptyQueue(Q)) return Q.Elements[Q.Front];
    else return -9999;//GIA TRI LOI;
}

int Solution(int Task[], int Prior[], int n)
{
    Queue QTask, QPrior;
    int count = 0;
    makenullQueue(&QTask);
    makenullQueue(&QPrior);
    for (int i = 0; i < n; i++)
    {
        enQueue(Prior[i], &QPrior);
        enQueue(Task[i], &QTask);
    }
    while (!emptyQueue(QTask))
    {
        if (FrontData(QTask) == FrontData(QPrior))
        {
            deQueue(&QTask);
            deQueue(&QPrior);
            count++;
        } 
        else 
        {
            int X = FrontData(QTask);
            deQueue(&QTask);
            enQueue(X, &QTask);;
            count++;
        }
    }
    
    return count;
}

int main()
{
    int A[100], B[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    printf("%d", Solution(A, B, n));
return 0;
}
