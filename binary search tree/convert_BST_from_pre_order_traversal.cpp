#include <bits/stdc++.h>
using namespace std;

struct treenode
{
	int val;
	struct treenode *left,*right;
};

void insert(struct treenode** root, int n)
{
	struct treenode* temp = new treenode;
	temp->val = n;
	temp->left=NULL;
	temp->right=NULL;
	if(*root==NULL)
	{
		*root = temp;
		return;
	}

}

struct treenode* construct_tree_util(int* pre, int* pre_index, int low, int high, int size)
{
	if(*pre_index>=size || low>high)
		return NULL;

	struct treenode* root = NULL;
	insert(&root,pre[(*pre_index)]);
	*pre_index = *pre_index+1;

	if(low==high)
		return root;
	int i;
	for(i=low;i<=high;++i)
	{
		if(pre[i]>root->val)
			break;
	}
	root->left = construct_tree_util(pre,pre_index,*pre_index,i-1,size);
	root->right = construct_tree_util(pre,pre_index,i,high,size);
	return root;
}

void construct_tree(struct treenode** root, int* pre,int size)
{

	int pre_index = 0;
	*root = construct_tree_util(pre,&pre_index,0,size-1,size);
}

void printtree(struct treenode** root)
{
	if(*root==NULL)
		return;
	printtree(&(*root)->left);
	cout<<(*root)->val<<" ";
	printtree(&(*root)->right);
}

int main()
{
	int pre[] = {10,5,1,7,40,50};
	struct treenode* root=NULL;
	construct_tree(&root,pre,6);
	printtree(&root);
	return 0;
}