#include <bits/stdc++.h>
using namespace std;

int main(){
     string s;
     cin>>s;
     int n = s.size();
     int i=0;
     string res = "";
     stack<string> stk;
     while(i<n){
          if(s[i] == '('){
               stk.push(res);
               res = "";
               i++;
          }
          else if(s[i] == ')')
               i++;
          else if(s[i] == '['){
               i++;
               int num = 0;
               while(s[i] != ']'){
                    num = num*10 + (s[i]-'0');
                    i++;
               }
               i++;
               string temp = stk.top();
               stk.pop();
               while(num--)
                    temp = temp + res;
               res = temp;
          }
          else{
               res = res + s[i];
               i++;
          }
     }
     cout<<res;
     return 0;
}
