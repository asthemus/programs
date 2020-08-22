//https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
//18 may

//largest contiguous sum algorithm modified

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,max_so_far=0,max_ending_here=0,flag=0,max=-10000001;
		cin>>n;
		long long int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]>=max)
				max=arr[i];
		}
		for(int i=0;i<n;i++)
		{
			max_ending_here=max_ending_here+arr[i];
			if(max_ending_here<0)
				
				max_ending_here=0;
			if(max_ending_here>max_so_far)
			{
				max_so_far=max_ending_here;
				flag=1;
			}
		}
		if(flag==0)
			cout<<max<<endl;
		else
			cout<<max_so_far<<endl;
	}
	return 0;
}