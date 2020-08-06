#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define twod vector<vector<int>>
#define mp make_pair
#define pbc push_back
#define all(a) a.begin(),a.end()
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

int32_t main()
{
     int n,k;
     cin>>n>>k;
     vec arr;
     for(int i=0;i<n;i++){
          int temp;
          cin>>temp;
          arr.push_back(temp);
     }
     vec dp(n,INT_MAX);
     dp[0]=0;
     for(int i=0;i<n-1;i++){
          for(int j=1;j<=k;j++){
               if(i+j <n)
                    dp[i+j] = min(dp[i+j],dp[i] + abs(arr[i+j] - arr[i]));
          }
     }
     cout<<dp[n-1]<<endl;
}
