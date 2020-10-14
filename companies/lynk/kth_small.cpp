#include <bits/stdc++.h>
using namespace std;

int main(){
    //test cases
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>k>>n;
        vector<int> nums;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        priority_queue<int> pq;
        int counter=0;
        for(int i=0;i<n;i++){
            int currnum = nums[i];
            if(counter < k){
                pq.push(currnum);
                counter++;
            }
            else if(pq.top()>currnum){
                pq.pop();
                pq.push(currnum);
            }
        }
        cout<<pq.top()<<endl;
    }
    return 0;
}