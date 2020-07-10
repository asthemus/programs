#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define twod vector<vector<int>>
#define all(a) a.begin(),a.end()
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

int findways(int *ways[10001], int n,int num,int cnt)
{
     if(ways[num]!=0)
          return ways[num];
     if(num>n)
          return INT_MAX;
     if(num==n)
          return cnt;
     int add = findways(ways,n,num+1,cnt+1);
     int dob=INT_MAX;
     if(num!=0)
          dob = findways(ways,n,2*num,cnt+1);
     ways[num] = min(add,dob);
     return ways[num];
}

int32_t main()
{
	istream;
     int t,n;
     scanf("%lld", &t);
     int ways[10001][10001];
     while(t--)
     {
          scanf("%lld", &n);
          cout<<findways(ways,n,0,0)<<endl;
     }
     return 0;
}
