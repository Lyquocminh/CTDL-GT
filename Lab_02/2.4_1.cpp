#include<stdio.h>

void swap(int &b, int &c){
	int t = b; 
	b = c;
	c = t;
}

void bubbleSort(int a[], int n){
	for(int i=0; i<n; i++){
		for(int j=n-1; j>0; j--){
			if(i<j){
				if(a[j] < a[j-1])
					swap(a[j], a[j-1]);
			}else{
				break;
			}
		}
	}
}

main() {
	int arr[] = {3, 2, 8, 9, 0, 1, 6, 10, 7, 5, 4};
	bubbleSort(arr, 10);
	for(int i=0; i<10; i++){
		printf("%d	", arr[i]);
	}
}
