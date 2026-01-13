#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cq[MAX];
int front = -1,rear=-1;

void enqueue(int value){
    if((rear+1)% MAX == front){
        printf("Overflow");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear = (rear+1) % MAX;
    }
    cq[rear]=value;
    printf("%d enqueud\n",value);
}

void deq(){
    if(front == -1){
        printf("Empty");
        return;
    }
    printf("Deleted item %d\n",cq[front]);
    if(front == rear){
        front = -1;
        rear = -1;

    }
    else{
        front = (front+1) % MAX;
    }
}

void display(){
    int i;
    if(front == -1){
        printf("Empty\n");
        return;
    }
    i = front;
    while(1){
        printf("%d ",cq[i]);
        if(i == rear){
            break;
        }
        i = (i + 1)%MAX;
    }
    printf("\n");
}

int main(){
    int ch,value;
    while(1){
        printf("\n---CQ----\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.exit");
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:printf("Enter the elemnt to enqueue\n");
                   scanf("%d",&value);
                   enqueue(value);
                   break;
            case 2:deq();
                   break;       
            case 3:printf("elemnts\n");
                   display();
                   break;
            case 4: exit(0);  
            default:
                    printf("Invalid choice");
                       
                          
        }
    }
    return 0;
}