#include <bits/stdc++.h>
using namespace std;

int main()
{
	int bell[1000][1000];

	bell[0][0] = 1;

	for(int i=1;i<10;i++)
	{
		bell[i][0] = bell[i-1][i-1];

		for(int j=1;j<=i;j++)
		{
			bell[i][j] = bell[i][j-1]+bell[i-1][j-1];
		}
	}
	cout<<bell[3][3];
	return 0;
}