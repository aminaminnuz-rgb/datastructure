#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define INF 999

int parent[MAX];

int find(int i){
    while(parent[i] != i){
        i = parent[i];
    }    
    return i;
    
}

void unionset(int x,int y){
    parent[y]=x;
}

int main(){
    int cost[MAX][MAX],visited[MAX]={0};
    int edges = 0,total_cost =0;
    int n,u,v,min;

    printf("Enter Number of elements\n");
    scanf("%d",&n);

    printf("Enter cost Adjacency Matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0){
                cost[i][j] = INF;
            }
        }
    }
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    printf("\nEdge Minimun Cost ST\n");
    while(edges < n-1){
        min = INF;
        for(int i = 1 ; i <=n ; i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    u = i;
                    v = j;

                }
            }    
        }       
        int pu = find(u);
        int pv = find(v);

        if(pu != pv){
            printf("%d <-> %d = %d\n",u,v,min);
            total_cost += min;
            unionset(pu,pv);
            edges++;
        }
        cost[u][v] = cost[v][u] = INF;
    }    
    printf("Total MinCost Spanning Tree%d\n",total_cost);

    return 0;


}