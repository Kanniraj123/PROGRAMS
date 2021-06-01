#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left,*right;
};
struct node *create(int data){
    struct node *new1=(struct node *)malloc(sizeof(struct node));
    new1->data=data;
    new1->left=new1->right=NULL;
    return new1;
}

struct node *insert(struct node *node,int data){
    if(node==NULL)return create(data);
    if(data<node->data)
        node->left=insert(node->left,data);
    else if(data>node->data)
        node->right=insert(node->right,data);
    return node;
}
int replace(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
struct node *delete(struct node *root,int data){
    if(root==NULL){
        return NULL;
    }else if(root->data==data){
        if(root->left==NULL && root->right==NULL)
            return NULL;
        else if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        else{
            int d= replace(root->right);
            root->data=d;
            root->right=delete(root->right,d);
        }
    }else if(data<root->data){
         root->left=delete(root->left,data);
    }else{
        root->right=delete(root->right,data);
    }
    return root;
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node *root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    delete(root,70);
    inorder(root);
 return 0;
}
