#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 32;
	vector<int> arr = {7,8,9,8,7,9,8,8,10};
	vector<vector<int>> dp(n+1, vector<int> (10, 0));
	for(int i=1;i<10;i++){
		int val = arr[i-1];
		for(int j=1;j<=n;j++){
			if(j<val)
				dp[j][i] = dp[j][i-1];
			else{
				int temp = dp[j-val][i];
				dp[j][i] = max(dp[j][i-1],10*temp + i);
				dp[j][i] = max(dp[j][i])
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<10;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
