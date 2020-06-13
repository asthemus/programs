#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define all(a) a.begin(),a.end()
#define twod vector<vector<int>>
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";

bool comp(int a,int b)
{
	return a>b;
}

int32_t main()
{
	istream;
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		set<int,greater<int>> st;
		set<int,greater<int>>::iterator itr; 
		set<int,greater<int>>::iterator itr2; 
		int n,temp,temp2,max;
		scanf("%lld", &n);
		vec vc(n,0);
		for(int i=0;i<n;i++)
		{
			scanf("%lld", &temp);
			st.insert(temp);
		}
		int flag=0;
		for(int j=1;j<=1024;j++)
		{
			flag=0;
			set<int,greater<int>> st1;
			for(itr=st.begin();itr!=st.end();itr++)
			{
				temp = *itr;
				st1.insert(temp^j);
			}
			itr2 = st.begin();
			for(itr=st1.begin();itr!=st1.end();itr++)
			{
				if(*itr2 != *itr)
				{
					flag=1;
					break;
				}
				itr2++;
			}
			if(flag==0)
			{
				cout<<j<<endl;
				break;
			}
		}
		if(flag==1)
			cout<<-1<<endl;
	}	
	return 0;
}


