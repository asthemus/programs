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
#define debugarray(arr,j,n)      for(int i=j;i<n;i++) {cout<<"i="<<i<<" arr[i]="<<arr[i]<<"\n";

struct node{
     int val;
     struct node* left;
     struct node* right;
};

typedef node node;

void insert(node** head, int val)
{
     node* temp = new node();
     temp->val = val;
     temp->left=NULL;
     temp->right =NULL;
     if(*head == NULL)
          *head = temp;
     else if(val <= (*head)->val)
          insert(&(*head)->left,val);
     else
          insert(&(*head)->right,val);
     return;
}

void inorder(node* head)
{
     if(head=NULL)
          return;
     inorder(head->left);
     cout<<head->val<<" ";
     inorder(head->right);
}

int32_t main()
{
	istream;
	node* root=NULL;
     insert(&root, 50);
     insert(&root, 30);
     insert(&root, 20);
     insert(&root, 40);
     insert(&root, 70);
     insert(&root, 60);
     insert(&root, 80);
     inorder(root);
     return 0;
}
