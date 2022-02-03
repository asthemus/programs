#include <stdio.h>
#include <string.h>

void reverse(char str[], int s, int e){
	while(s<=e){
		char temp = str[s];
		str[s++] = str[e];
		str[e--] = temp;
	}
}

int main(){
	char str[1000];
	scanf("%[^\n]s", str);
	int start = 0;
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(str[i] == ' '){
			reverse(str, start, i-1);
			start = i+1;
		}
	}
	reverse(str, start, len-1);
	reverse(str, 0, len-1);
	printf("%s", str);
	return 0;
}