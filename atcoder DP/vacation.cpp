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
     int n;
     cin>>n;
     twod grid(n, vec (3,0));
     for(int i=0;i<n;i++){
          int t1,t2,t3;
          cin>>t1>>t2>>t3;
          grid[i][0] = t1;
          grid[i][1] = t2;
          grid[i][2] = t3;
     }
     for(int i=1;i<n;i++){
          grid[i][0] += max(grid[i-1][1],grid[i-1][2]);
          grid[i][1] += max(grid[i-1][0],grid[i-1][2]);
          grid[i][2] += max(grid[i-1][0],grid[i-1][1]);
     }
     cout<<*max_element(grid[n-1].begin(), grid[n-1].end());
     return 0;
}
