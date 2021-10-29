#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createRootNode(int val){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct node* inorder(struct node* r){
   if(r){
       inorder(r->left);
       printf("%d ",r->data);
       inorder(r->right);
   }
}

struct node* postorder(struct node* root){
       if(root){
       postorder(root->left);
       postorder(root->right);
       printf("%d ",root->data);
       
   }
}

struct node* preorder(struct node* root){
       if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
       
       
   }
}

void insert(struct node* root , int key){
     struct node *prev = NULL;
     struct node *ptr;
     while(root!=NULL){
         prev = root;
         if(key==root->data)
         return;
         else if(key < root->data){
             root = root->left;
         } 
         else{
             root = root->right;
         }
     }
   
   // link all stuff

   ptr = createRootNode(key);
   if(key > prev->data)
   prev->right = ptr;
   else
   prev->left = ptr;
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main(){
struct node* p;
// first print menu
int arr[20];
int n,val;
n=1;
p = createRootNode(20);
printf("enter the values in tree or exit by -1");

while(n!=-1){                              // program for starting 
    printf("enter the value in tree : ");
    scanf("%d",&val);
    insert(p,val);
    printf("1 or -1\n");
    scanf("%d",&n);
}

inorder(p);

deleteNode(p,3);
inorder(p);
// menu create 
// printf("menu\n1.create tree \n2.insert value in tree \n3.preorder traversal \n4.inorder traversal \n5.postorder traversal \n6.search for a node \n7.delete\n");

return 0;
}