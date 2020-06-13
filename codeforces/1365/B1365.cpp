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
	int t,n,z,o;
	scanf("%lld" ,&t);
	while(t--)
	{
		z=0,o=0;
		int flag=1;
		scanf("%lld",&n);
		int arr[n];
		int typearr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%lld", &arr[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lld", &typearr[i]);
		}
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(typearr[i]==0)
				z++;
			else
				o++;
		}
		if(z!=n && o!=n)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}


