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

     int s,x,t1;
     cin>>s>>x;
     vec scores;
     vec trials;
     for(int i=0;i<s;i++){
          cin>>t1;
          scores.pbc(t1);
     }
     for(int i=0;i<x;i++){
          cin>>t1;
          trials.pbc(t1);
     }

     vec newscores;
     newscores.pbc(scores[0]);
     for(int i=1;i<s;i++)
          if(scores[i] != scores[i-1])
               newscores.pbc(scores[i]);
     s = newscores.size();
     sort(all(newscores));
     vec results(x,s);
     results[0] -= lower_bound(all(newscores), trials[0]) - newscores.begin();
     for(int i=1;i<x;i++){
          if(trials[i]<=trials[i-1])
               results[i] = results[i-1];
          else
               results[i] -=  lower_bound(all(newscores), trials[i]) - newscores.begin();
     }
     for(int i=0;i<x;i++){
          if(results[i] == 0)
               cout<<1<<" ";
          else
               cout<<results[i]<<" ";
     }
     return 0;
}
