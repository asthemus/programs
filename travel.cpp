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
     int t;
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     cin>>t;
     for(int k=1;k<=t;k++)
     {
          cout<<"Case #"<<k<<":"<<endl;
          int n;
          cin>>n;
          vector<vector<char>> grid(n, vector<char> (n,'Y'));
          string incoming, outgoing;
          cin>>incoming;
          cin>>outgoing;
          for(int i=0;i<n;i++)
          {
               for(int j=i;j<n;j++)
               {
                    if(i==j)
                         continue;
                    else
                    {
                         if(grid[i][j-1] == 'N')
                              grid[i][j] = 'N';
                         else if(outgoing[j-1] == 'N' || incoming[j] == 'N')
                              grid[i][j] = 'N';
                    }
               }
          }
          for(int i=n-1;i>=0;i--)
          {
               for(int j=i;j>=0;j--)
               {
                    if(i==j)
                         continue;
                    else
                    {
                         if(grid[i][j+1] == 'N')
                              grid[i][j] = 'N';
                         else if(outgoing[j+1] == 'N' || incoming[j] == 'N')
                              grid[i][j] = 'N';
                    }
               }
          }
          for(int i=0;i<n;i++)
          {
               for(int j=0;j<n;j++)
                    cout<<grid[i][j];
               cout<<endl;
          }
     }
}
