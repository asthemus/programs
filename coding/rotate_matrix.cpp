#include <iostream>
using namespace std;

void rotateMat(int matrix[1000][1000], int m){
	for(int i=0;i<m/2;i++){
		for(int j=i;j<m-i-1;j++){
			int temp = matrix[i][j];
			matrix[i][j] = matrix[m-j-1][i];
			matrix[m-j-1][i] = matrix[m-i-1][m-j-1];
			matrix[m-i-1][m-j-1] = matrix[j][m-i-1];
			matrix[j][m-i-1] = temp;
		}
	}
}

void printMat(int matrix[1000][1000], int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	int matrix[1000][1000] = {{1,2,3,4},
											{5,6,7,8},
											{9,10,11,12},
											{13,14,15,16}};
	rotateMat(matrix, 4);
	printMat(matrix, 4);
	return 0;
}