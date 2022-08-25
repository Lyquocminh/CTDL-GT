#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void nhapMang(int a[], int n){
	for(int i = 0; i<n; i++){
		a[i] = -100 + rand()%(-100-100);
	}
}
void xuatMang(int a[], int n){
	printf("Gia tri cua mang la:\n");
	for(int i=0; i<n; i++)
		printf("a[%d] = %d\n", i, a[i]);
}
int timKiem(int a[], int n, int x){
	for(int i=0; i<n; i++)
		if(a[i]==x)
			return i;
	return -1;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void sxTang(int a[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[j] < a[i])
				swap(a[j], a[i]);
}
void sxGiam(int a[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[j] > a[i])
				swap(a[j], a[i]);
}
int main(){
	srand(time(NULL));
	int n;
	printf("Nhap vao n: "); scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	sxTang(a,n);
	printf("Sau khi sap xep tang\n");
	xuatMang(a,n);
	sxGiam(a,n);
	printf("Sau khi sap xep giam\n");
	xuatMang(a,n);
	int x;
	printf("Nhap vao so can tim: "); scanf("%d", &x);
	int kq = timKiem(a,n,x);
	if(kq!=-1)
		printf("Gia tri %d nam o vi tri thu %d trong mang\n", x, kq);
	else
		printf("Gia tri %d khong co trong mang\n", x);
	return 0;
}
