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
	int t, n, k;
	scanf("%lld", &t);
	while(t--)
	{
          int x=0;
          scanf("%lld%lld",&n,&k);
          multiset<int,greater<int>> ms={};
          for(int i=0;i<n;i++)
          {
               int temp;
               scanf("%lld",&temp);
               if(temp%k != 0)
                    ms.insert(temp%k);
          }
          if(ms.begin()==ms.end())
          {
               cout<<0<<endl;
               continue;
          }
          while(ms.begin()!=ms.end())
          {
               int flag=0;
               for(auto itr = ms.begin();itr!=ms.end();itr++)
               {

                    if((*itr+x)%k == 0)
                    {
                         ms.erase(itr);
                         flag=1;
                         x++;
                         break;
                    }
               }
               if(flag==0)    x++;
          }
          cout<<x<<endl;
     }
	return 0;
}
