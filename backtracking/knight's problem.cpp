#include <iostream>
using namespace std;

void printsol(int sol[8][8]) 
{ 
    for (int x = 0; x < 8; x++) 
    { 
        for (int y = 0; y < 8; y++) 
            printf(" %2d ", sol[x][y]); 
        printf("\n"); 
    } 
} 

bool solved(int x,int y,int move, int sol[8][8], int xMove[8],int yMove[8]){
	
	if (move == 64)
		return true;
	
	for(int k=0;k<8;k++)
	{
		int nextx = x + xMove[k];
		int nexty = y + yMove[k];
		
		if(nextx >= 0 && nextx < 8 && nexty >= 0 && nexty < 8 && sol[nextx][nexty] == -1)
		{
			sol[nextx][nexty] = move;
			if(solved(nextx,nexty,move+1,sol,xMove,yMove)==true)
			{
				return true;
			}
			else
				sol[nextx][nexty] = -1;
			
		}
	}
	return false;
	
}

int main() {
	int sol[8][8];
	
	for (int x = 0; x < 8; x++) 
        for (int y = 0; y < 8; y++) 
            sol[x][y] = -1; 
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    
    sol[0][0]=0;
    
    if(solved(0,0,1,sol,xMove,yMove)==false)
    {
    	cout<<"no solution";
    }
    else 
    	printsol(sol);
	return 0;
}
