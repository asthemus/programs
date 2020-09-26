#include <bits/stdc++.h>
using namespace std;

void insert_edge(vector <int> graph[],int n,int m)
{
	graph[n].push_back(m);
}

void DFSinner(vector <int> graph[],int n,int m,bool visited[])
{
	visited[m] = true;
	vector <int>::iterator itr;
	for(itr=graph[m].begin();itr!=graph[m].end();itr++)
	{
		if(!visited[*itr])
		{
			DFSinner(graph,n,*itr,visited);
		}
	}
}

int mother(vector <int> graph[],int n)
{
	bool visited[n];
	for(int i=0;i<n;i++)
			visited[i] = false;

	int mt = 0;
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			DFSinner(graph,n,i,visited);
			mt = i;
		}
	}

	for(int i=0;i<n;i++)
		visited[i]=false;
	DFSinner(graph,n,mt,visited);
	vector<int>::iterator itr;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
			return -1;
	}
	return mt;		
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector <int> graph[n];
	for(int i=0;i<m;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		insert_edge(graph,temp1,temp2);
	}
	cout<<"the mother vertex is"<<mother(graph,n);
	return 0;

}