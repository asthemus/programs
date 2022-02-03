#include <iostream>
using namespace std;
#define MOD 1000000007

int main(){
	int n,r;
	cin>>n>>r;
	if(r>n){
		cout<<0<<endl;
		return 0;
	}
	int arr[1000001] = {0};
	for(int i=1;i<=n;i++){
		for(int j=r;j>=1;j--){
			if(j>i)
				continue;
			if(j == 1)
				arr[j] = i;
			else if(i == j)
				arr[j] = (j*arr[j-1])%MOD;
			else
				arr[j] = ((j*arr[j-1])%MOD + arr[j])%MOD;
		}
	}
	cout<<arr[r];
	return 0;
}
