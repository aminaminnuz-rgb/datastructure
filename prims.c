#include <stdio.h>
#include <stdlib.h>

#define INF 999


int main(){
    int n,u,v,min;
    int cost[10][10],visited[10]={0};
    int edge = 0, total_cost=0;

    printf("Enter the number of vertices\n");
    scanf("%d",&n);

    printf("enter Cost adjacency Matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0){
                cost[i][j] = INF;
            }
            

        }
    }

    visited[1]=1;
    printf("\nmininum edge cost\n");
    while(edge < n-1){
        min = INF;
        for(int i=1;i<=n;i++){
            if(visited[i]){
                 for(int j=1;j<=n;j++){
                     if(!visited[j] && cost[i][j]< min){
                        min = cost[i][j];
                        u = i;
                        v = j;

                    }
                }
            }
      }
      printf("%d <-> %d = %d\n", u,v,min);
      total_cost += min;
      visited[v]=1;
      edge++;
    }   
    printf("Total cost = %d\n",total_cost);
    
    return 0;

}