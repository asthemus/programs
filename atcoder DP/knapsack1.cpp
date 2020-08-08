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
     int n,w;
     scanf("%lld%lld",&n,&w);
     vec wts;
     vec vals;
     for(int i=0;i<n;i++){
          int t1,t2;
          scanf("%lld%lld",&t1,&t2);
          wts.pbc(t1);
          vals.pbc(t2);
     }
     twod knapsack(w+1, vec (n+1, 0));
     for(int i=1;i<=n;i++){
          int wt = wts[i-1];
          for(int j=1;j<=w;j++){
               if(j<wt)
                    knapsack[j][i] = knapsack[j][i-1];
               else
                    knapsack[j][i] = max(knapsack[j][i-1],knapsack[j-wt][i-1]+vals[i-1]);
          }
     }
     cout<<knapsack[w][n];
     return 0;
}
