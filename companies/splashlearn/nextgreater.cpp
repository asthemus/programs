#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define twod vector<vector<int>>
#define mp make_pair
#define pbc push_back
#define all(a) a.begin(),a.end()
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

int32_t main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    stack<int> stk;
    vector<int> nextgreater(n,-1);
    stk.push(n-1);
    for(int i=n-2;i>=0;i--){
        int greater;
        while(arr[stk.top()] <= arr[i]){
            greater = stk.top();
            stk.pop();
            if(stk.empty())
                break;
        }
        if(stk.empty())
            greater = -1;
        else
            greater = arr[stk.top()];
        stk.push(i);
        nextgreater[i] = greater;
    }
    for(int i=0;i<n;i++)
        cout<<nextgreater[i]<<" ";
    cout<<endl;
    return 0;
}