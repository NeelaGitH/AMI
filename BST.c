#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* createnode(int value){
    treenode* newNode = malloc(sizeof(treenode));
    if (newNode == NULL) return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printtree(treenode* root){
    if (root == NULL){
        printf("---<empty>---\n");
        return;
    }
    printf("value = %d\n", root->value);

    if (root->left != NULL) {
        printf("%d - left\n", root->value);
        printtree(root->left);
    }

    if (root->right != NULL) 
    {
        printf("%d - right\n", root->value);
        printtree(root->right);
    }

    // printf("---<end>---\n");
}

bool insertnumber(treenode** root_ptr, int value){
    treenode* root = *root_ptr;

    if (root == NULL){
        *root_ptr = createnode(value);
        return true;
    }

    if (value == root->value){
        // does nothing
        return false;
    }

    else if (value < root->value){
        return insertnumber(&(root->left), value);
    }

    else {
        return insertnumber(&root->right, value);
    }
}

bool searchvalue(treenode* root, int value){
    if (root == NULL) return false;
    if (value == root->value) return true;
    else if (value < root->value){
        return searchvalue(root->left, value);
    }
    else return searchvalue(root->right, value);
}

int main(){

    treenode* root = NULL;
    insertnumber(&root, 15);
    insertnumber(&root, 11);
    insertnumber(&root, 24);
    insertnumber(&root, 5);
    insertnumber(&root, 16);
    insertnumber(&root, 19);

    //printtree(root);

    printf("%d - %d\n", 16, searchvalue(root, 16));
    printf("%d - %d\n", 18, searchvalue(root, 18));
    printf("%d - %d\n", 19, searchvalue(root, 19));

    return 0;
}
