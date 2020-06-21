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
	int t, n, temp, oddlen;
     vec even;
     vec odd;
     vec res;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld",&n);
		even={};odd={};res={};
          for(int i=0;i<2*n;i++)
          {
               scanf("%lld",&temp);
               if(temp%2==1)
                    odd.push_back(i+1);
               else even.push_back(i+1);
          }
          oddlen = odd.size();
          if(oddlen%2==1)
          {
               odd.pop_back();
               even.pop_back();
               int k=0,l=0;
               while(k<odd.size())
               {
                    cout<<odd[k]<<" "<<odd[k+1]<<endl;
                    k+=2;
               }
               while(l<even.size())
               {
                    cout<<even[l]<<" "<<even[l+1]<<endl;
                    l+=2;
               }
          }
          else
          {
               if(odd.size()>=2)
               {
                    odd.pop_back();
                    odd.pop_back();
               }
               else
               {
                    even.pop_back();
                    even.pop_back();
               }

               /*for(auto itr=odd.begin();itr!=odd.end();itr++)
                    cout<<*itr<<endl;
               for(auto itr=even.begin();itr!=even.end();itr++)
                    cout<<*itr<<endl;*/
               int k=0,l=0;
               while(k<odd.size())
               {
                    cout<<odd[k]<<" "<<odd[k+1]<<endl;
                    k+=2;
               }
               while(l<even.size())
               {
                    cout<<even[l]<<" "<<even[l+1]<<endl;
                    l+=2;
               }
          }
          continue;
	}
	return 0;
}
