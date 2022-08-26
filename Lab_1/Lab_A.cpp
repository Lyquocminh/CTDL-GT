#include<stdio.h>
#include<stdlib.h>

int BSearch_Recursion(int a[], int key, int l, int r){
	if(l <= r){
		int mid = (l + r) / 2;
		if(key == a[mid]){
			return mid;
		}
		else if(key < a[mid])
			return BSearch_Recursion(a, key, l, mid-1);
		else
			return BSearch_Recursion(a, key, mid+1, r);
	}
	return -1;
}

void enterList(int a[], int n){
	for(int i=0; i<n; i++){
		printf("Nhap id nguoi thu %d: ", i+1);scanf("%d", &a[i]);
	}
}

void change(int &b, int &c){
	int t = b;
	b = c;
	c = t;
}

void sort(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if(a[j]<a[i]){
				change(a[j], a[i]);
			}
		}
	}
}

void enterId(int &id){
	printf("Nhap ID can tim kiem:");scanf("%d", &id);
}

void showResult(int a[], int key, int l, int r){
	if(BSearch_Recursion(a, key, l, r) == -1){
		printf("Not Found!");
	}
	printf("Found: %d", BSearch_Recursion(a, key, l, r));
}

int main() {
	int id, n, l=0, r, *list;
	do{
		printf("Nhap so nguoi tham gia bau cu:");scanf("%d", &n);
	}while(n<0);
	r=n;
	list = (int*) malloc(n * sizeof(int));
	enterList(list, n);
	sort(list, n);
	enterId(id);
	showResult(list, id, l, r);
	free(list);
}
