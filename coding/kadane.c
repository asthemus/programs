#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int max_total = 0;
	int max_till_here = 0;
	for(int i=0;i<n;i++){
		max_till_here+=arr[i];
		if(max_till_here>max_total)
			max_total = max_till_here;
		if(max_till_here<=0)
			max_till_here = 0;
	}
	printf("%d", max_total);
	return 0;
}