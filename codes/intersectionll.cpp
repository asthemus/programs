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

void insert(struct node** head,int i)
{
	struct node* temp = new node();
	temp->val = i;
	temp->next = NULL;
	if(*head == NULL)
	{
		*head = temp;
		return;
	}
	insert(&(*head)->next,i);
}

struct node* find(int i, struct node* second)
{
	while(second!=NULL)
	{
		if(second->val == i)
			return second;
		second = second->next;
	}
	return NULL;
}

bool check(struct node* first,struct node* second)
{
	while(first!=NULL && second!=NULL)
	{
		if(first->val != second->val)
			return 0;
		first = first->next;
		second = second->next;
	}
	if((first!=NULL && second==NULL)||(first==NULL && second!=NULL))
		return 0;
	return 1;
}

int32_t main()
{
	istream;
	struct node* first = NULL;
	struct node* second = NULL;
	insert(&first,7); insert(&first,1); insert(&first,2); insert(&first,4); insert(&first,1); insert(&first,8);
	insert(&second,3);insert(&second,8);insert(&second,2);insert(&second,4);insert(&second,1);insert(&second,7);
	/*while(first!=NULL)
	{
		cout<<first->val;
		first=first->next;
	}
	cout<<endl;
	while(second!=NULL)
	{
		cout<<second->val;
		second=second->next;
	}
	cout<<endl;*/
	while(first!=NULL)
	{
		int i = first->val;
		struct node* finding = find(i,second);
		if(finding!=NULL)
		{
			if(check(first,finding))
			{
				cout<<i;
				return 0;
			}
		}
		first = first->next;
	}
	cout<<-1;
	return -1;
}


