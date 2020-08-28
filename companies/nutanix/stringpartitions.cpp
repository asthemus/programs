#include <bits/stdc++.h>
using namespace std;

int main(){
     string s;
     cin>>s;
     int n = s.size();
     if(!n){
          cout<<-1;
          return 0;
     }
     if(n==1){
          cout<<1;
          return 0;
     }
     int ret = 0;
     int alp1[26] = {0};
     int alp2[26] = {0};
     for(int i=0;i<s.size();i++){
          int index = s[i]-'a';
          alp1[index]++;
          alp2[index]++;
     }
     for(int i=0;i<n;i++){
          int index = s[i]-'a';
          alp1[index]--;
          int flag=0;
          for(int j=0;j<26;j++)
               if((alp1[j] != alp2[j]) && (alp1[j] !=0)){
                    flag=1;
                    break;
               }
          if(!flag)
               ret++;
     }
     cout<<ret;
     return 0;
}
