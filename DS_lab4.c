#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode BSTNode;

struct BSTNode{

    int data;
    struct BSTNode *left;
    struct BSTNode * right;

};

BSTNode * root;


BSTNode* getNewNode(int data){
    BSTNode * newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode ->data = data;
    newNode ->left = newNode ->right = NULL;
    return newNode;
}

BSTNode* add(BSTNode * root , int data){
    if(root == NULL){
        root= getNewNode(data);
        return root;
    }
    if(data < root -> data){
        root->left = add(root->left,data);
    }
    else{
        root->right = add(root->right,data);
    }
    return root;

}

int findMin(BSTNode * root ){
    if(root == NULL){
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }

    return findMin(root->left);
}

void inOrder(BSTNode *root){
    if(root == NULL)
        return;

    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);


}

int get_depth(BSTNode *root ){
    int leftDepth=0;
    int rightDepth=0;
    if(root == NULL){
        return 0;
    }
    else{
        leftDepth = get_depth(root->left);
        rightDepth = get_depth(root->right);
    }
    if(leftDepth > rightDepth){
        return (leftDepth +1);
    }
    else{
        return (rightDepth +1);
    }



}

int main()
{
    root = add(root,15);
    root = add(root,20);
    root = add(root,10);
    root = add(root,25);
    //root = add(root,30);
    //root = add(root,5);
    root = add(root,7);
    //root = add(root,22);
    inOrder(root);
    int maxDepth = get_depth(root);
    printf("\nmax Depth = %d",maxDepth);

    return 0;
}
