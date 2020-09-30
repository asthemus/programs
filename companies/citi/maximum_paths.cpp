#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define twod vector<vector<int>>
#define mp make_pair
#define pbc push_back
#define all(a) a.begin(),a.end()
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

int dfs(map<pair<int,int>,int> &f, vec graph[], int node, int parent, int N){
	int size = 1;
	for(auto itr = graph[node].begin();itr!=graph[node].end();itr++){
		if(*itr != parent){
			int val = dfs(f,graph,*itr,node,N);
			//cout<<val<<" "<<*itr<<" "<<node<<endl;
			f[mp(*itr , node)] = val*(N-val);
			size += val;
		}
	}
	return size;
}

int32_t main(){

	int n,r;
	cin>>n>>r;
	vec graph[n];
	for(int i=0;i<r;i++){
		int t1,t2;
		cin>>t1>>t2;
		graph[t1-1].pbc(t2-1);
		graph[t2-1].pbc(t1-1);
	}
	/*for(int i=0;i<n;i++){
		cout<<i<<" ---> <>";
		for(auto node:graph[i])
			cout<< node<<" ";
		cout<<endl;
	}*/
	map<pair<int,int>,int> f;
	dfs(f,graph,0,0,n);
	for(auto itr=f.begin();itr!=f.end();itr++)
		cout<<itr->first.first<<","<<itr->first.second<<" ---> "<<itr->second<<endl;
	
	return 0;
}
