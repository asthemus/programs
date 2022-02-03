#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

	TreeNode(int val){
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

void preorder(struct TreeNode* root){
	stack<struct TreeNode*> stk;
	stk.push(root);
	while(!stk.empty()){
		struct TreeNode* temp = stk.top();
		stk.pop();
		cout<<temp->val<<" ";
		if(temp->right)
			stk.push(temp->right);
		if(temp->left)
			stk.push(temp->left);
	}
}

void inorder(struct TreeNode* root){
	stack<struct TreeNode*> stk;
	while(!stk.empty() || root){
		if(root){
			stk.push(root);
			root = root->left;			
		}
		else {
			root = stk.top();
			stk.pop();
			cout<<root->val<<" ";
			root = root->right;
		}
	}
}

void postorder(struct TreeNode* root){
	stack<struct TreeNode*> stk1;
	stack<struct TreeNode*> stk2;
	stk1.push(root);
	while(!stk1.empty()){
		root = stk1.top();
		stk1.pop();
		stk2.push(root);
		if(root->left)
			stk1.push(root->left);
		if(root->right)
			stk1.push(root->right);
	}
	while(!stk2.empty()){
		root = stk2.top();
		stk2.pop();
		cout<<root->val<<" ";
	}
}

int main(){
	struct TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left->left = new TreeNode(7);
	root->right->left->right = new TreeNode(8);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}