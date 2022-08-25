#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void TaoMang(int a[], int n){
	srand(time(NULL));
	for(int i=0;i<n;i++)
		a[i]= a[i-1] + rand()%(0-50);
}
void XuatMang(int a[], int n){
	printf("Gia tri cua mang: ");
	for(int i=0;i<n;i++)
		printf("\t a[%d] = %d", i, a[i]);
}
int TimNhiPhan(int a[], int n, int x){
	int left = 0, right = n-1;
	do{
		int mid = (left+right)/2;
		if(x<a[mid]) 
			right = mid-1;
		else if(x>a[mid])
			left = mid+1;
		else 
			return mid;
	}while(left<=right);
	
	return -1;
}
void XuatKQ(int a[], int n, int x){
	if(TimNhiPhan(a,n,x)==-1)
		printf("\nKhong tim thay!");
	else 
		printf("\nGia tri %d nam o vi tri thu %d", x, TimNhiPhan(a,n,x));
}
int main(){
	int n;
	printf("Nhap vao so luong phan tu: "); scanf("%d", &n);
	int a[n];
	TaoMang(a,n);
	XuatMang(a,n);
	int x;
	printf("\nNhap vao gia tri can tim: "); scanf("%d", &x);
	clock_t t1 = clock();
	XuatKQ(a,n,x);
	clock_t t2 = clock();
	printf("\nThoi gian thuc thi: %f", (float)t2-t1);
	return 0;
}
