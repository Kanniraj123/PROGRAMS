#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next, *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
void insert(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else
    {
      tail->next=newnode;
      newnode->prev=tail;
      tail=newnode;
    }
}
void delete(int data){
    struct node *temp;
    for(temp=head;temp;temp=temp->next){//1 2 3 5
        if(temp->data==data){
            break;
        }
    }
     temp->prev->next=temp->next;
     temp->next->prev=temp->prev;
}
void update(int index,int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    int i=1;
    while(i!=index){
        temp=temp->next;
        i++;
    }
    temp->prev->next=new;->
    new->prev=temp->prev;<-
    new->next=temp->next;
    temp->next->prev=new;
}
void insertf(int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;

    if(head==NULL){
        head=new;
    }else{
        new->next=head;
        head->prev=new;
        head=new;
    }
}
void deletef(){
   head=head->next;
}
void deletel(){
    tail=tail->prev;
    tail->next=NULL;
}
void insertsort(int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    int f=0;
    if(head->data>data){
        head->prev=new;//25
        new->next=head;//10 20 30
        head=new;
    }else{
       while(!(temp->next->data<data && temp->next->next->data>data)){
            temp=temp->next;
       }
       temp->prev->next=new;
       new->prev=temp->prev;
       new->next=temp;
       temp->prev=new;
    }
  // if(f==0){
     //temp->next=new;
    // new->prev=temp;
    //}

}
void print()
{
struct node *temp=head;
while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
}
}
int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insertsort(25);
    print();
return 0;
}

