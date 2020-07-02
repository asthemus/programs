#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define istream ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define uint unsigned int
#define mod 1000000007
#define vec vector<int>
#define twod vector<vector<int>>
#define all(a) a.begin(),a.end()
#define debug1(x)                cout<<#x<<"="<<x<<endl;
#define debug2(x,y)              cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z)            cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";};

void heapify(vector<int> &vc, int n, int i)
{
     int left = 2*i+1;
     int right = 2*i+2;
     int largest = i;

     if(left<n && vc[left]>vc[largest])
          largest = left;

     if(right<n && vc[right]>vc[largest])
          largest = right;

     if(largest!=i)
     {
          int temp = vc[largest];
          vc[largest] = vc[i];
          vc[i] = temp;

          heapify(vc,n,largest);
     }

}

void heap_sort(vector<int> &vc, int n)
{
     for(int i=n/2-1;i>=0;i--)
          heapify(vc,n,i);

     for(int i=n-1;i>=0;i--)
     {
          int temp = vc[0];
          vc[0] = vc[i];
          vc[i] = temp;

          heapify(vc,i,0);
     }
}

int32_t main()
{
	istream;
     vec vc = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
     int n = vc.size();
     heap_sort(vc,n);

     debugarray(vc,0,n);
     return 0;
}
