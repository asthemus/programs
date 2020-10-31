#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector<vector<int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ADITYA freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 200001
#define mod 1000000007
#define inf 1e17

ll ncr(ll n, ll r) 
{ 
    if (r > n - r) 
        r = n - r; 
  
    ll C[r + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
  
    for (ll i = 1; i <= n; i++) { 
   
        for (ll j = min(i, r); j > 0; j--) 
  
         
            C[j] = (C[j] + C[j - 1]) % mod; 
    } 
    return C[r]; 
}




int32_t main()  
{
	boost
    #ifndef ONLINE_JUDGE 
    ADITYA
    #endif
    
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
    	int n ;
    	cin>>n;
    	int cnt=0;
    	string str;
    	cin>>str;
    	for(int i=1;i<n;i++)
    	{
    		if(str[i]==str[i-1])
    		{
    			cnt++;
    		}	
    	}
    	cout<<(cnt+1)/2<<endl;
    }

}