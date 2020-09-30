#include <bits/stdc++.h>
using namespace std;

int main(){
     string s;
     cin>>s;
     int m = s.size();
     int n,t1;
     vector<int> start,end,subs;
     cin>>n;
     for(int i=0;i<n;i++){
          cin>>t1;
          start.push_back(t1);
     }
     for(int i=0;i<n;i++){
          cin>>t1;
          end.push_back(t1);
     }
     for(int i=0;i<n;i++){
          cin>>t1;
          subs.push_back(t1);
     }
     vector<vector<int>> dp(m, vector<int> (m,0));
     for(int i=0;i<m;i++){
          for(int j=i;j>=0;j--){
               if(i == j)
                    dp[i][j] = 0;
               else if(i-j==1){
                    if(s[i] == s[j])    dp[i][j] = 0;
                    else                dp[i][j] = 1;
               }
               else{
                    if(s[i] == s[j])    dp[i][j] = dp[i-1][j+1];
                    else                dp[i][j] = 1+dp[i-1][j+1];
               }
          }
     }
     for(int i=0;i<m;i++){
          for(int j=0;j<m;j++)
               cout<<dp[i][j]<<" ";
          cout<<endl;
     }
     string res = "";
     for(int i=0;i<n;i++){
          if(dp[end[i]][start[i]] <= subs[i])
               res = res+"1";
          else
               res = res+"0";
     }
     cout<<res;
     return 0;
}
