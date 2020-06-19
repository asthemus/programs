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
	int t, n, x,temp,maxi;
	scanf("%lld", &t);
	while(t--)
	{
		temp=0;
		scanf("%lld%lld", &n,&x);
		int nvc[n];
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&nvc[i]);
			temp = temp + nvc[i];
			nvc[i] = temp % x;
		}
		maxi=-1;
		for(int i=0;i<n;i++)
		{
			if(nvc[i]!=0)
			{
				maxi = max(maxi,max(i+1,n-i-1));
			}
		}
		if(maxi==-1)
			cout<<-1<<endl;
		else
			cout<<maxi<<endl;
	}
	return 0;
}


