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
     twod matrix  = {{1, 1, 1, 1}
                    ,{2, 2, 2, 2}
                    ,{3, 3, 3, 3}};
     int n = matrix.size();
     int m = matrix[0].size();
     twod tp(m, vec (n,0));
     for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
               tp[j][i] = matrix[i][j];
     for(int i=0;i<m;i++){
          for(int j=0;j<n;j++)
               cout<<tp[i][j]<<" ";
          cout<<endl;
     }
     return 0;
}
