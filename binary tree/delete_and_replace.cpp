#include <bits/stdc++.h>
using namespace std;

struct treenode{
	int val;
	struct treenode* left;
	struct treenode* right;
};

struct treenode* newNode(int vl)
{
	struct treenode* node = new treenode;
	node->val=vl;
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

void deletenode(struct treenode** root,int key)
{
		   
}

int main()
{
	struct treenode* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8);  

    inorder(&root);
    int key = 11;
    deletenode(&root,key);
}