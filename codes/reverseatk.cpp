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
	struct node* next;
};

typedef node node;

void insert(node** head,int i)
{
	if(*head == NULL)
	{
		node* temp = new node();
		temp->val = i;
		temp->next=NULL;
		*head = temp;
	}
	else
		insert(&(*head)->next,i);
}

node* reverse(node* A, int i)
{
	int key = i;
	node* head=A;
	node* prev=NULL;
	node* next=NULL;
	while(head != NULL && key--)
	{
		next = head->next;
		head->next = prev;
		prev=head;
		head=next;
	}
	if(next!=NULL)
		A->next = reverse(next, i);
	return prev;
}

int32_t main()
{
	istream;
	int k;
	scanf("%lld",&k);
	node* head = NULL;
	node* next;
	for(int i=1;i<=3*k;i++)
		insert(&head,i);
	head = reverse(head,k);
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head = head->next;
	}		
	return 0;
}


