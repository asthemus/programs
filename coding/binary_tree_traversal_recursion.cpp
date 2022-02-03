#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* getNode(int val){
	TreeNode* temp = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct TreeNode* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void preorder(struct TreeNode* root){
	if(!root)
		return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct TreeNode* root){
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}

int main(){
	TreeNode* root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->right->left = getNode(5);
	root->right->right = getNode(6);
	root->right->left->left = getNode(7);
	root->right->left->right = getNode(8);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}