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
     int sumval = 0;
     for(int i=0;i<n;i++){
          int t1,t2;
          scanf("%lld%lld",&t1,&t2);
          wts.pbc(t1);
          vals.pbc(t2);
          sumval+=vals[i];
     }
     vec knapsack(sumval+1,INT_MAX);
     knapsack[0]=0;
     for(int i=0;i<n;i++){
          int val = vals[i];
          for(int j=sumval-val;j >= 0;j--){
               knapsack[j+val] = min(knapsack[j]+wts[i],knapsack[j+val]);

          }
     }
     int ans = 0;
     for(int i=0;i<=sumval;i++){
          if(knapsack[i]<=w)
               ans = max(ans, i);
     }
     cout<<ans;
     return 0;
}
