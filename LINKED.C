#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node* start = NULL;
struct node* create(){
	struct node* temp = NULL;
	int n = 5;
	while(n>0){
		struct node* new = NULL;
		new = (struct node*)malloc(sizeof(struct node));
		new->data = n;
		if(start == NULL){
			new->next = NULL;
			start = new;
			temp = new;
		}
		else{
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new;
			new->next = NULL;
			temp = new;
		}
		n--;
	}
	return start;
}
struct node* iae(struct node* start,int data){
	struct node* temp = NULL;
	struct node* new = NULL;
		new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	temp = start;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new;
	return start;
}
struct node* iab(struct node* start,int data){
	struct node* new = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new ->next = start;
	start = new;
	return start;
}
//data1 is value b4 which node is to be inserted
struct node* ibn(struct node* start,int data,int data1){
	struct node* new = NULL;
	struct node* temp = NULL;
	struct node* pretemp = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	temp = start;
	pretemp = temp;
	while(temp->data!=data1){
		pretemp = temp;
		temp = temp->next;
	}
	new->data = data;
	new->next = pretemp->next;
	pretemp->next = new;
	return start;
}
struct node* ian(struct node* start,int data,int data1){
	struct node* temp = NULL;
	struct node* new = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	temp = start;
	while(temp->data!=data1){
		temp = temp->next;
	}
	new->data = data;
	new->next = temp->next;
	temp->next = new;
	return start;
}
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
struct node* dels(struct node* start){
	struct node* temp = NULL;
	temp=start;
	start = start->next;
	free(temp);
	return start;

}
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