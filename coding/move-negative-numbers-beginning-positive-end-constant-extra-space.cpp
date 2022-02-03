#include <iostream>
using namespace std;

void rearrange(int arr[], int n){
	int start = 0;
	int end = n-1;
	while(start<end){
		if(arr[start] < 0)
			start++;
		else {
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			end--;
		}
	}
}

int main(){
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int len = sizeof(arr)/sizeof(arr[0]);
	rearrange(arr, len);
	for(int i=0;i<len;i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}