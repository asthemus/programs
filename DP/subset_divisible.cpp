#include <bits/stdc++.h>
using namespace std;

bool isdiv(int arr[],int n,int m,int sum)
{

	if(sum!=0 && sum%m==0)
		return true;

	if(n==0)
		return false;

	cout<<sum<<" ";
	return isdiv(arr,n-1,m,sum-arr[n-1])||isdiv(arr,n-1,m,sum);

}

int main()
{

	int arr[] = {1,6};
	int n = 2;
	int m = 5;
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+arr[i];

	if(isdiv(arr,n,m,sum))
		cout<<"found a subset";
	else
		cout<<"no subset found";
	return 0;

}