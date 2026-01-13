#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertBeg(){
    struct node *newnode;
    int value;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter a value");
    scanf("%d",&value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;
}

void insertEnd(){
    struct node *temp, *newnode;
    int value;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter a value");
    scanf("%d",&value);

    newnode->data=value;
    newnode->next=NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newnode;    
        newnode->prev = temp;
            
        
    }
}
void deletebeg(){
    struct node *temp;
    if(head == NULL){
        printf("List is Empty!\n");

    }
    else{
        head = head->next;
        if(head != NULL){
            head->prev=NULL;
        }
     
    }
}

void delteEnd() {
    struct node *temp;
    if(head == NULL){
        printf("List is Empty!\n");

    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }  
        temp->prev->next = NULL;
        free(temp);
        printf("Deleted at end\n"); 
    }
}

void traverseBeg(){
    struct node *temp=head;
    if(head == NULL){
        printf("LIst empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d<->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }

}

void traverseEnd(){
    struct node *temp=head;
    if(head == NULL){
        printf("LIst empty\n");
    }
    else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        printf("Backward\n: NULL<->");
        while(temp != NULL){
            printf("%d<->",temp->data);
            temp=temp->prev;
        }
        printf("\n");
    }
    
}

void count(){
    int c=0;
    struct node * temp = head;

    while(temp!= NULL){
        c++;
        temp = temp->next;
    }
    printf("Total count :%d\t ", c);
}


int main(){
    int choice;
    while(1){
        printf("----DLL----\n");
        printf("1.Insert At Beginning\n");
        printf("2.Insert At End\n");
        printf("3.delete At Beg\n");
        printf("4.delete At End\n");
        printf("5.Forward Traversal\n");
        printf("5.Backward Traversal\n");
        printf("5.count\n");
        printf("enter your choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deletebeg(); break;
            case 4: delteEnd(); break;
            case 5: printf("\n Forward Traversal\n");traverseBeg();break;
            case 6: traverseEnd();break;
            case 7: count();break;
            case 9: printf("Exit\n"); break;
            default: printf("Wrong Choice\n");
        }
    }
    return 0;
}