#include <bits/stdc++.h>
using namespace std;

void insert_edge(vector <int> vc[],int t1,int t2)
{
	vc[t1].push_back(t2);
	vc[t2].push_back(t1);
}


int BFS(vector <int> vc[],int n,int l)
{
	vector <int>::iterator itr;
	bool visited[n];
	int level[n];
	list <int> queue; 
	for (int i=0;i<n;i++)
	{
		visited[i]=false;
		level[i]=0;
	}	
	queue.push_back(0);
	visited[0] = true;
	level[0] = 0;

	while(!queue.empty())
	{
		int front = queue.front();
		queue.pop_front();

		for(itr=vc[front].begin();itr!=vc[front].end();itr++)
		{
			if(!visited[*itr])
			{
				level[*itr] = level[front]+1;
				visited[*itr]=true;
				queue.push_back(*itr);
			}
		}
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(level[i]==l)
			count++;
	}
	return count;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector <int> vc[n];
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		insert_edge(vc,t1,t2);
	}
	int x = BFS(vc,n,1);
	cout<<x;
	return 0;
}
