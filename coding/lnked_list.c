#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void insert(struct node** head, int val){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
		return;
	}
	struct node* curr = *head;
	while(curr->next)
		curr = curr->next;
	curr->next = temp;
	return;
}

struct node* search(struct node* head, int val){
	if(!head)
		return NULL;
	while(head){
		if(head->data == val)
			return head;
		head = head->next;
	}
	return NULL;
}

void print(struct node* head){
	while(head){
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main(){
	struct node* head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	print(head);
	struct node* value = search(head, 7);
	if(value)
		printf("%d", value->data);
	else
		printf("%s", "nothing here");
	return 0;
}