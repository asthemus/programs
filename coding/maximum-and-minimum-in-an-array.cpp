#include <iostream>
using namespace std;

int* minandmax(int arr[], int len){
	if(len == 0 )	return NULL;
	int min = arr[0];
	int max = arr[0];
	if(len%2 == 0){
		if(arr[1] < arr[0])
			min = arr[1];
		else
			max = arr[1];
	}
	for(int i=2;i<len;i+=2){
		int localmin = arr[i];
		int localmax = arr[i];
		if(arr[i] < arr[i+1])
			localmax = arr[i+1];
		else
			localmin = arr[i+1];
		if(localmax > max)
			max = localmax;
		if(localmin < min)
			min = localmin;
	}
	static int retarr[2];
	retarr[0] = min;
	retarr[1] = max;
	return retarr;
}

int main(){
	int arr[] = {1,10,11,13,0,-1,-5,31};
	int len = sizeof(arr)/sizeof(arr[0]);
	int* retarr = minandmax(arr, len);
	for(int i=0;i<2;i++)
		cout<<retarr[i]<<' ';
	return 0;
}