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

int getcnt(vector<int> A, vector<int> B)
{
	int res=0;
	for(int i=0;i<A.size();i++)
	{
		if(A[i]==0)
			res++;
	}
	for(int i=0;i<B.size();i++)
	{
		if(B[i]==0)
			res++;
	}
	return res;
}

int32_t main()
{
	istream;
	int t,temp,count;
	scanf("%lld" ,&t);
	while(t--)
	{
		int n,m;
		scanf("%lld%lld",&n,&m);
		int ones=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%lld", &temp);
				ones = ones+temp;
			}
		}
		if(ones%4==0)
			cout<<"Vivek"<<endl;
		else
			cout<<"Ashish"<<endl;
	}
	return 0;
}


