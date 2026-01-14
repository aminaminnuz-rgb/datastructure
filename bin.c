#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create(int value){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value){
    if(root == NULL) return create(value);
    if(value < root->data) root->left = insert(root->left, value);
    else if(value > root->data) root->right = insert(root->right, value);
    return root;
}

struct node *search(struct node *root, int value){
    if(root == NULL || root->data == value) return root;
    if(value < root->data) return search(root->left, value);
    return search(root->right, value);
}

struct node *findMin(struct node *root){
    while(root->left != NULL) root = root->left;
    return root;
}

struct node *del(struct node *root, int value){
    if(root == NULL) return root;

    if(value < root->data) root->left = del(root->left, value);
    else if(value > root->data) root->right = del(root->right, value);
    else {
        // No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // One child (right)
        else if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // One child (left)
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Two children
        else{
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root = NULL;
    int ch, value;

    while(1){
        printf("\n--BST Menu--\n");
        printf("1. Insertion\n2. Inorder\n3. Find\n4. Delete\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                if(root == NULL){
                    printf("Tree is empty\n");
                } else {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if(search(root, value)){
                    printf("Value %d Found\n", value);
                } else {
                    printf("Value %d Not Found\n", value);
                }
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = del(root, value);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
