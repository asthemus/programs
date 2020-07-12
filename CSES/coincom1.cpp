#include <unistd.h>
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
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

int32_t main()
{
	istream;
	int n,x,temp;
	scanf("%lld%lld", &n,&x);
     vector<int> coins;
     vector<int> dp(x+1,0);
     dp[0] = 1;
     for(int i=0;i<n;i++)
     {
          scanf("%lld" ,&temp);
          coins.push_back(temp);
     }
     sort(all(coins));
     for(int i=coins[0];i<=x;i++)
     {
          for(int j=0;j<n && coins[j]<=i;j++)
               dp[i] = (dp[i]+dp[i-coins[j]]%mod)%mod;
     }
     cout<<dp[x];
     return 0;
}
