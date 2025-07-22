#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//KHAI BAO LINKED LIST
typedef int ElementType;

typedef struct Node
{
  int Data;
  struct Node* Next;
} Node;

typedef struct Node* Position;
typedef Position List;


//TAO RONG
void makeNull(List* pN)
{
    (*pN) = (Node*)malloc(sizeof(Node));
    (*pN)->Next = NULL;
}


//TRA VE PHAN TU CUOI CUNG
Position EndList(List L)
{
    Position P;

    P = L;

    while (P->Next != NULL)
    {
        P = P->Next;
    }

    return P;
}


//TRA VE PHAN TU DAU TIEN
Position First(List L)
{
    return L;
}


//GOI PHAN TU KE TIEP
Position Next(Position P)
{
    return P->Next;
}


//TRA VE GIA TRI CUA PHAN TU VI TRI P
ElementType Retrieve(Position P, List L)
{
    return P->Next->Data;
}


//DINH VI PHAN TU X DAU TIEN TRONG LIST
Position Locate(ElementType x, List L)
{
    Position T = L;

    while (T->Next != NULL)
    {
        if(T->Next->Data == x) return T;
        T = T->Next;
    }

    return T->Next;
}


//XOA PHAN TU VI TRI P TRONG LIST
void deleteList(Position P, List* pL)
{
    Position T;

    if (P->Next != NULL)
    {
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}


// CHEN PHAN TU X VAO VI TRI P TRONG LIST
void Insert(ElementType x, Position P)
{
    Position temp;
    temp = (Node*)malloc(sizeof(Node));

    temp->Data = x;
    temp->Next = P->Next;
    P->Next = temp;
}


//NHAP VAO LIST N PHAN TU NHAP TU BAN PHIM
void Input(List* pL)
{
    ElementType n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Insert(x, EndList(*pL));
    }
}


//IN RA MAN HINH
void Output(List L)
{
    Position T = L->Next;

    while(T != NULL)
    {
        printf("%d ", T->Data);
        T = T->Next;
    }

    printf("\n");
}


//BUBBLE SORT TREN LINKED LIST
void Sort(List* pL)
{
    Position ptr1 = *pL;
    while(ptr1->Next != NULL)
    {
        Position ptr2 = (*pL)->Next;
        while(ptr2->Next!= NULL)
        {
            if(ptr2->Data > ptr2->Next->Data)
            {
                ElementType temp = ptr2->Next->Data;
                ptr2->Next->Data = ptr2->Data;
                ptr2->Data = temp;
            }
            ptr2 = ptr2->Next;
        }
        ptr1 = ptr1->Next;
    }
}


//IN SO LE TRONG LIST
void Odd(List L)
{
    Position temp = L;

    while(temp->Next != NULL)
    {
        if (Retrieve(temp, L) % 2 != 0) printf("%d ", Retrieve(temp, L));
        temp = temp->Next;
    }
    printf("\n");
}


//IN SO CHAN TRONG LIST
void Even(List L)
{
    Position temp = L;

    while(temp->Next != NULL)
    {
        if (Retrieve(temp, L) % 2 == 0) printf("%d ", Retrieve(temp, L));
        temp = temp->Next;
    }
    printf("\n");
}


//TINH GIA TRI TRUNG BINH CAC PHAN TU TRONG LIST
float Averange(List L)
{
    int S = 0, count = 0;
    Position temp = L;

    while(temp->Next != NULL)
    {
            S += Retrieve(temp, L);
            count++;
            temp = temp->Next;
    }

    return 1.0*S / count; // NHAN 1.0 VI EP S VE KIEU SO THUC
}


//TINH GIA TRI TRUNG BINH CAC PHAN TU CHAN TRONG LIST
float EvenAverage(List L)
{
    Position temp = L;
    int S = 0, count = 0;
    while(temp->Next != NULL)
    {
        if (Retrieve(temp, L) % 2 == 0)
        {
            S += Retrieve(temp, L);
            count++;
       }
        temp = temp->Next;
    }
    return 1.0 * S / count; // EP S VE KIEU SO THUC
}


//XOA TAT CA CAC PHAN TU CO GIA TRI X TRONG LIST
void deleteAll(ElementType x, List* pL)
{
    Position temp = *pL;
    while (Locate(x, temp) != NULL)
    {
        deleteList(Locate(x, temp), pL);
    }
}

// CHUONG TRINH CHINH
int main()
{
    ElementType x;
    List L;

    makeNull(&L);
    Input(&L);
    Output(L);
    scanf("%d", &x);
    deleteAll(x, &L);
    Output(L);


    return 0;
}
