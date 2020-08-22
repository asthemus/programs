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
     scanf("%lld%lld" , &n, &k);
     vec arr;
     for(int i=0;i<n;i++){
          scanf("%lld", &t1);
          arr.pbc(t1);
     }
     sort(all(arr));
     int sum=0;
     for(int i=0;i<n;i++){
          sum += arr[i];
          arr[i] = sum/(i+1);
     }
     for(int i=0;i<k;i++){
          scanf("%lld", &t1);
          cout<<(lower_bound(all(arr),t1) - arr.begin());
     }
     return 0;
}
