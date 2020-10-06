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
     int n,k,t1;
     cin>>n>>k;
     vec cost;
     vec pages;
     for(int i=0;i<n;i++){
          scanf("%lld",&t1);
          cost.pbc(t1);
     }
     for(int i=0;i<n;i++){
          scanf("%lld",&t1);
          pages.pbc(t1);
     }
     vec dp1(k+1, 0);
     vec dp2(k+1, 0);
     for(int i=1;i<=n;i++){
          int cost_book = cost[i-1];
          for(int j=0;j<=k;j++){
               if(j<cost_book)
                    dp1[j] = dp2[j];
               else
                    dp1[j] = max(dp2[j], dp2[j-cost_book]+pages[i-1]);
          }
          dp1.swap(dp2);
     }
     cout<<dp2[k];
     return 0;
}
