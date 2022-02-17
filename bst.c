#include<stdio.h>
#include<stdlib.h>
struct node{
int num;
struct node* lptr;
struct node* rptr;
};

void preorder(struct node* t){

if(t==NULL){
printf("empty tree");
}

else{
printf("%d ",t->num);
 if(t->lptr!=NULL){
	preorder(t->lptr);
	}

 if(t->rptr!=NULL){
	preorder(t->rptr);
	}

}

}


void inorder(struct node* t){

if(t==NULL){
printf("empty tree");
}

else{

 if(t->lptr!=NULL){
	inorder(t->lptr);
	}
printf("%d ",t->num);
 if(t->rptr!=NULL){
	inorder(t->rptr);
	}

}


}

struct node* search(struct node* root,int x){

if(root==NULL || root->num==x){
return root;
}
else if(x>root->num)
return search(root->rptr,x);

else{
return search(root->lptr,x);
}
}

struct node* minvaluenode(struct node* m){
struct node* current=m;
while(current && current->lptr!=NULL){
current=current->lptr;
}
return current;


}

struct node* delete(struct node* root,int d){

if(d<root->num){

root->lptr=delete(root->lptr,d);
}
else if(d>root->num){
root->rptr=delete(root->rptr,d);
}

else{

if(root->lptr==NULL){
struct node* temp=root->rptr;
free(root);
return temp;
}
else if(root->rptr==NULL){
struct node* temp=root->lptr;
free(root);
return temp;

}
struct node* temp=minvaluenode(root->rptr);
root->num=temp->num;
root->rptr=delete(root->rptr,temp->num);



}


}

struct node* insert(struct node* root,int x){
if(root==NULL) {
struct node* p=(struct node*)malloc(sizeof(struct node));
p->num=x;
p->lptr=NULL;
p->rptr=NULL;
return p;
}
else if(x>(root->num)){
 root->rptr=insert(root->rptr,x);
}
else{
root->lptr=insert(root->lptr,x);
}
return root;



}

void main(){

int arr[10];

printf("enter 10 nums");

struct node* t=(struct node*)malloc(sizeof(struct node));
struct node* temp=(struct node*)malloc(sizeof(struct node));
struct node* trav=(struct node*)malloc(sizeof(struct node));
for(int i=0;i<10;i++){
scanf("%d",&arr[i]);
insert(t,arr[i]);
}
printf("%d",t->num);
//temp->rptr=NULL;
//temp->lptr=NULL;
insert(t,1);
printf("in order");
inorder(t);
printf("\n");
printf("pre order");
preorder(t);

delete(t,5);
temp=search(t,1);
printf("\npreorder after delete\n");
preorder(t);
//printf("\n%d\n",temp->num);



}
