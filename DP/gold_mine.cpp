#include <bits/stdc++.h>
using namespace std;

int getmaxgold(int gold[4][4],int m,int n)
{
	int getgold[4][4]={0};

	for(int j=n-1;j>=0;j--)
	{	
		for(int i=0;i<m;i++)
		{
			int right,right_up,right_down;
			if(j == n-1)
				right = 0;
			else
				right = getgold[i][j+1];

			if(i == 0||j == n-1)
				right_up = 0;
			else
				right_up = getgold[i-1][j+1];

			if(i==m-1||j == n-1)
				right_down = 0;
			else
				right_down = getgold[i+1][j+1];

			getgold[i][j] = gold[i][j] + max(right,max(right_up,right_down));
		}
	}

	int max=0;
	for(int j=0;j<m;j++)
	{
		if(getgold[j][0]>max)
			max= getgold[j][0];
	}
	return max;
}

int main()
{
	int gold[4][4]= 
	   {{1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2}}; 
    int m = 4, n = 4; 
    cout<<getmaxgold(gold,m,n);
    return 0; 
}