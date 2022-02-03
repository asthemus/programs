#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int main(){
	int l1[2];
	int r1[2];
	int l2[2];
	int r2[2];
	scanf("%d %d", &l1[0], &l1[1]);
	scanf("%d %d", &r1[0], &r1[1]);
	scanf("%d %d", &l2[0], &l2[1]);
	scanf("%d %d", &r2[0], &r2[1]);
	int area = 0;

	area += (abs(l1[0]-r1[0])*abs(l1[1]-r1[1]));
	area += (abs(l2[0]-r2[0])*abs(l2[1]-r2[1]));
	int x_overlap = min(r1[0], r2[0]) - max(l1[0], l2[0]);
	int y_overlap =  min(r1[1], r2[1]) - max(l1[1], l2[1]);
	if(x_overlap>0 && y_overlap>0)
		area -= (x_overlap*y_overlap);
	printf("%d", area);
	return 0;
}