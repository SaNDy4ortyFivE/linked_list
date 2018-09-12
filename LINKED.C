/*
CODE:linked list complete
author:sandy45
date:12/09/18
compiler:Turbo C
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//actual nodes using structures 
struct node{
	int data;
	//pointer to next node
	//syntax for pointer: datatype pointer_name
	//here the datatype is node which is a structure
	struct node *next;
};
//initializing start node as NULL
struct node* start = NULL;
//function to create a default linked list:'5->4->3->2->1'
struct node* create(){
	//creating a temporary node 
	struct node* temp = NULL;
	int n = 5;
	while(n>0){
		//creating a node that will ne added to the existing linked list
		struct node* new = NULL;
		//allocating memory to it
		new = (struct node*)malloc(sizeof(struct node));
		//data element of the node = current value of i
		new->data = n;
		if(start == NULL){
			//if the start equals NULL
			//means this is the 1st node in the linked list
			//making the next as NULL
			new->next = NULL;
			//making  the start point to new node
			start = new;
			//making the temp as 1st node
			temp = new;
		}
		else{
			//gettting to last element
			while(temp->next != NULL){
				temp = temp->next;
			}
			//making the 'next' of last node point to this new node
			temp->next = new;
			//making the next of this new node ppint to NULL
			new->next = NULL;
			temp = new;
		}
		n--;
	}
	return start;
}
//inserting node at the end 
struct node* iae(struct node* start,int data){
	struct node* temp = NULL;
	struct node* new = NULL;
		new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	temp = start;
	//getting to the last node
	while(temp->next!=NULL){
		temp = temp->next;
	}
	//making the'next' of last node point to this new node
	temp->next = new;
	//returning start
	return start;
}
//inserting node at hte beginning of the list
struct node* iab(struct node* start,int data){
	struct node* new = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	//making this new node point to 1st node in the list
	new ->next = start;
	//making the start as new node
	start = new;
	return start;
}
//inserting value before a node which holds a particular data
//data1 is value before which node is to be inserted
struct node* ibn(struct node* start,int data,int data1){
	int isThere = 0;
	struct node* new = NULL;
	struct node* temp = NULL;
	struct node* pretemp = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	temp = start;
	pretemp = temp;
	while(temp!=NULL){
		if(temp->data==data1){
			isThere = 1;
			break;
		}
		pretemp = temp;
		temp = temp->next;
	}
	if(isThere == 0){
		printf("\nvalue not found:");
		return start;
	}
	else{
		new->data = data;
		new->next = pretemp->next;
		pretemp->next = new;
		return start;
	}
}
//inserting a node after a particular node
struct node* ian(struct node* start,int data,int data1){
	int isThere = 0;
	struct node* temp = NULL;
	struct node* new = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	temp = start;
	while(temp!=NULL){
		if(temp->data == data1){
			isThere = 1;
			break;
		}
		temp = temp->next;
	}
	if(isThere == 0){
		printf("\nValue not found");
		return start;
	}
	else{
		new->data = data;
		new->next = temp->next;
		temp->next = new;
		return start;
	}
}
//deleting a node
struct node* del(struct node* start,int data){
	struct node* temp = NULL;
	struct node* pre = NULL;
	int isThere = 0;
	temp = start;
	while(temp!=NULL){
		if(temp->data == data){
		isThere = 1;
		break;
		}
		pre = temp;
		temp = temp->next;
	}
	if(isThere == 0){
		printf("\nVlaue not found:");
		return start;
	}
	else{
		pre->next = temp->next;
		free(temp);
		return start;
	}


}
//deleting the start node
struct node* dels(struct node* start){
	struct node* temp = NULL;
	temp=start;
	start = start->next;
	free(temp);
	return start;
}
//deleting the end node
struct node* dele(struct node* start){
	struct node* temp= NULL;
	struct node* pre = NULL;
	temp = start;
	while(temp->next!=NULL){
		pre=temp;
		temp = temp->next;
	}
	pre->next = NULL;
	free(temp);
	return start;
}
//as the name sugggests
void display(struct node* start){
	struct node* temp = NULL;
	temp = start;
	printf("\n******************************************************");
	printf("\nstart->");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	printf("\n******************************************************");
}
int main(){
	int choice;
	int data,data1;
clrscr();
	printf("Karan sandam SE/IT/A/01 Linked list :)");
	//infinite loop that will exit on pressing 9
	while(1){
	printf("\n1>create2>iae3>iab4>ian5>ibn6>del7>dels8>dele9>exit");
	printf("***Enter choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			start = create();
			display(start);
			break;
		case 2:
			printf("\nEnter data:");
			scanf("%d",&data);
			start = iae(start,data);
			display(start);
			break;
		case 3:
			printf("\nEnter data:");
			scanf("%d",&data);
			start = iab(start,data);
			display(start);
			break;
		case 4:
			printf("\nEnter data");
			scanf("%d",&data);
			printf("\nAfter what?");
			scanf("%d",&data1);
			start = ian(start,data,data1);
			display(start);
			break;
		case 5:
			printf("\nEnter data");
			scanf("%d",&data);
			printf("\nBefore what?");
			scanf("%d",&data1);
			start = ibn(start,data,data1);
			display(start);
			break;
		case 6:
			printf("\nvalue:");
			scanf("%d",&data);
			start = del(start,data);
			display(start);
			break;
		case 7:
			start = dels(start);
			display(start);
			break;
		case 8:
		       start = dele(start);
		       display(start);
		       break;
		case 9:
			exit(0);
		}
	}
getch();
return 0;
}
