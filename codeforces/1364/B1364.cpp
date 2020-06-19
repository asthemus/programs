#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define twod vector<vector<int>>
#define all(a) a.begin(),a.end()
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";


int32_t main()
{
	istream;
	int t,temp,n;
	scanf("%lld", &t);
	while(t--)
	{
		vec nvc,sortvc;
		scanf("%lld", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			nvc.push_back(temp);
		}
		sortvc.push_back(nvc[0]);
		for(int i=1;i<n-1;i++)
		{
			if(nvc[i]<nvc[i-1] && nvc[i]<nvc[i+1])
				sortvc.push_back(nvc[i]);
			if(nvc[i]>nvc[i-1] && nvc[i]>nvc[i+1])
				sortvc.push_back(nvc[i]);
		}
		sortvc.push_back(nvc[n-1]);
		cout<<sortvc.size()<<endl;
		for(int i=0;i<sortvc.size();i++)
		{
			cout<<sortvc[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}




