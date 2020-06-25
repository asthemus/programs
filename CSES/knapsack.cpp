#include <bits/stdc++.h>
using namespace std;

int matrix[1001][100001] = {0};

int knapsack(int index, int size, int weights[],int values[]){
    int take,dontTake;

    take = dontTake = 0;

    if (matrix[index][size]!=0)
        return matrix[index][size];

    if (index==0){
        if (weights[0]<=size){
            matrix[index][size] = values[0];
            return values[0];
        }
        else{
            matrix[index][size] = 0;
            return 0;
        }
    }

    if (weights[index]<=size)
        take = values[index] + knapsack(index-1, size-weights[index], weights, values);

    dontTake = knapsack(index-1, size, weights, values);

    matrix[index][size] = max (take, dontTake);

    return matrix[index][size];

}

int main(){
    int nItems,knapsackSize;
     cin>>nItems>>knapsackSize;
     int weights[nItems];
     int values[nItems];
     for(int i=0;i<nItems;i++)
               cin>>weights[i];
     for(int i=0;i<nItems;i++)
               cin>>values[i];

    cout<<knapsack(nItems-1,knapsackSize,weights,values);
    return 0;
}
