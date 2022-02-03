#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+1];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int low = 0;
	int high = n-1;
	int mid = 0;
	while(mid<=high){
		if(arr[mid] == 0)
			swap(arr, mid++, low++);
		else if(arr[mid] == 1)
			mid++;
		else
			swap(arr, mid, high--);
	}
	for(int i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}