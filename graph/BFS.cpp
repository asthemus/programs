/*#include <bits/stdc++.h>
using namespace std;

void insert(vector <int> vc[],int u,int v)
{
	vc[u].push_back(v);
	vc[v].push_back(u);
}

void printgraph(vector<int> vc[],int n)
{
	vector<int>::iterator itr;
	for(int i=0;i<n;i++)
	{
		for(itr=vc[i].begin();itr!=vc[i].end();itr++)
		{
			cout<<*itr<<" ";
		}
		cout<<endl<<endl;
	}
}

void BFS(vector <int> vc[],int n,int temp)
{

	list <int> queue;
	bool visited[n];
	vector <int>::iterator itr;
	for(int i=0;i<n;i++)
		visited[i] = false;
	queue.push_back(temp);
	visited[temp] = true;

	while(!queue.empty())
	{
		int s = queue.front();
		queue.pop_front();

		cout<<s<<" ";
		for(itr = vc[s].begin();itr!=vc[s].end();itr++)
		{
			if(!visited[*itr])
			{
				visited[*itr]=true;
				queue.push_back(*itr);
			}
		}
	}

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
		insert(vc,temp1,temp2);
	}
	//printgraph(vc,n);

	BFS(vc,n,1);
	return 0;

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

void BFS(vector<int> graph[], int n, int root)
{
	queue<int> qu;
	bool  visited[n]={false};
	qu.push(root);
	visited[root] = true;
	while(!qu.empty())
	{
		int s = qu.front();
		cout<<s<<" ";
		qu.pop();
		for(int i=0;i<graph[s].size();i++)
		{
			if(!visited[graph[s][i]])
			{
				visited[graph[s][i]] = true;
				qu.push(graph[s][i]);
			}
		}
	}

}

void insert_edge(vector<int> graph[], int a, int b)
{
	graph[a].push_back(b);
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
	BFS(graph,n,2);
	return 0;
}


vector<vector<int>>res;


queue<TreeNode *>q;
TreeNode * point =A;
q.push(A);
vector <int>v;
while(q.empty()==false)
{

    TreeNode * top=q.front();
    q.pop();
    v.push_back(top->val);

    if(top->left!=NULL)
    {

        q.push(top->left);

    }
    if(top->right!=NULL)
    {

        q.push(top->right);
    }
    if(point==top)
    {
        // This step is to separate the rows i.e levels.
        point=q.back();
        res.push_back(v);
        v.clear();
    }

}
return res;
