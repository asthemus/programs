#include <bits/stdc++.h>
using namespace std;

int main(){
     int n,k,temp;
     string s;
     cin>>s;
     cin>>k;
     n = s.size();
     stack<pair<char,int>> stk;
     for(int i=0;i<n;i++){
          if(stk.empty())
               stk.push(make_pair(s[i],1));
          else{
               if(stk.top().first != s[i])
                    stk.push(make_pair(s[i],1));
               else{
                    pair<char,int> p = stk.top();
                    (p.second)++;
                    stk.pop();
                    stk.push(p);
               }
          }
          while(!stk.empty() && stk.top().second == k)
               stk.pop();
     }
     string res = "";
     while(!stk.empty()){
          int freq = stk.top().second;
          char charecter = stk.top().first;
          stk.pop();
          while(freq--)
               res = charecter+res;
     }
     cout<<res;
}
