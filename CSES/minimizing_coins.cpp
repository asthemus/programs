#include <bits/stdc++.h>
using namespace std;

int mins[1000001];

int get_min(vector<int> vc, int n, int sum,int count)
{
	cout<<sum<<" "<<count<<endl;
	if(n==0)
		return -1;
	if(mins[sum] != -1)
		return mins[sum];

	if(sum==0)
		return count;

	int temp = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(vc[i]<=sum)
		{
			int temp1 = get_min(vc,n,sum-vc[i],count+1);
			if(temp1>=0)
				temp = min(temp,temp1);
		}
	}
	if(temp==INT_MAX)
		temp=-1;
	mins[sum]=temp;
	return temp;
	return 0;
}

int main()
{
	int n,x,temp;
	cin>>n>>x;
	vector<int> vc;
	for(int i=0;i<=x+1;i++)
		mins[i] = -1;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vc.push_back(temp);
	}
	//sort(vc.begin(),vc.begin()+n,greater<>());
	cout<<get_min(vc,n,x,0);

	return 0;
}