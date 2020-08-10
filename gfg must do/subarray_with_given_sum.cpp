//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

//used two pointer technique
//18 may 2019

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,s,flag;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		long int A[n],sumarr[n+1];
		cin>>A[0];
		sumarr[0]=0;
		sumarr[1]=A[0];
		for(int i=1;i<n;i++)
		{
			cin>>A[i];
			sumarr[i+1]=sumarr[i]+A[i];
		}
		int i=0,j=1;
		while(j<=n)
		{
			flag=0;
			if(sumarr[j]-sumarr[i]<s)
			{
				j++;
			}
			else if (sumarr[j]-sumarr[i]>s)
			{
				i++;
			}
			else{
				cout<<i+1<<' '<<j<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)cout<<-1<<endl;
	}
	return 0;
}