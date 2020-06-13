#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define all(a) a.begin(),a.end()
#define twod vector<vector<int>>

int32_t main()
{
	istream;
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		uint n,tempx,res=0;
		scanf("%llu",&n);
		while(n>0)
		{
			res = res +n;
			n=n/2;
		}
		printf("%llu\n" ,res);
	}	
	return 0;
}
