#include<stdio.h>
#include<malloc.h>
 
struct node{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}
 
void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
 
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
 
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
 
struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}
 
void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
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
     int root_value,s;

  // i have to make menu first of all
  printf("\t__menu__\n1.create tree \n2.insert values in tree \n3.preorder traversal \n4.inorder traversal \n5.postorder traversal \n6.search for a node \n7.delete\n8. -1 to exit ");
while(s!=-1){
    printf("\nENTER THE OPERATION NO. TO PERFORM \n");
    scanf("%d",&s);
switch (s)
{
case 1:
    printf("enter the root value : ");
    scanf("%d",&root_value);
    struct node *p = createNode(root_value);
    break;
case 2:
    printf("enter value to be inserted : ");
    scanf("%d",&root_value);
    insert(p,root_value); 
    break;
      // make condn when p is null what to do
case 3:
    preOrder(p);
    break;
case 4:
    inOrder(p);
    break;
case 5:
    postOrder(p);
    break;
case 6:
    printf("Node to be searched is : ");
    scanf("%d",&root_value);
    struct node* search_val = searchIter(p,root_value);
    if(search_val==NULL)
    printf("not found\n");
    else
    printf("found\n");
    break;
case 7:
    printf("enter the node data to be deleted\n");
    scanf("%d",&root_value);
    deleteNode(p,root_value);
    break;
default:
printf("invalid operation no\n");
}
}

    return 0;
}