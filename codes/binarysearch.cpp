#include <bits/stdc++.h>
using namespace std;


bool comp(int a, int b){
	return !(a>b);
}
int bsearch(vector<int> &vc, int l, int start,int end)
{
	if(start>end)
		return -1;
	int mid = (start+end)/2;
	if(vc[mid]==l)
		return mid;
	if(l>vc[mid])
		return bsearch(vc,l,mid+1,end);
	if(l<vc[mid])
		return bsearch(vc,l,start,mid-1);
	
}

int main()
{
	vector<int> vc = {0,2,6,11,12,18,34,34,34,45,55,99};
	int n = vc.size();
	sort(vc.begin(),vc.end(),comp);
	cout<<bsearch(vc,18,0,n-1);
	return 0;
}