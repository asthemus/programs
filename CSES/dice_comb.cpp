#include <bits/stdc++.h>
using namespace std;

int ways[1000000];

int getways(int n)
{	

	if(n<=0)
		return 0;
	if(n==1)
		return ways[0];
	if(n<=6)
	{
		int temp = 0;
		for(int j=0;j<n-1;j++)
		{
			if(ways[j]!=-1)
				temp = temp + ways[j];
			else
				temp = temp + getways(j+1);
		}
		ways[n-1] = temp+1;
		return temp+1;
	}
	else
	{
		int temp = 0;
		for(int j=n-7;j<n-1;j++)
		{
			if(ways[j]!=-1)
				temp = (temp + ways[j]%1000000007)%1000000007;
			else
				temp = (temp + getways(j+1)%1000000007)%1000000007;
		}
		ways[n-1]=temp;
		return temp;
	}
	return 0;
}

int main()
{	
	int n;
	cin>>n;
	for(int i=0;i<n+2;i++)
		ways[i]=-1;
	ways[0]=1;
	cout<<getways(n);
	return 0;
}