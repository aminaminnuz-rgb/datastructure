#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void create(){
    struct node *newnode, *temp;
    int value;

    newnode = (struct node*)malloc (sizeof(struct node));
    printf("enter a value");
    scanf("%d",&value);

    newnode->data = value;
    newnode->next = NULL;

    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        temp->next=newnode;
        }
    }

}

void insertbeg(){
    struct node *newnode;
    int value;

    newnode = (struct node*)malloc (sizeof(struct node));
    printf("enter a value");
    scanf("%d",&value);

    newnode->data = value;
    newnode->next = head;
    head=newnode;
}

void delbeg(){
    struct node* temp;
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
        printf("deleted at beginning");
        }
    }

void delend(){
     struct node *temp, *prev;
    if(head==NULL){
        printf("list is empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head=NULL;
        printf("last node deleted");
    }
    else{
        temp=head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        prev->next=NULL;
        free(temp);
        printf("last node deleted");

        }
}
void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        printf("list..");
        while(temp!= NULL){
            printf("%d",temp->data);
            temp=temp->next;
        
        }
    printf("NULL\n");
    }
} 

void count(){
    int c=0;
    struct node *temp=head;
    while(temp!= NULL){
        c++;
        temp=temp->next;
    }
    printf("total count =%d",c);

    
}

