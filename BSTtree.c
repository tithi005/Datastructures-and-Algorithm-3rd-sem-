// binary search tree construction and traversal
#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    struct tree *left;
    struct tree *right;
    int data;
}tree;

tree *insertBST(tree *root , int x){
    if(root == NULL){
        root = (tree*)malloc(sizeof(tree));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x>root->data){
        root->right = insertBST(root->right,x);
    }
    else if(x<root->data){
        root->left = insertBST(root->left , x);
    }
    else{
        printf("\n Duplicate key");
    }
    return root;
}

tree *searchBST(tree *root , int x){
    if(root == NULL){
        return NULL;
    }
    else if(x>root->data){
        return searchBST(root->right,x);
    }
    else if(x<root->data){
        return searchBST(root->left,x);
    }
    else{
        return root;
    }
}

tree *findminBST(tree *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else{
        return findminBST(root->left);
    }
}

tree *findmaxBST(tree *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->right == NULL){
        return root;
    }
    else{
        return findmaxBST(root->right);
    }
}

tree *deleteBST(tree *root , int x){
    if(root == NULL){
        return NULL;
    }
    else if(x>root->data){
        root->right = deleteBST(root->right,x);
    }
    else if(x<root->data){
        root->left = deleteBST(root->left,x);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            tree *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            tree *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            tree *temp = findminBST(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right,temp->data);
        }
    }
    return root;
}
void preorderBST(tree *root){
    if(root!=NULL){
        printf("\t%d",root->data);
        preorderBST(root->left);
        preorderBST(root->right);
    }
}

void inorderBST(tree *root){
    if(root!=NULL){
        inorderBST(root->left);
        printf("\t%d",root->data);
        inorderBST(root->right);
    }
}

void postorderBST(tree *root){
    if(root!=NULL){
        postorderBST(root->left);
        postorderBST(root->right);
        printf("\t%d",root->data);
    }
}

int main() {
    tree *root = NULL;
    int choice, x;
    tree *temp;

    while(1) {
        printf("\n\n----- BINARY SEARCH TREE MENU -----");
        printf("\n1. Insert a node");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search for a node");
        printf("\n6. Delete a node");
        printf("\n7. Find Minimum value");
        printf("\n8. Find Maximum value");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &x);
                root = insertBST(root, x);
                break;

            case 2:
                printf("\nPreorder traversal: ");
                if(root == NULL) printf("Tree is empty");
                else preorderBST(root);
                break;

            case 3:
                printf("\nInorder traversal: ");
                if(root == NULL) printf("Tree is empty");
                else inorderBST(root);
                break;

            case 4:
                printf("\nPostorder traversal: ");
                if(root == NULL) printf("Tree is empty");
                else postorderBST(root);
                break;

            case 5:
                printf("\nEnter the data to be searched: ");
                scanf("%d", &x);
                temp = searchBST(root, x);
                if(temp != NULL) {
                    printf("\n%d is found in the tree", temp->data);
                } else {
                    printf("\n%d is not found in the tree", x);
                }
                break;

            case 6:
                printf("\nEnter the data to be deleted: ");
                scanf("%d", &x);
                root = deleteBST(root, x);
                printf("\nNode deleted (if it existed).");
                break;

            case 7:
                if(root == NULL) {
                    printf("\nTree is empty. No minimum value.");
                } else {
                    printf("\nMinimum value in the tree: %d", findminBST(root)->data);
                }
                break;

            case 8:
                if(root == NULL) {
                    printf("\nTree is empty. No maximum value.");
                } else {
                    printf("\nMaximum value in the tree: %d", findmaxBST(root)->data);
                }
                break;

            case 9:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}