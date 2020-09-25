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
     int n;
     cin>>n;
     vector<int> stairs(n,0);
     for(int i=0;i<n;i++)
          cin>>stairs[i];
      if(n==0){
           cout<<0;
           return 0;
      }
      if(n==1){
           cout<<stairs[0];
           return 0;
      }
     vector<int> dp(n+1, INT_MAX);
     dp[0] = 0;
     dp[2] = stairs[0];
     for(int i=1;i<=n;i++){
          if(i+1<=n)
               dp[i] = min(dp[i], dp[i+1] + stairs[i+1]);
          if(i+2<=n)
               dp[i+2] = dp[i] + stairs[i];
     }
     cout<<min(dp[n],dp[n-1]+stairs[n-1]);
     return 0;
}
