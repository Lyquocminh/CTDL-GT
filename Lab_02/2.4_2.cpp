#include<stdio.h>

void swap(int &b, int &c){
	int t = b; 
	b = c;
	c = t;
}

void InsertionSort(int a[], int n){
	int pos;
	for (int i = 0; i < n; i++){
		pos = i;
		while (pos > 0 && a[pos] > a[pos-1])
		{
			swap(a[pos], a[pos-1]);
			pos--;
		}
	}
}

main() {
	int arr[] = {3, 2, 8, 9, 0, 1, 6, 10, 7, 5, 4};
	InsertionSort(arr, 10);
	for(int i=0; i<10; i++){
		printf("%d	", arr[i]);
	}
}
