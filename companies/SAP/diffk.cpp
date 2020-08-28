#include <bits/stdc++.h>
using namespace std;

int main(){
     int n,temp,k;
     cin>>n>>k;
     unordered_map<int,int> mp;
     int count = 0;
     for(int i=0;i<n;i++){
          cin>>temp;
          if(mp.find(temp-k) != mp.end())
               count+=mp[temp-k];
          mp[temp]++;
     }
     cout<<count;
     return 0;
}
