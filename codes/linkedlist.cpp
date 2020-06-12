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

void insert(int i, struct node** head)
{
	struct node* temp = new node();
	temp->val = i;
	temp->next = NULL;
	if(*head == NULL)
	{
		*head = temp;
		return;
	}
	insert(i,&(*head)->next);

}

int32_t main()
{
	istream;
	struct node* head=NULL;
	for(int i=10;i<15;i++)
	{
		insert(i,&head);
	}
	cout<<head->val;
	/*while(head!=NULL)
	{
		cout<<head->val<<" ";
		head = head->next;
	}*/
	return 0;
}


