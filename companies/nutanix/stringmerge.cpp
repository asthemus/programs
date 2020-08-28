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
     vector<string> strs;
     for(int i=0;i<n;i++){
          string temp;
          cin>>temp;
          strs.push_back(temp);
     }
     twod dp(26, vec(26,0));
     int maxsize = 0;
     for(int i=0;i<n;i++){
           int size = strs[i].size();
           maxsize = max(maxsize,size);
           int indexs = strs[i][0] - 'a';
           int indexe = strs[i][size-1] - 'a';
           for(int j=0;j<26;j++){
                if(j == indexs)
                    dp[j][indexe] = max(dp[j][indexe],size+dp[j][indexs]);
                if(dp[j][indexs]!=0)
                    dp[j][indexe] = max(dp[j][indexe] , size + dp[j][indexs]);
           }
     }
     int maxi = 0;
     for(int i=0;i<26;i++){
          if(dp[i][i]>maxsize)
               maxi = max(maxi,dp[i][i]);
     }
     cout<<maxi;
     return 0;
}
