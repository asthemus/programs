#include <iostream>
using namespace std;

class Solution{
public:
    void merge(int arr1[], int arr2[], int m, int n) {
        // code here
        for(int i=n-1;i>=0;i--){
            int last = arr1[m-1];
            int j;
            for(j=m-2; j>=0 && arr1[j] > arr2[i];j--)
                arr1[j+1] = arr1[j];
            if(j != m-2 || last > arr2[i]){
                arr1[j+1] = arr2[i];
                arr2[i] = last;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}