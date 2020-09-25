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

struct node{
     int number;
     int count;
     struct node* left;
     struct node* right;
};

typedef node node;

void insert(node** tree, int value){
     node* temp = new node();
     temp->number = value;
     temp->count = 1;
     temp->left = NULL;
     temp->right = NULL;
     if(*tree == NULL){
          *tree = temp;
          return;
     }
     if(value >= (*tree)->number)
          insert(&(*tree)->right,value);
     else
          insert(&(*tree)->left,value);
     return;
}

bool find(node* tree, int value){
     if(tree== NULL)
          return false;
     if(tree->number == value){
          (tree->count)++;
          return true;
     }
     return find(tree->left,value)||find(tree->right,value);
}

void inorder(node* tree){
     if(tree==NULL)
          return;
     inorder(tree->left);
     cout<<tree->number<<" "<<tree->count<<endl;
     inorder(tree->right);
     return;
}

int32_t main(){
     int n,t1;
     cin>>n;
     node* tree = NULL;
     for(int i=0;i<n;i++){
          cin>>t1;
          if(!find(tree,t1))
               insert(&tree,t1);
     }
     inorder(tree);
     return 0;
}
