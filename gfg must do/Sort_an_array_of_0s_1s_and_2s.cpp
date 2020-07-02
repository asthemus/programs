//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
//18 may

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,temp;
		map <int,int> mp;
		map <int,int> :: iterator itr; 
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			mp[temp]++;
		}
		for(itr = mp.begin();itr!=mp.end();itr++)
		{
			int x = itr->first;
			int y = itr->second;
			for(int j=0;j<y;j++)
			{
				cout<<x<<' ';
			}
		}
		cout<<endl;
	}
}