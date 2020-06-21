#include <bits/stdc++.h>
using namespace std;

int DP[1001][100001]={0};

int knapsack(int price[], int pages[], int n, int maxprice)
{
     int take=0,donttake=0;
     if(DP[n][maxprice]!=0)
          return DP[n][maxprice];

     if(n==0)
     {
          if(price[n]<=maxprice)
          {
               DP[n][maxprice] = pages[0];
               return DP[n][maxprice];
          }
          DP[n][maxprice]=0;
          return 0;
     }
     if(price[n]<=maxprice)
          take = pages[n] + knapsack(price,pages,n-1,maxprice-price[n]);

     donttake = knapsack(price,pages,n-1,maxprice);
     DP[n][maxprice] = max(take,donttake);
     return DP[n][maxprice];


}

int main()
{
     int n,x,temp;
     cin>>n>>x;
     int price[n];
     int pages[n];
     for(int i=0;i<n;i++)
     {
          cin>>price[i];
     }
     for(int i=0;i<n;i++)
     {
          cin>>pages[i];
     }
     cout<<knapsack(price,pages,n-1,x);
}
