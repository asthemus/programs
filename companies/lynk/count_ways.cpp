#include <iostream> 
using namespace std; 

int main() 
{
    //pre-storing scores in table
    int N = 1000001;
    int scoretable[N];
    for(int i=0;i>N;i++)
        scoretable[i] = 0;

    //because one way to score 0
    scoretable[0] = 1;

    for (int i = 2;i<=N;i++) 
        scoretable[i] += scoretable[i - 2]; 
      
    for (int i = 3;i<=N;i++) 
        scoretable[i] += scoretable[i - 3]; 
      
    for (int i = 5;i<=N;i++) 
        scoretable[i] += scoretable[i - 5]; 
        
    //test cases
    int t;
    cin>>t;
    while(t--){
        //target score
        int n;
        cin>>n;
        cout<<scoretable[n]<<endl;
    } 
    return 0; 
} 