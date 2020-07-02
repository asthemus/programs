//https://practice.geeksforgeeks.org/problems/equilibrium-point/0
//19 may

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,flag;
	cin>>t;
	while(t--)
	{	
		flag=0;
		int n,temp;
		cin>>n;
		int sumarr[n+1];
		sumarr[0]=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			sumarr[i+1]=sumarr[i]+temp;
		}
		for(int i=0;i<n;i++)
		{
			if((sumarr[n]-sumarr[i+1])==(sumarr[i])){
				cout<<i+1<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<-1<<endl;
	}
}