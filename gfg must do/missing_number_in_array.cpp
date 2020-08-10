//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
//18 may 

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,temp,flag=0;
		cin>>n;
		int arr[n+1]={0};
		for(int i=0;i<n-1;i++)
		{
			cin>>temp;
			arr[temp]=1;	
		}
		for(int i=1;i<=n;i++)
		{
			if(arr[i]==0)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}		