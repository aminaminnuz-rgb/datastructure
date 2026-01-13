#include <stdio.h>
#include <stdlib.h>

int q[10],adj[10][10],visited[10];
int front = -1,rear=-1;
int n;

void enq(int v){
    if (rear==9)
    {
        return;
    }
    if(front == -1){
        front =0;
    }
    q[++rear] = v;
}

int deq (){
    return q[front++];
}

void bfs(int start){
    int v;
    enq(start);
    visited[start]=1;

    printf("BFS Traversal\n");
        while(front <= rear){
            v = deq();
            printf("%d",v);

            for(int i=0;i<n;i++){
                if (adj[v][i]==1 && visited[i]==0)
                {
                    enq(i);
                    visited[i]=1;
                }
                
            }
        }
    }
int main(){
    int start,visited[10];
    printf("enter number of elements");
    scanf("%d",&n);

    printf("Adjacency MAtrix\n");
    for(int i=0;i<n;i++){
        visited[i]=0;
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }


    printf("Enter the starting vertices");
    scanf("%d",&start);

    bfs(start);
    
    return 0;
}

