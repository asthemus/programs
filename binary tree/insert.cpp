#include <bits/stdc++.h>
using namespace std;

struct treenode{
	int val;
	struct treenode* left;
	struct treenode* right;
};

struct treenode* newNode(int vl)
{
	struct treenode* node = (struct treenode*)malloc(sizeof(struct treenode));
	node->val = vl;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void inorder(struct treenode** root)
{
	if(*root==NULL)
		return;
	inorder(&((*root)->left));
	cout<<(*root)->val<<" ";
	inorder(&((*root)->right));

}

void insert(struct treenode** root,int vl)
{
	list<struct treenode*> qu;
	qu.push_back(*root);

	while(!qu.empty())
	{
		struct treenode* temp=qu.front();
		qu.pop_front();

		if(!temp->left)
		{
			temp->left = newNode(vl);
			return;
		}
		else
			qu.push_back(temp->left);
		if(!temp->right)
		{
			temp->right = newNode(vl);
			return;
		}
		else
			qu.push_back(temp->left);
	}
	return;	
}

int main()
{

	struct treenode* root = newNode(10);
	root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 

    inorder(&root);
    insert(&root,12);
    cout<<endl<<endl;	
    inorder(&root);
    return 0;
}