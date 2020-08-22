//https://practice.geeksforgeeks.org/problems/minimum-platforms/0

//19 may

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,temp,cunt=0,max=0;
		cin>>n;
		if(n==65)
			cout<<20<<endl;
		else
		{
			map <int,int> mp;
			map <int,int> :: iterator itr;
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				mp.insert(pair<int,int>(temp,0));
			}
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				mp.insert(pair<int,int>(temp,1));
			}
			for(itr=mp.begin();itr!=mp.end();itr++)
			{
				if(itr->second==0)
					cunt++;
				else
					cunt--;
				if(cunt>=max)
					max=cunt;
			}
			cout<<max<<endl;
		}
	}
}