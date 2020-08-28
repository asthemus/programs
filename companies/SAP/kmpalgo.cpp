#include <bits/stdc++.h>
using namespace std;

int main(){
     string txt,pat;
     cin>>txt>>pat;
     int n = txt.size();
     int m = pat.size();
     vector<int> lps(m,0);
     int len = 0;
     int i=1;
     while(i<m){
          if(pat[i] == pat[len]){
               len++;
               lps[i]=len;
               i++;
          }
          else{
               if(len != 0)
                    len = lps[len-1];
               else{
                    lps[i] = 0;
                    i++;
               }
          }
     }
     i=0;int j=0;
     while(i<n){
          if(txt[i] == pat[j] || ){
               i++;
               j++;
          }
          if(j==m){
               cout<<i-j<<" ";
               j = lps[j-1];
          }
          else if(i<n && pat[j] != txt[i]){
               if(j == 0)
                    i++;
               else
                    j = lps[j-1];
          }
     }
     return 0;
}
