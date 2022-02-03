#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<vector<int> > graph(1000, vector<int> (1000, 0));
	vector<vector<int> > graph_list(1000, vector<int> ());
	int nodes, edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int a1, a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		graph[a1][a2] = graph[a2][a1] = 1;
		graph_list[a1].push_back(a2);
		graph_list[a2].push_back(a1);
	}

	for(int i=0;i<nodes;i++){
		cout<<i<<endl;
		for(int j=0;j<graph_list[i].size();j++)
			cout<<graph_list[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}