#include <bits/stdc++.h>
using namespace std;

long long int getval(unsigned long long a, unsigned long long b)
{
	/*cout<<a<<" "<<b<<" "<<count<<endl;
	if(a<0||b<0)
		return -1;
	if(a==b)
		return count;
	if(b>a)
		return -1;
	long long int mini = INT_MAX;
	long long int fst = getval(a,b*2,count+1),snd= getval(a,b*4,count+1),trd= getval(a,b*8,count+1);
	if(fst==-1 && snd==-1 && trd==-1)
		mini = -1;
	if(fst>0)
		mini = min(mini,fst);
	if(snd>0)
		mini = min(mini,snd);
	if(trd>0)
		mini = min(mini,trd);
	return mini;*/
	if(b==a)
		return 0;
	unsigned long long cnt=0;
	//cout<<a<<" "<<b<<endl;
	while(a>=b*8)
	{
		b = b*8;
		cnt++;
		if(a==b)
			return cnt; 
	}
	//cout<<a<<" "<<b<<endl;
	while(a>=b*4)
	{
		b = b*4;
		cnt++;
		if(a==b)
			return cnt; 
	}
	//cout<<a<<" "<<b<<endl;
	while(a>=b*2)
	{
		b = b*2;
		cnt++;
		if(a==b)
			return cnt; 
	}
	//cout<<a<<" "<<b<<endl;
	return -1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long a,b;
		cin>>a>>b;
		if(a>b)
			cout<<getval(a,b)<<endl;
		else 
			cout<<getval(b,a)<<endl;
	}
	return 0;
}