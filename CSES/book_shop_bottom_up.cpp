#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,x;
     cin>>n>>x;
     int DP[n+1][x+1]={0};
     int prices[1001],pages[100001];
     for(int i=0;i<n;i++)
          cin>>prices[i];
     for(int i=0;i<n;i++)
          cin>>pages[i];

     for(int i=0;i<=n;i++)
     {
          for(int j=0;j<=x;j++)
          {
               if(i==0||j==0)
               {
                    DP[i][j]=0;
                    continue;
               }
               if(prices[i-1]<=j)
               {
                    DP[i][j] = max(DP[i-1][j],pages[i-1]+DP[i-1][j-prices[i-1]]);
               }
               else
                    DP[i][j] = DP[i-1][j];
          }
     }
     cout<<DP[n][x];
     return 0;
}
