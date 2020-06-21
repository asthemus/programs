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

bool isprime(int n)
{
     for(int i=2;i<=sqrt(n);i++)
     {
          if(n%i==0)
               return false;
     }
     return true;
}

int32_t main()
{
	istream;
	int t, n;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld",&n);
          if(n==1)            cout<<"FastestFinger"<<endl;
          else if(n==2)       cout<<"Ashishgup"<<endl;
          else if(n%2==1)     cout<<"Ashishgup"<<endl;
          else
          {
               int count=0;
               while(n%2==0 && n>=2)
               {
                    n=n/2;
                    count++;
               }
               if(n==1)            cout<<"FastestFinger"<<endl;
               else
               {
                    if(isprime(n) && count<=1) cout<<"FastestFinger"<<endl;
                    else           cout<<"Ashishgup"<<endl;
               }
          }

     }
	return 0;
}
