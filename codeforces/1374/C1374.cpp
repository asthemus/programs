#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
	int t,n;
    string s;
	cin>>t;
	while(t--)
	{
		  s={};
          stack<char> stk;
          cin>>n;
          cin>>s;
          for(int i=0;i<s.size();i++)
          {
               if(stk.empty())
                    stk.push(s[i]);
               else
               {
                    if(s[i]==')' && stk.top()=='(')
                         stk.pop();
                    else stk.push(s[i]);
               }
          }
          if(stk.empty())
          {
               cout<<0<<endl;
               continue;
          }
          int count=1;
          char c = stk.top();
          stk.pop();
          while(!stk.empty() && stk.top()==c)
          {
               count++;
               stk.pop();
          }
		  cout<<count<<endl;
     }
	return 0;
}
