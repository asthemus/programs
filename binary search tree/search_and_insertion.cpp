#include <bits/stdc++.h>
using namespace std;

struct treenode
{
	int val;
	struct treenode* left;
	struct treenode* right;
};

void insert(struct treenode** root, int value)
{
	struct treenode* temp = (struct treenode*)malloc(sizeof(struct treenode));
	temp->val =  value;
	temp->left=NULL;
	if(*root==NULL)
	{
		*root = temp;
		return;
	}
	if(value<(*root)->val)
		insert(&(*root)->left,value);
	else if(value>(*root)->val)
		insert(&(*root)->right,value);
}

void inorder(struct treenode** root)
{
	if(*root==NULL)
		return;
	inorder(&(*root)->left);
	cout<<(*root)->val<<" ";
	inorder(&(*root)->right);
}

int main()
{
	struct treenode* root = NULL;
	insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40); 
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    inorder(&root);

	return 0;
}
