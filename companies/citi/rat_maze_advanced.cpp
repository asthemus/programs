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

int32_t main(){
     twod maze =    {{1 ,0 ,1 ,1 ,1 ,0 ,0 ,1}
                    ,{1 ,0 ,0 ,0 ,1 ,1 ,1 ,1}
                    ,{1 ,0 ,0 ,0 ,1 ,0 ,0 ,1}
                    ,{1 ,0 ,1 ,0 ,9 ,0 ,1 ,1}
                    ,{1 ,1 ,1 ,0 ,0 ,0 ,1 ,0}
                    ,{1 ,0 ,1 ,0 ,1 ,1 ,1 ,1}
                    ,{1 ,1 ,1 ,1 ,1 ,0 ,1 ,1}};
     int n = 7;
     int m = 8;
     if(maze[0][0] == 0){
          cout<<"Not possible";
          return 0;
     }
     queue<pair<int,int>> qu;
     qu.push({0,0});
     while(!qu.empty()){
          int y = qu.front().first;
          int x = qu.front().second;
          qu.pop();
          if(maze[y][x] == 9){
               cout<<"Possible";
               return 0;
          }
          maze[y][x] = -1;
          if((x+1 < m) && maze[y][x+1] > 0)
               qu.push({y,x+1});
          if((x-1 >= 0) && maze[y][x-1] > 0)
               qu.push({y,x-1});
          if((y+1<n) && maze[y+1][x] > 0)
               qu.push({y+1,x});
          if((y-1 >=0) && maze[y-1][x] > 0)
               qu.push({y-1,x});
     }
     cout<<"Not Possible";
     return 0;
}
