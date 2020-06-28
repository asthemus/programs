#include <bits/stdc++.h>
using namespace std;

int golumb(int n)
{
	if(n==0) 
		return 0;
	vector<int> vc;
	vc.push_back(1);
	vc.push_back(2);
	vc.push_back(2);
	int count = 2;
	for(int i=3;i<n;i++)
	{	
		int temp = vc[count];
		for(int j=0;j<temp;j++)
		{
			vc.push_back(count+1);
			i++;
		}
		i--;
		count++;
	}

	for(int i=0;i<n;i++)
		cout<<vc[i]<<" ";
	cout<<endl;
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		golumb(n);
		
	}
	return 0;
}