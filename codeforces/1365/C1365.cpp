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
	int n,temp,ans=INT_MIN;
	scanf("%lld" ,&n);
	vec vc1(n+1,0);
	vec vc2(n+1,0);
	vec diff(n+1,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&temp);
		vc1[temp] = i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&temp);
		vc2[temp] = i;
	}
	for(int i=1;i<=n;i++)
	{
		temp = vc1[i]-vc2[i];
		if(temp<0)
			temp=temp+n;
		diff[temp]++;
	}

	for(int i=0;i<=n;i++)
	{
		ans = max(ans,diff[i]);
	}
	cout<<ans<<endl;
	return 0;
}


