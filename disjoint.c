#include <stdio.h>
#define MAX 100

int parent[MAX];  // Stores parent of each element

// MakeSet: Initialize each element to be its own parent
void create(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    printf("MakeSet done. Each element is its own parent.\n");
}

// Find: Find the representative of the set with path compression
int find(int x) {
    if(parent[x] != x){
      parent[x]=find(parent[x]);
    return parent[x];
    }
 
}

// Union: Join the sets that contain x and y
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        printf("Elements %d and %d are already in the same set.\n", x, y);
    } else {
        parent[rootY] = rootX;  // Merge sets
        printf("Union done: %d and %d are now in the same set.\n", x, y);
    }
}

// Display current parent array (for debugging)
void displaySets(int n) {
    printf("Element: Parent");
    for(int i=0;i<n;i++){
        printf("%d \t:%d\n",i , parent[i]);
    }
    
}

int main() {
    int n, choice, x, y;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    create(n);

    while (1) {
        printf("\n--- Disjoint Set Menu ---\n");
        printf("1. Find\n");
        printf("2. Union\n");
        printf("3. Display Sets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to find: ");
                scanf("%d", &x);
                printf("Representative od %d is %d",x,find(x));
                break;

            case 2:
                printf("Enter two elements to union (x y): ");
                scanf("%d %d", &x, &y);
                unionSets(x, y);
                break;
                

            case 3:
                displaySets(n);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
