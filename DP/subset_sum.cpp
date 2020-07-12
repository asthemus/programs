#include <bits/stdc++.h>
using namespace std;

bool is_sum(int arr[],int n,int sum)
{
	bool bool_table[n][sum+1];

	for(int i=0;i<n;i++)
		bool_table[i][0]=true;

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(i==0)
			{
				if(arr[i]==j)
					bool_table[i][j]=true;
				else
					bool_table[i][j]=false;
			}
			else
			{
				if(arr[i]<=j)
				{
					bool_table[i][j] = bool_table[i-1][j]||bool_table[i-1][j-arr[i]];
				}
				if(arr[i]>j)
					bool_table[i][j] = bool_table[i-1][j];	
			}
			
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=sum;j++)
			cout<<bool_table[i][j]<<"  ";
		cout<<endl<<endl;
	}

	return bool_table[n][sum];
}

int main()
{
	int n,sum;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>sum;

	if(is_sum(arr,n,sum)==true)
		cout<<"subset found";
	else
		cout<<"subset not found";

	return 0;
}