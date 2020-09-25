#include <iostream>
using namespace std;
#define m 1000000007 //1e9 + 7
#define ll long long int

ll pow_mod(ll a, ll b) //return a^b mod m
{
    ll ans=1LL;
    while(b>0) {
        if(b%2==1)
            ans = (ans*a)%m;
        a = (a*a)%m;
        b = b>>1;
    }
    return ans;
}

int main() {
	// your code goes here
	ll n,k,ans=0;
	cin>>n>>k;
	ll i,f[n+1]; //f[i]=i! mod m
    f[0] = f[1] = 1;
    for(i=2;i<=n;i++)
        f[i] = (f[i-1]*i)%m;

    ll t,a,b,c,num,den,tem;
    for(c=0;c<=k;c++) {
        t = n - (3LL*c);
        if(t<0)
            break;

        for(b=0;(2LL*b)<=t;b++) {
            a = t - (2LL*b);
            num = f[a+b+c];
            den = (f[a]*f[b])%m;
            den = (den*f[c])%m;
            den = pow_mod(den,m-2); //fermat theorem
            tem = (num*den)%m;
            ans = (ans + tem)%m;
        }
    }
    cout<<ans<<"\n";
	return 0;
}
