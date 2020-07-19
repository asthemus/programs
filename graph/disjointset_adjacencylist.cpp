#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x)
{
    if(parent[x] == -1)
        return x;
    else
        return find(parent, parent[x]);
}

void uniona(vector<int> &parent, int x,int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset)
        parent[xset] = yset;
    return;
}

int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    for(int i=0;i<m;i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
    }
     vector<int> parent(n,-1);
     int f=0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<graph[i].size();j++)
        {
             cout<<i<<" "<<graph[i][j]<<endl;
            int x = find(parent,i);
            int y = find(parent,graph[i][j]);
            cout<<x<<" "<<y<<endl;
            if(x==y && x!=-1)
            {
                f=1;
                break;
            }
            uniona(parent,x,y);
            for(int i=0;i<n;i++)
               cout<<parent[i]<<" ";
               cout<<endl;
        }
        if(f) break;
     }
     if(f) cout<<"YES";
     else cout<<"NO";
    return 0;
}
