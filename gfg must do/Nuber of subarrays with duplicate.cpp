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
     vec arr = {1,2,1,3,1};
     int n = arr.size();
     int ret = 0;
     unordered_map<int,int> mp;
     int j=-1;
     for(int i=0;i<n;i++)
     {
          mp[arr[i]]++;
          if(mp[arr[i]] >= 2)
          {
               j++;
               while(arr[j] != arr[i])
               {
                    mp[arr[j]]--;
                    j++;
               }
               mp[arr[j]]--;
               ret += (i-j);
          }
          else
               ret += (i-j);
     }
     cout<<(n*(n+1)/2) - ret;
     return 0;
}
