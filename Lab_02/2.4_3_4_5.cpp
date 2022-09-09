#include<stdio.h>
#include <string.h>
struct NhanVien{
	char ten[10];
	double luong;
};

void swap(NhanVien &n1, NhanVien &n2)
{
	NhanVien t = n1;
	n1 = n2;
	n2 = t; 
}

void nhapMotNhanVien(NhanVien &p){
	printf("Nhap ten:");
	fflush(stdin);
	gets(p.ten);
	printf("Nhap muc luong:\n");scanf("%lf", &p.luong);
}

void xuatMotNhanVien(NhanVien p){
	printf("%s\t%lf\n", p.ten, p.luong);
}

void nhapDanhSachNhanVien(NhanVien a[], int n){
	for(int i=0; i<n; i++){
		nhapMotNhanVien(a[i]);
	}
}

void xuatDanhSachNhanVien(NhanVien a[], int n){
	for(int i=0; i<n; i++){
		xuatMotNhanVien(a[i]);
	}
}
void bubbleSortTen(NhanVien a[], int n){
	for(int i=0; i<n; i++){
		for(int j=n-1; j>0; j--){
			if(i<j){
				if(strcmp(a[j].ten, a[j-1].ten) < 0)
					swap(a[j], a[j-1]);
			}else{
				break;
			}
		}
	}
}
void InsertionSortIncrease(NhanVien a[], int n){
	int pos;
	for (int i = 0; i < n; i++){
		pos = i;
		while (pos > 0 && a[pos].luong < a[pos-1].luong)
		{
			swap(a[pos], a[pos-1]);
			pos--;
		}
	}
}

void InsertionSortReduce(NhanVien a[], int n){
	int pos;
	for (int i = 0; i < n; i++){
		pos = i;
		while (pos > 0 && a[pos].luong > a[pos-1].luong)
		{
			swap(a[pos], a[pos-1]);
			pos--;
		}
	}
}
void XuatDStheoTop(NhanVien a[], int top){
	for(int i=0; i<top; i++)
		xuatMotNhanVien(a[i]);
}
main() {
	NhanVien a[100];
	int n;
	printf("Nhap so luong nhan vien muon nhap:");scanf("%d", &n);
	nhapDanhSachNhanVien(a, n);
	printf("Danh sach nhan vien vua nhap\n");	
	xuatDanhSachNhanVien(a, n);
	bubbleSortTen(a, n);
	printf("Danh sach nhan vien sap xep theo ten\n");
	xuatDanhSachNhanVien(a, n);
	InsertionSortIncrease(a, n);
	printf("Danh sach nhan vien sau khi sap xep tang dan theo muc luong\n");
	xuatDanhSachNhanVien(a, n);
	printf("Danh sach nhan vien sau khi sap xep giam dan theo muc luong\n");
	InsertionSortReduce(a, n);
	xuatDanhSachNhanVien(a, n);
	printf("Top 10 nhan vien muc luong cao nhat\n");
	XuatDStheoTop(a, 10);
	return 0;
}
