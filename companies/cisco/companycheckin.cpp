#include <bits/stdc++.h>
using namespace std;

int main(){
     vector<string> employees = {"Alice,10:23:02,13:04:45","Bob,09:00:43,12:03:21"};
     int n = employees.size();
     vector<int> time(600001,0);
     for(int i=0;i<n;i++){
          int num = 0;
          string s = employees[i];
          int j=0;
          while(s[j] != ',')
               j++;
          j++;
          while(s[j] != ','){
               if(s[j]>='0' && s[j]<='9')
                    num = num*10 + (s[j]-'0');
               j++;
          }
          j++;
          time[num]++;
          num = 0;
          while(j<s.size()){
               if(s[j]>='0' && s[j]<='9')
                    num = num*10 + (s[j]-'0');
               j++;
          }
          time[num+1]--;
     }
     for(int i=1;i<600001;i++)
          time[i]+=time[i-1];

     return 0;
}
