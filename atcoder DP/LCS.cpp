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
     string s,t;
     cin>>s>>t;
     int n = s.size();
     int m = t.size();
     if(!n || !m){
          cout<<"";
          return 0;
     }
     vector<vector<int>> dp(n+1, vector<int> (m+1,0));
     int len=0;
     int row,col;
     for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
               if(i==0 || j==0)
                    dp[i][j] = 0;
               else{
                    if(s[i-1] == t[j-1])
                         dp[i][j] = dp[i-1][j-1]+1;
                    else
                         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
               }
          }
     }
     string res = "";
     int i=n,j=m;
     while(i>0 && j>0){
          if(s[i-1] == t[j-1]){
               res = s[i-1]+res;
               i--; j--;
          }
          else if(dp[i][j-1]>dp[i-1][j])
               j--;
          else
               i--;
     }
     cout<<res;
     return 0;
}
