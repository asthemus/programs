#include <unistd.h>
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


int32_t main()
{
	istream;
	int t, n,r;
	scanf("%lld", &t);
	while(t--)
	{
          scanf("%lld%lld", &n,&r);
          int res=0;
          if(n==1)
          {
               cout<<1<<endl;
               break;
          }
          if(n>r)
          {
               if(r%2==0)
                    res += (r/2)*(r+1);
               else
                    res += r*((r+1)/2);
          }
          else
          {
               if(n%2==0)
                    res += (n-1)*(n/2) + 1;
               else
                    res += ((n-1)/2)*n + 1;
          }
          cout<<res<<endl;
     }
	return 0;
}
