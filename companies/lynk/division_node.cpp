#include <bits/stdc++.h>
using namespace std;
#define N 100001
#define inf 1e9


void dfs(vector<pair<int,int>> tree[N], int nodes[N], int sub[N],int node,int val)
{
    sub[node] = nodes[node];
    for(auto v:tree[node])
    {
        if(v.first == val)
            continue;
        dfs(tree,nodes,sub,v.first , node);
        sub[node]+=sub[v.first];
    }
}

void dfs2(vector<pair<int,int>> tree[N], int nodes[N], int sub[N],int *mini, int *ans, int node,int p,int *total)
{
    for(auto v:tree[node])
    {
        if(v.first == p)
            continue;
        int val = *total - sub[v.first];
        if(val < *mini)
        {
            *mini = val;
            *ans = v.second;
        }
        else if(val == *mini && v.second < *ans)
        {
            *ans = v.second;
        }
        dfs2(tree,nodes,sub,&(*mini),&(*ans),v.first,node,&(*total));
    }
}

int main(){
    
    //test cases
    int t;
    cin>>t;
    while(t--){
        //number of nodes
        int n;
        cin>>n;
        int totalnodes = 0;
        vector<pair<int,int>> tree[N];
        int nodes[N];
        int sub[N];
        int total = 0;
        int mini = inf;
        int ans = 0;
        for(int i=1;i<n;i++){
            int ui,vi;
            cin>>ui>>vi;
            tree[ui].push_back({vi,i});
            tree[vi].push_back({ui,i});
        }
        for(int i=1;i<=n;i++){
            int temp;
            cin>>temp;
            nodes[i] = temp;
            totalnodes += nodes[i];
        }
        dfs(tree,nodes,sub,1,0);
        dfs2(tree,nodes,sub,&mini,&ans,1,0,&total);
        cout<<ans<<endl;
    }
}