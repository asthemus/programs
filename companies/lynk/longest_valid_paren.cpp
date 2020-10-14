#include <bits/stdc++.h>
using namespace std;

int main()
{
    //test cases
	int t;
	cin>>t;
	while(t--)
	{
        int ans = 0;
        //input string
        string str;
        cin>>str;
		int n = str.size();
        stack<int> stk;
        stk.push(-1);
        for(int i=0;i<n;i++)
        {
            if(str[i] == '['){
                stk.push(i);
            }
            else{
                stk.pop();
                if(!stk.empty()){
                    ans = max(ans,i-stk.top()); 
                }
                else
                    stk.push(i);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
