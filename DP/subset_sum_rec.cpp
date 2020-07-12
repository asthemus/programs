#include <bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono; 

auto start = high_resolution_clock::now(); 

bool issum(int arr[],int sum,int n)
{
	
	if(sum==0)
		return true;

	if(n==0 && sum!=0)
		return false;

	if (arr[n-1] > sum) 
     return issum(arr,sum,n-1); 

	return issum(arr,sum-arr[n-1],n-1)||issum(arr,sum,n-1);
}

int main()
{
	int arr[] = {3,34,4,12,5,2};
	int sum = 9;
	int size = 6;

	if(issum(arr,sum,size)==true)
		cout<<"found a subset";
	else
		cout<<"no subset found";

	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << duration.count() << endl; 
	return 0;
}