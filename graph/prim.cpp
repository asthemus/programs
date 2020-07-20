#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
     cin>>n>>m;
     vector<pair<int,int>> graph[n];

     for(int i=0;i<m;i++)
     {
          int t1,t2,t3;
          cin>>t1>>t2>>t3;
          graph[t1-1].push_back(make_pair(t3,t2-1));
          graph[t2-1].push_back(make_pair(t3,t1-1));
     }

     int mincost = 0;
     vector<bool> visited(n,false);
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
     pq.push(make_pair(0,0));

     while(!pq.empty())
     {
          pair<int,int> p = pq.top();
          int node = p.second;
          int wt = p.first;
          pq.pop();
          if(visited[node])
               continue;
          visited[node] = true;
          mincost += wt;
          for(int i=0;i<graph[node].size();i++)
          {
               if(!visited[graph[node][i].second])
                    pq.push(graph[node][i]);
          }
     }
     cout<<mincost;
     return 0;
}
