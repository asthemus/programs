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
	int t, n;
	scanf("%lld", &t);
	while(t--)
	{
          int cnt = 0;
          scanf("%lld",&n);
          while(true)
          {
               if(n!=1 && n%3!=0)
               {
                    cout<<-1<<endl;
                    break;
               }
               while(n%6==0)
               {
                    n=n/6;
                    cnt++;
               }
               if(n==1)
               {
                    cout<<cnt<<endl;
                    break;
               }
               else
               {
                    n=2*n;
                    cnt++;
               }
          }
     }
	return 0;
}
