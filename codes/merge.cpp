#include <bits/stdc++.h>
using namespace std;

int merge(int *vc, int start, int mid, int end)
{
	int temparr[end-start+1];
	int i = start, j = mid+1, k=0;

	while(i<=mid && j<=end)
	{
		if(vc[j]<vc[i])
		{
			temparr[k] = vc[j];
			k++;j++;
		}
		else
		{
			temparr[k] = vc[i];
			k++;i++;
		}
	}
	while(i<=mid)
	{
		temparr[k]=vc[i];
		k++;i++;
	}
	while(j<=end)
	{
		temparr[k]=vc[j];
		k++;j++;
	}
	for(int i=start;i<=end;i++)
	{
		vc[i] = temparr[i-start];
	}
	return 0;
}

int mergesort(int *vc,int start, int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		mergesort(vc,start,mid);
		mergesort(vc, mid+1,end);
		merge(vc,start, mid, end);
	}
	return 0;
}

int main()
{
	int vc[8] = {14, 7, 3, 12, 9, 11, 6 ,2};
	int n=8;
	mergesort(vc,0,n-1);
	for(int i=0;i<n;i++)
		cout<<vc[i]<<" ";
	return 0;
}