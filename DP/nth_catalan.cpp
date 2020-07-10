#include <bits/stdc++.h>
using namespace std;

int gen_cat(int n)
{
	int arr[10];
	arr[0]=1,arr[1]=1;
	arr[n]=0;
	for(int i=0;i<n;i++)
	{
		arr[n]=arr[n]+arr[i]*arr[n-i-1];
	}
	return arr[n];
}

int catalan(int* cat)
{
	cat[0]=1;
	cat[1]=1;
	for(int i=2;i<10;i++)
		cat[i]=gen_cat(i);
	return 0;
}

int main()
{
	int cat[1000];
	catalan(cat);
	cout<<cat[9];
	return 0;
}