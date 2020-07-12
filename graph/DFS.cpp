/*#include <bits/stdc++.h>
using namespace std;

void insert_edge(vector<int> vc[],int temp1,int temp2)
{
	vc[temp1].push_back(temp2);
	vc[temp2].push_back(temp1);
}

void printgraph(vector <int> vc[],int n)
{
	vector <int>::iterator itr;
	for(int i=0;i<n;i++)
	{
		for(itr = vc[i].begin();itr!=vc[i].end();itr++)
			cout<<*itr<<" ";
		cout<<endl<<endl;
	}
}

void DFSinner(vector <int> vc[],int n,int m,bool visited[])
{
	cout<<m<<" ";
	visited[m]=true;
	vector<int>::iterator itr;
	for(itr=vc[m].begin();itr!=vc[m].end();itr++)
	{
		if(!visited[*itr])
		{
			DFSinner(vc,n,*itr,visited);
		}
	}
}

void DFS(vector <int> vc[],int n,int m)
{
	bool visited[n];
	for(int i=0;i<n;i++)
			visited[i]=false;
	DFSinner(vc,n,m,visited);
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector <int> vc[n];
	for(int i=0;i<m;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		insert_edge(vc,temp1,temp2);
	}
	//printgraph(vc,n);

	DFS(vc,n,2);
}*/

#include <unistd.h>
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
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

void DFS(vector<int> graph[], int n, int root)
{
	stack<int> stk;
	bool visited[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
	stk.push(root);
	while(!stk.empty())
	{
		int x = stk.top();
		stk.pop();
		if(visited[x]!=true)
		{
			cout<<x<<" ";
			visited[x]=true;
			for(int i=0;i<graph[x].size();i++)
			{
				if(visited[graph[x][i]]==false)
					stk.push(graph[x][i]);
			}
		}
	}
}

void insert_edge(vector<int> graph[], int a, int b)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void printgraph(vector <int> vc[],int n)
{
	vector <int>::iterator itr;
	for(int i=0;i<n;i++)
	{
		cout<<i<<"----> ";
		for(itr = vc[i].begin();itr!=vc[i].end();itr++)
			cout<<*itr<<" ";
		cout<<endl<<endl;
	}
}

int32_t main()
{
	int n,m,temp1,temp2;
	cin>>n>>m;
	vector<int> graph[n];
	for(int i=0;i<m;i++)
	{
		cin>>temp1>>temp2;
		insert_edge(graph, temp1,temp2);
	}
	DFS(graph,n,0);
	return 0;
}
