#include<stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int &b, int &c){
	int t = b; 
	b = c;
	c = t;
}
void taoMang(int a[], int n){
	for(int i=0; i<n; i++)
		a[i] = rand()%(0-100);
}
void xuatMang(int a[], int n){
	printf("\n---------------------\n");
	for(int i=0; i<n; i++)
		printf("\t %d", a[i]);
}
void bubbleSort(int a[], int n){
	for(int i=0; i<n; i++)
		for(int j=n-1; j>i; j--)
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);	
}
void bubbleSort2(int a[], int n){
	for(int i=0; i<n; i++)
		for(int j=n-1; j>0; j--)
			if(i<j){
				if(a[j] < a[j-1])
					swap(a[j], a[j-1]);	
			}else 
				break;
}
int main() {
	srand(time(NULL));
	int n;
	printf("Nhap n: "); scanf("%d", &n);
	int a[n];
	taoMang(a,n);
	xuatMang(a,n);
	clock_t t1 = clock();
	bubbleSort(a, n);
	clock_t t2 = clock();
	xuatMang(a,n);
	printf("\nThoi gian thuc thi: %f", (float)(t2-t1));
	return 0;
}
