#include <stdio.h>
#include <stdlib.h>

int stack[10], visited[10], adj[10][10];
int top =-1,start;
int n;

void push(int v){
    stack[++top] = v;
}

int pop(){
    return stack[top--];
}

void dfs(int start){
    int i,v;
    push(start);
    visited[start]=1;

    printf("DFS Traversal\n");
    while(top != -1){
        v = pop();
        printf("%d",v);

        for(i= n-1;i>=0;i--){
            if(adj[v][i]==1 && visited[i]==0){
                push(i);
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
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    printf("visited vertices initiay = 0");
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Enter the starting vertices");
    scanf("%d",&start);

    dfs(start);
    
    return 0;
}
