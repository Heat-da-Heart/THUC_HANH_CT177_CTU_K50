#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Position;

typedef struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
} SinhVien;

typedef struct DanhSach
{
    SinhVien A[40];
    int n;
} DanhSach;

DanhSach dsRong()
{
    DanhSach L;
    L.n = 0;
    return L;
}

bool ktRong(DanhSach L)
{
    if (L.n == 0) return 1;
    return 0;
}

bool ktDay(DanhSach L)
{
	if (L.n >= 40) return 1;
	return 0;
}

Position Next(int n)
{
	return n++;
}

Position EndList(DanhSach L)
{
	return L.n;
}

void chenCuoi(struct SinhVien S, DanhSach* pL)
{
	if (!ktDay(*pL))
	{
		strcpy(pL->A[pL->n].MSSV, S.MSSV);
		strcpy(pL->A[pL->n].HoTen, S.HoTen);
		pL->A[pL->n].DiemLT = S.DiemLT;
		pL->A[pL->n].DiemTH1 = S.DiemTH1;
		pL->A[pL->n].DiemTH2 = S.DiemTH2;
		pL->n++;
	} else printf("Loi! Danh sach day!");
}

Position tim(char x[], DanhSach L)
{
	Position i = 1;
	while (i <= EndList(L))
	{
		if (strcmp(x, L.A[i-1].MSSV) == 0) return i;
		i++;
	}
	return EndList(L) + 1;
}

void hienthi(DanhSach L)
{	
	float Total = 0;
	Position i = 1;
	while (i <= EndList(L))
	{
		Total = L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2;
		printf("%s - %s - ", L.A[i - 1].MSSV, L.A[i - 1].HoTen); 
		printf("%.2f - %.2f - %.2f - %.2f", L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2, Total);
		printf("\n");
		i++;
	}
}

DanhSach nhap()
{
	int n;
	SinhVien SV;
	DanhSach L = dsRong();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", SV.MSSV);
		scanf("\n");
		fgets(SV.HoTen, 50, stdin);
		if (SV.HoTen[strlen(SV.HoTen) - 1] == '\n') SV.HoTen[strlen(SV.HoTen) - 1] = '\0';
		scanf("\n");
		scanf("%f %f %f", &SV.DiemLT, &SV.DiemTH1, &SV.DiemTH2);
		if (tim(SV.MSSV, L) == EndList(L) + 1) chenCuoi(SV, &L);	
	}
return L;
}

void xoaTai(int p, DanhSach* pL)
{
    if (p > 0 && p < pL->n) 
    {
        for (int i = p; i < pL->n; i++)
            {
                strcpy(pL->A[i-1].HoTen, pL->A[i].HoTen);
                strcpy(pL->A[i-1].MSSV, pL->A[i].MSSV);
                pL->A[i-1].DiemLT = pL->A[i].DiemLT;
                pL->A[i-1].DiemTH1 = pL->A[i].DiemTH1;
                pL->A[i-1].DiemTH2 = pL->A[i].DiemTH2;
            }
        pL->n--;    
    }
}

void xoaSinhVien(char x[], DanhSach* pL)
{
	Position p;
	p = tim(x, *pL);
	if (p != EndList(*pL) + 1) xoaTai(p, pL);
}

void hienthiDat(DanhSach L)
{
	Position i = 1;
	DanhSach Dat = dsRong();
	while (i <= EndList(L))
	{
		if ((L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2) >= 4) chenCuoi(L.A[i - 1], &Dat);
		i++;
	}
	hienthi(Dat);
}

DanhSach chepKhongDat(DanhSach L)
{
	DanhSach KhongDat = dsRong();
	Position i = 1;
	while (i <= EndList(L))
	{
		if ((L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2) < 4) chenCuoi(L.A[i - 1], &KhongDat);
		i++;
	}
	return KhongDat;
}

int main()
{
	int i;
	DanhSach L1;
	DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
	struct SinhVien s1 = {"B1806872","Minh Dong", 1.5f, 1.0f, 1.0f}; 
	struct SinhVien s2 = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
	struct SinhVien s3 = {"B1818973","Dong Nghi", 0.5f, 1.25f, 1.0f}; 
	L.A[1] = s1;
	L.n++;
	L.A[2] = s2;
	L.n++;
	L.A[3] = s3;
	L.n++;
	L1 = chepKhongDat(L);
	printf("Khong dat:\n");
	for(i=0;i<=L1.n-1;i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n",L1.A[i].MSSV, L1.A[i].HoTen, L1.A[i].DiemLT, L1.A[i].DiemTH1, L1.A[i].DiemTH2);
	}
return 0;
}
