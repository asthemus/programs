#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x)
{
	if(parent[x] == -1)
		return x;
	return find(parent, parent[x]);
}

void union1(vector<int> &parent, int x, int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	if(xset != yset)
		parent[xset] = yset;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int, pair<int,int>>> edges;
	for(int i=0;i<m;i++)
	{
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		edges.push_back(make_pair(t3,make_pair(t1-1,t2-1)));
	}

	sort(edges.begin(),edges.end());

	int mincost = 0;
	vector<int> parent(n,-1);
	for(int i=0;i<m;i++)
	{
		//cout<<edges[i].second.first<<" "<<edges[i].second.second<<" "<<edges[i].first<<endl;
		int x = find(parent,edges[i].second.first);
		int y = find(parent,edges[i].second.second);
		//cout<<x<<" "<<y<<endl;
		int wt = edges[i].first;

		if(x==y && x!= -1)
			continue;
		if((x==y && x==-1)||(x!=y))
		{
			mincost += wt;
			union1(parent,edges[i].second.first,edges[i].second.second);
		}
		//for(int i=0;i<n;i++)
		//	cout<<parent[i]<<" ";
		//cout<<endl;
	}
	cout<<mincost<<endl;
	return 0;
}
