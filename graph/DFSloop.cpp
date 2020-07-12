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

void DFSinner(vector<int> graph[], int n, bool visited[], int root)
{
     visited[root] = true;
     cout<<root<<" ";
     for(int i=0;i<graph[root].size();i++)
     {
          if(!visited[graph[root][i]])
               DFSinner(graph,n,visited,graph[root][i]);
     }

}

void DFS(vector<int> graph[], int n)
{
	bool visited[n];
     for(int i=0;i<n;i++)
          visited[i] = false;
     DFSinner(graph,n,visited,0);
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
	DFS(graph,n);
	return 0;
}
