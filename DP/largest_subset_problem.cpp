#include <bits/stdc++.h>
using namespace std;

int largest_sub(vector<int> vc,int n)
{
	sort(vc.begin(),vc.begin()+n);
	vector<int> dp(n,1);
	int mix;
	for(int i=n-2;i>=0;i--)
	{
		mix=0;
		for(int j=i+1;j<n;j++)
		{
			if(vc[j]%vc[i]==0)
				mix = max(mix,dp[j]); 
		}
		dp[i] = dp[i] + mix;
	}
	mix = 0;
	for(int i=0;i<n;i++)
		mix = max(mix,dp[i]);
	return mix;
}

int main()
{
	vector<int> vc{10, 5, 3, 15, 20};
	int n = vc.size();
	cout<<largest_sub(vc,n);
	return 0;
}