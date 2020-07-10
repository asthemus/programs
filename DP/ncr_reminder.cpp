#include <bits/stdc++.h>
using namespace std;

int reminder(int ni, int ri, int p)
{	
	if(ni<ri || ni<=0 || ri<0)
		return 0;

	if(ri==1)
		return ni;		

	return (reminder(ni-1,ri,p)%p + reminder(ni-1,ri-1,p)%p)%p;
	
}

int main()
{
	int n = 10;
	int r = 2;
	int p = 13;

	cout << reminder(n,r,p)<<endl;
	return 0;
}

