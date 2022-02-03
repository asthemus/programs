#include <iostream>
#include <vector>
using namespace std;
vector<string> AllParenthesis(int n) ;

class Solution
{
    public:
    void generate (vector<string> &res, int m, int n, string curr){
        if(m == 0 && n == 0){
            res.push_back(curr);
            return;
        }
        if(m<n){
            if(m != 0)
                generate(res, m-1, n, curr+"(");
            generate(res,  m, n-1, curr+")");
        }
        else if(m == n)
            generate(res, m, n-1, curr+")");
        else
            return;
        return;
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        string curr = "(";
        generate(res, n-1, n, curr);
        cout<<res.size();
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends