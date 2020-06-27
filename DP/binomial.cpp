#include <bits/stdc++.h>
using namespace std;

int binomial(int n,int k)
{
	if(n<=0||k<=0)
		return 0;
	if(k==0||k==n)
		return 1;

	return binomial(n-1,k)+binomial(n-1,k-1);
}

int main()
{
	int n=10,k=2;

	cout<<binomial(n,k);
	return 0;
}