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

int32_t main(){
     int n,k;
     cin>>n>>k;
     if(n == 1){
          cout<<1;
          return 0;
     }
     if(n == 2){
          cout<<2;
          return 0;
     }
     twod dp(n+1, vec (k+1,0));
     dp[1][0] = 1;
     dp[2][0] = 1;
     if(k != 0)
          dp[3][1] = 1;
     for(int i=1;i<n;i++){
          for(int j=0;j<=k;j++){
               if(dp[i][j] !=0){
                    if(i+1<=n)      dp[i+1][j] = (dp[i+1][j] + dp[i][j]%mod)%mod;
                    if(i+2<=n)      dp[i+2][j] = (dp[i+2][j] + dp[i][j]%mod)%mod;
                    if(i+3<=n && j+1<=k)  dp[i+3][j+1] = (dp[i+3][j+1] + dp[i][j]%mod)%mod;
               }
          }
     }
     int count = 0;
     for(int i=0;i<=k;i++)
          count = (count + dp[n][i]%mod)%mod;
     cout<<count;
     return 0;
}
