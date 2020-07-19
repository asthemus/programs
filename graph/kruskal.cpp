#include <bits/stdc++.h>
using namespace std;

void insert_edge(vector <int> vc[],int t1,int t2,int wt)
{
	vc[t1].push_back(t2);
	vc[t2].push_back(t1);
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector <int> vc[n];
	for(int i=0;i<m;i++)
	{
		int t1,t2,wt;
		cin>>t1>>t2>>wt;
		insert_edge(vc,t1,t2,wt);
	}
	kruskal(vc);
}