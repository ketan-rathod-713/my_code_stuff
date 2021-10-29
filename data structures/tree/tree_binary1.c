#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createRootNode(int val){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct node* linkToLeft(struct node* p1,struct node* p2){
    p1->left = p2;     // see is this function is working or not
}
struct node* linkToRight(struct node* p1,struct node* p2){
    p1->right = p2;
}

struct node* inorder(struct node* r){
   if(r){
       inorder(r->left);
       printf("%d ",r->data);
       inorder(r->right);
   }
}

int main(){
 struct node *p = createRootNode(3);
 struct node *p1 = createRootNode(2);
 struct node *p2 = createRootNode(4);

 // to link them
 p->left = p1;
 p->right = p2; 
 inorder(p);
return 0;
}