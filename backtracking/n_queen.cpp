#include <bits/stdc++.h>
using namespace std;

bool issafe(int x,int y,int n, int board[1000][1000])
{
	for(int i=0;i<n;i++)
	{
		if(board[x][i]==1 || board[i][y]==1)
			return false;
			
		if(x+i>=0 && y+i>=0 && x+i<n && y+i<n)
			if(board[x+i][y+i]==1 || board[x+i][y-i]==1)	
				return false;
			
		if(x-i>=0 && y-i>=0 && x-i<n && y-i<n)
			if(board[x-i][y-i]==1 || board[x-i][y+i]==1)	
				return false;
	}
	return true;
}

bool n_queen(int x,int board[1000][1000],int n)
{
	if(x==n)
		return true;
	if(x>=0 && x<n)
	{
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(issafe(x,i,n,board)==true)
			{
				board[x][i]=1;
				if(n_queen(x+1,board,n)==true)
					return true;
				board[x][i]=0;	
			}
		}
		
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	int board[1000][1000];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i][j]=0;
	n_queen(0,board,n);
	/*board[1][2]=1;
	board[2][1]=1;
	cout<<issafe(3,3,4,board);*/
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<board[i][j]<<" ";
		cout<<endl<<endl;	
	}
	return 0;
}
