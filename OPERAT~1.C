#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* create(){
	struct node* temp = NULL;
	int n = 5;
	while(n>0){
		struct node* new = NULL;
		new = (struct node*)malloc(sizeof(struct node));
		new->data = n;
		if(start1 == NULL){
		    new->next = NULL;
	    start1 = new;
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
	return start1;
}
struct node* copycat(struct node* start1){
    struct node* ptr1 = NULL;
    struct node* ptr2 = NULL;
    struct node* temp = NULL;
    ptr1 = start1;
    while(ptr1!=NULL){
	ptr2 = (struct node*)malloc(sizeof(struct node));
	ptr2->data = ptr1->data;
	if(start2==NULL){
	    ptr2->next = NULL;
	    start2 = ptr2;
	    temp = ptr2;
	}
	else{
	    ptr2->next = NULL;
	    temp->next = ptr2;
	    temp = ptr2;
	}
	ptr1=ptr1->next;
    }
    return start2;

}
struct node* concat(struct node* start1,struct node* start2){
    struct node* temp = NULL;
    temp = start1;
    while(temp->next!=NULL){
	temp = temp->next;
    }
    temp->next = start2;
    return start1;
}
int countcat(struct node* start){
    struct node* temp = NULL;
    int count = 0 ;
    temp = start;
    while(temp!=NULL){
	count++;
	temp = temp->next;
    }
    return count;
}
struct node* reversecat(struct node* start,int count){
	int tp[20];
    struct node* temp = NULL;
    temp = start;
    while(count>0){
	tp[count] = temp->data;
	temp = temp->next;
	count--;
    }
    temp = start;
    count++;
    while(temp!=NULL){
	temp->data = tp[count];
	temp = temp->next;
	count++;

    }
    return start;
}
 void splitcat(struct node* start,int data){
    struct node* temp = NULL;
    struct node* atemp = NULL;
    int isThere = 0;
    temp = start;
    atemp = start;
    while(temp!=NULL){
	if(temp->data==data){
	    isThere = 1;
	    break;
	}
	temp = temp->next;
    }
    if(isThere == 0){
	printf("\nValue not found");
    }
    else{atemp = temp;
	temp = temp->next;
	start2 = temp;
	atemp->next = NULL;
    }
}
void clearcat(struct node* start){
    struct node* temp = NULL;
    temp = start;
    while(temp!=NULL){
	temp->data = 0;
	temp = temp->next;
    }
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
    int count = 0;
    start1 = create();
    printf("\nLinked 1:");
    display(start1);
		
			
	start2 = copycat(start1);
	printf("\nAfter Copying.....\nLinked 2");
	display(start2);
			
	start1 = concat(start1,start2);
	printf("\nLinked 1 after concatenation");
	display(start1);
			
	count = countcat(start1);
	printf("\nCOUNT of Linked 1:%d",count);
			
	start1 = reversecat(start1,count);
	printf("\nAfter reversal of Linked 1:");
	display(start1);
		
	
	splitcat(start1,4);
	printf("\nAfter splitting.....\nLinked 1");
	display(start1);
	printf("\nLinked 2:");
	display(start2);
			
	
	
    return 0;
}
