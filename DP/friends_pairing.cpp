#include <bits/stdc++.h>
using namespace std;

int get_num(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;

	return get_num(n-1)+(n-1)*get_num(n-2);
}

int main()
{
	int n;
	cin>>n;

	cout<<get_num(n);
	return 0;
}