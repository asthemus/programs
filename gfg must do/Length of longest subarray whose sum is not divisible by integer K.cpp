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
     int arr[] = {6, 3, 12, 15}, k = 3;
     int n = sizeof(arr)/sizeof(arr[0]);
     int sum = 0;
     int left = -1, right = -1;
     for(int i=0;i<n;i++)
     {
          if(arr[i]%k != 0)
          {
               if(left == -1)
                    left = i;
               right = i;
          }
          sum += arr[i];
     }
     if(sum%k != 0)
          cout<<n;
     else if(left == -1)
          cout<<-1;
     else
          cout<<max(n-left-1,right);
     return 0;
}
