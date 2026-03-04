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

int main(){
    tree *root = NULL;
    int x ;
    while(1){
        printf("\n Enter the data to be inserted in the tree (0 to exit) : ");
        scanf("%d",&x);
        if(x==0) break;
        root = insertBST(root,x);
    }
    printf("\n Preorder traversal : ");
    preorderBST(root);
    printf("\n Inorder traversal : ");
    inorderBST(root);
    printf("\n Postorder traversal : ");
    postorderBST(root);
    printf("\n Enter the data to be searched in the tree : ");
    scanf("%d",&x);
    tree *temp = searchBST(root,x);
    if(temp!=NULL){
        printf("\n %d is found in the tree",temp->data);
    }
    else{
        printf("\n %d is not found in the tree",x);
    }
    printf("\n Enter the data to be deleted from the tree : ");
    scanf("%d",&x);
    root = deleteBST(root,x);
    printf("\n Inorder traversal after deletion : ");
    inorderBST(root);
    printf("\n Minimum value in the tree : %d",findminBST(root)->data);
    printf("\n Maximum value in the tree : %d",findmaxBST(root)->data);
    printf("\n");
    return 0;
}