#include<bits/stdc++.h>
using namespace std;

struct cell 
{ 
    int x, y; 
    int distance; 
    cell(int x, int y, int distance) : 
        x(x), y(y), distance(distance) {} 
}; 

bool operator<(const cell& a, const cell& b) 
{ 
    if (a.distance == b.distance) 
    { 
        if (a.x != b.x) 
            return (a.x < b.x); 
        else
            return (a.y < b.y); 
    } 
    return (a.distance < b.distance); 
} 

bool isvalid(int x, int y,int n) 
{ 
    return (x >= 0 && x < n && y >= 0 && y < n); 
} 

int getshortestdist(int n, vector<vector<int>> matrix){
    if(n == 0)
        return 0;
    if(n == 1)
        return matrix[0][0];
    vector<vector<int>> dist(n , vector<int> (n , INT_MAX));
    set<cell> st;
    st.insert(cell(0,0,0));
    int xchange[] = {-1,0,1,0};
    int ychange[] = {0,1,0,-1};
    dist[0][0] = matrix[0][0];
    while(!st.empty()){
        cell curr = *st.begin();
        st.erase(st.begin());

        for(int i=0;i<4;i++){
            int x,y;
            int oldx = curr.x;
            int oldy = curr.y;
            x = oldx + xchange[i];
            y = oldy + ychange[i];
            if(!isvalid(x,y,n))
                continue;
            if(dist[x][y] > dist[oldx][oldy] + matrix[x][y]){
                if(dist[x][y] != INT_MAX)
                    st.erase(st.find(cell(x,y,dist[x][y])));
                dist[x][y] = dist[oldx][oldy] + matrix[x][y];
                st.insert(cell(x,y,dist[x][y]));
            }
        }
    }
    return 0;
}

int main() { 
    //test cases
    int t;
    cin >> t;
    while(t--) {
        //taking input of N*N in nodeavals array then it's pushed to a matrix
        vector<int> nodevals;
        int node;
        char c;
        while(true){
            scanf("%d%c",&node,&c);
            nodevals.push_back(node);
            if(c == '\n')
                break;
        }
        //size of a row and column
        int n = nodevals.size();
        n = (int)sqrt(n);
        vector<vector<int>> matrix(n, vector<int> (n,0));
        int pos = 0;
        for(int i=0; i<n;i++) {
            for(int j=0;j<n;j++) {
                matrix[i][j] = nodevals[pos];
                pos++;
            }
        }
        cout<<getshortestdist(n,matrix);
    }
    return 0;
}