#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *rptr;
    struct Node *lptr;
};

struct Node* lptr=NULL;
struct Node* rptr=NULL;

void insert(int data,struct Node** rptr,struct Node** lptr,int pos){
struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=data;
struct Node* r=*rptr;
struct Node* l=*lptr;
struct Node* pred;
int size=0;
while(r!=NULL){
size++;
*r=*r->rptr;

}
while(--pos){
pred=r;
r=r->rptr;
}
if(*rptr==NULL){
newnode->rptr=NULL;
newnode->lptr=NULL;
*rptr=*lptr=NULL;

}
else{
if(pos==1){
newnode->lptr=NULL;
newnode->rptr=pred;
*lptr=newnode;

}
}
printf("%d  %p %p",newnode->data,newnode->lptr,newnode->rptr);
}
void main(){
int data;
insert(3,&rptr,&lptr,1);
insert(5,&rptr,&lptr,2);
insert(4,&rptr,&lptr,3);
}







