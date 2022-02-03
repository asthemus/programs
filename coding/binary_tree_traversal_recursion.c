#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct sNode{
	struct sNode* next;
	struct Node* entry;
};

void push(struct sNode** stk, struct Node* leaf){
	struct sNode* temp = (struct sNode*)malloc(sizeof(struct sNode));
	temp->entry = leaf;
	temp->next = *stk;
	*stk = temp;
}

struct Node* pop(struct sNode** stk){
	if(*stk == NULL)
		return NULL;
	struct Node* temp = (*stk)->entry;
	*stk = (*stk)->next;
	return temp;
}

struct Node* getNode(int val){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = val;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void inorder_rec(struct Node* root){
	if(!root)
		return ;
	inorder_rec(root->left);
	printf("%d ", root->data);
	inorder_rec(root->right);
	return ;
}

void preorder_iter(struct Node* root){
	struct sNode* stk = NULL;
	push(&stk, root);
	while(stk != NULL){
		root = pop(&stk);
		printf("%d ", root->data);
		if(root->right)
			push(&stk, root->right);
		if(root->left)
			push(&stk, root->left);	
	}
}

void inorder_iter(struct Node* root){
	struct sNode* stk = NULL;
	while(root || (stk != NULL)){
		if(root){
			push(&stk, root);
			root = root->left;
		}
		else {
			root = pop(&stk);
			printf("%d ", root->data);
			root = root->right;
		}
	}
}

void postorder_iter(struct Node* root){
	struct sNode* stk1 = NULL;
	struct sNode* stk2 = NULL;
	push(&stk1, root);
	while(stk1){
		root = pop(&stk1);
		push(&stk2, root);
		if(root->left)
			push(&stk1, root->left);
		if(root->right)
			push(&stk1, root->right);
	}
	while(stk2){
		root = pop(&stk2);
		printf("%d ", root->data);
	}
}

int main(){
	struct Node* root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
	// inorder_rec(root);
	postorder_iter(root);
	return 0;
}