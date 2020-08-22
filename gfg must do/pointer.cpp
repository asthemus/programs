#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int start,int mid,int end){
	//create a temp array
	int temp[end-start+1];

	int i=start,j=mid+1,k=0;

	while(i<=start && j<=end){
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			k++;
			i++;
		}
		else{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}

	while(i<=mid){
		temp[k]=arr[i];
		k++;
		i++;
	}
	while(j<=end){
		temp[k]=arr[j];
		k++;
		j++;
	}

	for(i = start; i <= end; i += 1) {
		arr[i] = temp[i - start];
	}

}

void mergesort(int arr[],int start,int end){

	if(start < end) {
		int mid = (start + end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main(){
	
	int arr[] = {12, 11, 13, 5, 6, 7};
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	mergesort(arr,0,5);
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
}

