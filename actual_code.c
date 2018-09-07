/*Implemetation of linked lsit in C
the following code will create a default linked lsit containing 3 nodes
functions for displaying and inserting nodes are included
//written by Sandy45
//date:07/09/18
//feel free to edit and make mess :)
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//here the actual node is created using structures
/*
###############     ###############
# data # next # ->  # data # next # ->
###############     ###############
  node1         ->          node2   ->
*/
struct node{
  int data;
  //pointer to next node
  //normal declaration of pointer: datatype *pointer_name
  //here the datatype is a strucutre
  struct node *next;
};
//defining display function 
//accepting start node as parameter
void display(struct node* start){
    //creating a temporary node 
    struct node* temp = NULL;
    //making that temporary node as start
    temp=start;
    printf("\nstart");
    //traverse and print till temp is NULL
    //if 'temp->next==NULL' is used as condition the last node 
    //is neglected................give it a try!!!
    while(temp!=NULL){
        printf("->%d",temp->data);
        //moving to next node
        temp=temp->next;
    }
    printf("->NULL");
}
//defining insert function accepting start and data as parameter
void insert(struct node *start,int data){
    //creating a temp node to insert a new node
    //creating a ptr node that will point to start
    struct node* ptr = NULL;
    struct node* temp = NULL;
    //allocating memory location to temp node
    temp = (struct node*)malloc(sizeof(struct node));
    //making ptr as start of the linked list
    ptr=start;
    //since we have to find the last node
    //condition 'ptr->next==NULL' is used since we need the last node
    //we do not want ptr to move to the next  random memory location
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    //now the ptr actually points to the last node
    //inserting value in the node
    temp->data=data;
    //since it is the last node
    //'*next' of the node is made as NULL
    temp->next=NULL;
    //making this last node point to new temp node
    ptr->next=temp;
    //now temp is the new last ndoe
}
int main(){
    //declaring 3 nodes
    struct node* node1 = NULL;
    struct node* node2 = NULL;
    struct node* node3 = NULL;
    //creating a seperate node that will always be start of the linked list
    struct node* start = NULL;
    //using malloc to allocate memory to the 3 nodes
    node1 = (struct node*)malloc(sizeof(struct node));
    node2 = (struct node*)malloc(sizeof(struct node));
    node3 = (struct node*)malloc(sizeof(struct node));
    //assigning data value to node1
    node1->data=10;
    //making the pointer of node1 equal to memorylocation of node2
    node1->next=node2;
    //assigning data value to node2
    node2->data=20;
    //making the pointer of node2 equal to memorylocation of node3
    node2->next=node3;
    //assigning data value to node3
    node3->data=30;
    //since node3 is last element in the default list
    //pointer 'next' of node3 will be NULL
    node3->next=NULL;
    //make node1 as start
    start=node1;
    //calling the display function by passing the start node
    display(start);
    //inserting 40 at the end of the linked list
    //since last node of the linked list in unknown 
    //we have to traverse the linked list to find the last node
    insert(start,40);
    //again displaying the linked list by passing the start
    display(start);
    return 0;
}
