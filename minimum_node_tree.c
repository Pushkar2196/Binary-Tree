#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Definition of Node for Binary search tree
struct treeNode{
      int data;
      struct treeNode* left;
      struct treeNode* right;
};

// Function to create a new Node in heap
struct treeNode* getNode(int data){
      struct treeNode* newNode=(struct treeNode*)malloc(sizeof(struct treeNode));
      newNode->data=data;
      newNode->left=newNode->right=NULL;
      return newNode;
}

// To insert data in BST, returns address of root node
struct treeNode* insert(struct treeNode* root,int data){
      if(root==NULL){
            root=getNode(data);
      }
      else if(root->data > data){
            root->left=insert(root->left,data);
      }
      else{
            root->right=insert(root->right,data);
      }
      return root;
}
/* Given a non-empty binary search tree,
return the minimum data value found in that
tree.*/
void minNode(struct treeNode* root){
      while(root->left!=NULL){
            root=root->left;
      }
      printf("Min value in the tree: %d\n",root->data);
}


int main(){
      struct treeNode* root=NULL;
      root=insert(root,5);
      root=insert(root,3);
      root=insert(root,4);
      root=insert(root,6);
      root=insert(root,9);
      minNode(root);
}
