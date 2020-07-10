#include <bits/stdc++.h>
using namespace std;

int ncrmod(int ni,int ri, p)
{
	if(ni<ri || ni<=0 || ri<0)
		return 0;

	if(ri==1)
		return ni;		

	return (reminder(ni-1,ri,p)%p + reminder(ni-1,ri-1,p)%p)%p;
	
}

int ncrmodlucas(int n,int r,int p)
{
	if(r==0)
		return 0;
	int ni = n%p, ri = r%p;

	return (ncrmodlucas(n/p,r/p,p)*ncrmod(ni,ri,p))%p;
}

int main()
{
	int n=20;
	int r=18;
	int p=13;

	cout<<ncrmodlucas(n,r,p);
}