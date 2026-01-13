#include <stdio.h>
#define MAX 10

void inputset(int n, int bitstring[]) {
    int x;

    for (int i = 0; i < MAX; i++)
        bitstring[i] = 0;

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 1 && x <= MAX)
            bitstring[x - 1] = 1;
    }
}

void displaySet(int bitstring[]) {
    printf("{ ");
    for (int i = 0; i < MAX; i++) {
        if (bitstring[i] == 1)
            printf("%d ", i + 1);
    }
    printf("}\n");
}

void displayBit(int bitstring[]) {
    for (int i = 0; i < MAX; i++)
        printf("%d ", bitstring[i]);
    printf("\n");
}

void unionset(int A[], int B[], int C[]) {
    for (int i = 0; i < MAX; i++)
        C[i] = A[i] | B[i];
}

void intersection(int A[], int B[], int C[]) {
    for (int i = 0; i < MAX; i++)
        C[i] = A[i] & B[i];
}

void diff(int A[], int B[], int C[]) {
    for (int i = 0; i < MAX; i++)
        C[i] = A[i] & (!B[i]);
}

int main() {
    int choice, n1, n2;
    int A[MAX], B[MAX], C[MAX];

    printf("Universal Set = {1, 2, 3, ..., %d}\n", MAX);

    printf("Enter number of elements for SET A: ");
    scanf("%d", &n1);
    inputset(n1, A);

    printf("Enter number of elements for SET B: ");
    scanf("%d", &n2);
    inputset(n2, B);

    while (1) {
        printf("\n--- SET OPERATIONS ---\n");
        printf("1. Display Set A\n");
        printf("2. Display Set B\n");
        printf("3. Union (A ∪ B)\n");
        printf("4. Intersection (A ∩ B)\n");
        printf("5. Difference (A - B)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySet(A);
                displayBit(A);
                break;

            case 2:
                displaySet(B);
                displayBit(B);
                break;

            case 3:
                unionset(A, B, C);
                printf("A ∪ B = ");
                displaySet(C);
                break;

            case 4:
                intersection(A, B, C);
                printf("A ∩ B = ");
                displaySet(C);
                break;

            case 5:
                diff(A, B, C);
                printf("A - B = ");
                displaySet(C);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
