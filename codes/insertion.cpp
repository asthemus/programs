#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vc = {25,17,31,13,2};
	int n = vc.size();
	for(int i=1; i<n; i++)
	{
		int key = vc[i];
		int j=i-1;
		while(vc[j]>key && j>=0)
		{
			vc[j+1] = vc[j];
			j = j-1;
		}
		vc[j+1] = key;
	}

	for(int i=0;i<n;i++)
		cout<<vc[i]<<" ";

	return 0;
}
