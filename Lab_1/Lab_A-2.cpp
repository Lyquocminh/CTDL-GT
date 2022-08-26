#include<stdio.h>
#include<stdlib.h>

int LSearch(int a[], int n, int key){
	int find = -1;
	for(int i=0; i<n; i++){
		if(a[i]==key){
			find = i;
			break;
		}
	}
	return find;
}

//void enterList(int a[], int n){
//	for(int i=0; i<n; i++){
//		printf("Enter chracters : ", i+1);scanf("%d", &a[i]);
//	}
//}
//
//void enterId(int &id){
//	printf("Nhap ID can tim kiem:");scanf("%d", &id);
//}

void showResult(int a[], int n, int key){
	if(LSearch(a, n, key) == -1){
		printf("Not Found!");
	}
	printf("Found: %d", LSearch(a, n, key));
}

main() {
	int n, *list, id;
	do{
		printf("Nhap so nguoi tham gia bau cu:");scanf("%d", &n);
	}while(n<0);
	list = (int*) malloc(n * sizeof(int));
	enterList(list, n);
	enterId(id);
	showResult(list, n, id);
	free(list);
}
