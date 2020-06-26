#include <bits/stdc++.h>
using namespace std;

int get_min(int n)
{
	int ans=0;

	while(n!=0)
	{
		vector<int> tempvec;
		int temp=n,maxel;
		while(temp!=0)
		{
			int rem = temp%10;
			temp=temp/10;
			tempvec.push_back(rem);
		}
		maxel = *max_element(tempvec.begin(),tempvec.end());
		n=n-maxel;
		ans++;
	}

	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<get_min(n);
	return 0;	
}