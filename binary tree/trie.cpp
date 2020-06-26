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
const int ALPHABET_SIZE = 26;

struct node{
     bool isend;
     struct node* children[ALPHABET_SIZE];
};

typedef node node;

node* newnode()
{
     node* temp = new node();
     temp->isend = false;
     for(int i=0;i<ALPHABET_SIZE;i++)
          temp->children[i] = NULL;
     return temp;
}

void insert(node* root, string key)
{
     for(int i=0;i<key.size();i++)
     {
          int index = key[i]-'a';
          if(root->children[index]==NULL)
               root->children[index] = newnode();
          root = root->children[index];
     }
     root->isend = true;
}

bool search(node* root, string key)
{
     for(int i=0;i<key.size();i++)
     {
          int index = key[i] - 'a';
          if(root->children[index]==NULL)
               return false;
          root = root->children[index];
     }
     return(root!=NULL && root->isend);
}

int32_t main()
{
     node* root = newnode();
     vector <string> words = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
     int n = words.size();
     for(int i=0;i<n;i++)
          insert(root,words[i]);
     if(search(root,"their"))
          cout<<"Yes";
}
