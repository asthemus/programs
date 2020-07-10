#include <bits/stdc++.h>
using namespace std;

int count = 0;
void print(vector<int> p)
{
	for(int i=0;i<p.size();i++)
		cout<<p[i]<<"  ";
	cout<<endl;
		
}

int print_subsets(bool dp[1000][1000], vector<int> vc, int i,int sum, vector<int> p)
{	
	if(i==0 && sum!=0)
	{
		return 0;
	}

	if(sum==0)
	{
		print(p);
		return 0;
	}

	if(dp[i-1][sum])
	{	
		print_subsets(dp,vc,i-1,sum,p);
	}

	if(sum >= vc[i-1] && dp[i-1][sum-vc[i-1]])
	{	
		p.push_back(vc[i-1]);
		print_subsets(dp,vc,i-1,sum-vc[i-1],p);
	}
}

int find_sum(vector<int> vc,int n,int sum)
{
	bool dp[1000][1000];

	for(int i=0;i<=n;i++)
		dp[i][0]=true;

	for(int i=1;i<=sum;i++)
		dp[0][i]=false;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j>=vc[i-1])
				dp[i][j]=dp[i-1][j]||dp[i-1][j-vc[i-1]];
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	if(dp[n][sum]==false)
	{
		cout<<"No subset found";
		return 0;
	}
	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	vector<int> p;
	print_subsets(dp,vc,n,sum,p);

	return 0;
}

int main()
{
	vector<int> vc{1, 2, 3, 4, 5};
	int n = vc.size();
	int sum = 10;
	find_sum(vc,n,sum);
	return 0;
}