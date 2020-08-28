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
     vec arr = {1,3,2,4,5};
     int n = arr.size();
     int rsum = 0,sum=0;
     for(int i=0;i<n;i++)
          rsum+=arr[i];
     sum=rsum/2;
     sort(all(arr));
     vector<vector<bool>> dp(sum+1, vector<bool> (n,false));
     for(int i=0;i<n;i++)
          dp[0][i] = true;
     dp[arr[0]][0] = true;
     for(int i=1;i<n;i++){
          for(int j=1;j<=sum;j++){
               if(j<arr[i])
                    dp[j][i] = dp[j][i-1];
               else
                    dp[j][i] = dp[j][i-1]||dp[j-arr[i]][i-1];
          }
     }
     for(int i=sum;i>=0;i--)
          if(dp[i][n-1]){
               cout<<max(i,rsum-i);
               break;
          }
     return 0;
}
