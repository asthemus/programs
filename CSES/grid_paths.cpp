#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char temp;
	cin>>n;
	vector<vector<char>> vc;
	vector<vector<int>> paths;
	for(int i=0;i<n;i++)
	{	
		vector<char> vc1;
		vector<int> vc2;
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			vc1.push_back(temp);
			vc2.push_back(0);
		}
		vc.push_back(vc1);
		paths.push_back(vc2);
	}
	paths[0][0]=0;
	if(vc[0][0]=='.')
		paths[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vc[i][j]=='.')
			{
				if(i!=0)
					paths[i][j] = (paths[i][j] + paths[i-1][j]%1000000007)%1000000007;
				if(j!=0)
					paths[i][j] = (paths[i][j] + paths[i][j-1]%1000000007)%1000000007;
			}
		}
	}
	cout<<paths[n-1][n-1];

	return 0;
}