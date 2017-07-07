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
//To search an element in BST, returns true if element is found
bool search(struct treeNode* root,int data){
      if(root==NULL){
            return false;
      }
      else if(root->data==data){
            return true;
      }
      else if(root->data > data){
            search(root->left,data);
      }
      else{
            search(root->right,data);
      }
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

struct node * minValueNode(struct node* node)
{
    struct node* current = node;


    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
      if (root == NULL) return root;

      if (key < root->key)
            root->left = deleteNode(root->left, key);


      else if (key > root->key)
            root->right = deleteNode(root->right, key);


      else
      {
        // node with only one child or no child
            if (root->left == NULL){
                  struct node *temp = root->right;
                  free(root);
                  return temp;
            }
            else if (root->right == NULL){
                  struct node *temp = root->left;
                  free(root);
                  return temp;
            }

            struct node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
      }
      return root;
}

void inorder(struct treeNode* root){
      if(root!=NULL){
            inorder(root->left);
            printf("%d ",root->data);
            inorder(root->right);
      }
}

int main(){
      struct treeNode* root=NULL;
      root=insert(root,5);
      root=insert(root,3);
      root=insert(root,4);
      root=insert(root,6);
      root=insert(root,9);
      inorder(root);
      int a;
      printf("\nInsert no to search ");
      scanf("%d",&a);
      if(search(root,a)){
            printf("Found\n");
      }
      else{
            printf("Not Found\n");
      }
}
