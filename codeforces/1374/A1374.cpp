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
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";


int32_t main()
{
	istream;
	int t, n, x, y;
	scanf("%lld", &t);
	while(t--)
	{
          scanf("%lld%lld%lld",&x,&y,&n);
          int temp = n;
          if(x==0||n==0)
          {
               cout<<0<<endl;
               continue;
          }
          if(n%x==y)
          {
               cout<<n<<endl;
               continue;
          }
          n = n - (n%x);
          if(n+y<=temp)
               cout<<n+y<<endl;
          else if(n-(x-y)>0 && n-(x-y)<temp)
               cout<<n-(x-y)<<endl;
          else cout<<0<<endl;
     }
	return 0;
}
