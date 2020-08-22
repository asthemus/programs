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
     int arr[] = {5, 7, 1, 1, 2, 4, 4, 4, 5, 5, 4, 5, 8, 9}, K = 1;
     int n = sizeof(arr)/sizeof(arr[0]);
     int ret = -1;
     map<int,int> mp;
     for(int i=0;i<n;i++)
          mp[arr[i]]++;
     auto itr1 = mp.begin();
     auto itr2 = mp.begin();
     itr2++;
     while(itr2 != mp.end())
     {
          debug2(itr1->first, itr1->second);
          debug2(itr2->first, itr2->second);
          if(itr2->first - itr1->first == K)
               ret = max(ret,itr2->second + itr1->second);
          debug1(ret);
          itr1++;
          itr2++;
     }
     cout<<ret;
     return 0;
}
