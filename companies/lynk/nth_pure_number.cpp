#include <bits/stdc++.h>
using namespace std;

bool numistwopower(int number) 
{ 
    double n = log(number)/log(2); 
    int checker = int(n);
    if(n - int(n) == 0)
        return true;
    else 
        return false;  
} 

bool numisfourseries(int number, int numofdigits) 
{ 
    int maxi = int(pow(2, numofdigits)+pow(2, numofdigits - 1)-1); 
    int mini = int(pow(2, numofdigits)-1); 
    return (number >= mini) && (number < maxi); 
}

int main(){
    
    //till n = 100001 we can store results in numbers array which will not cause segmentation fault due to lack of memory and can speed up the code.
    //as it is coded below. otherwise we can generate numbers array inside our test cases loop which will take more time 
    int N = 100001;
    string nums[N];
    nums[0] = "";
    int size = 0;
    int increment = 0;
    for (int i=1;i<N;i++) { 
        if(numistwopower(i + 1)) { 
            size = size + 1; 
        }
        if (numisfourseries(i, size)) { 
            increment = int(pow(2, size - 1)); 
            nums[i] = "4" + nums[i - increment] + "4"; 
        }
        else {
            increment = int(pow(2, size)); 
            nums[i] = "5" + nums[i - increment] + "5"; 
        } 
    }
    int t;
    //test cases
    cin>>t;
    while(t--){
        //nth pure number
        int n;
        cin>>n;
        cout<<nums[n]<<endl;
    }
    return 0;
}