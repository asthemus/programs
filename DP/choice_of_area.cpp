#include <bits/stdc++.h>
using namespace std;

int get_time(int a, int b, int arr[1000][1000], int curr)
{
	if(a<=0 || b<=0)
		return 0;

	int time = 0;

	if(curr == 0)
		time = max(time, 1 + max(get_time(a+arr[1][0], b+arr[1][1], arr,1),get_time(a+arr[2][0], b+arr[2][1], arr, 2))) ;

	if(curr == 1)
		time = max(time, 1 + max(get_time(a+arr[0][0], b+arr[0][1], arr, 0),get_time(a+arr[2][0], b+arr[2][1], arr, 2))) ;

	if(curr == 2)
		time = max(time, 1 + max(get_time(a+arr[0][0], b+arr[0][1], arr, 0),get_time(a+arr[1][0], b+arr[1][1], arr, 1))) ;			

	return time;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int arr[1000][1000];
		int a,b;
		
		for(int i=0;i<3;i++)
			for(int j=0;j<2;j++)
				cin>>arr[i][j];

		cin>>a>>b;

		int ans = max(get_time(a+arr[0][0],b+arr[0][1],arr,0),max(get_time(a+arr[1][0],b+arr[1][1],arr,1),get_time(a+arr[2][0],b+arr[2][2],arr,2)));
		
		cout<<ans<<endl;
	}
	return 0;
}