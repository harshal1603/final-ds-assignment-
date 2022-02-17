#include<stdio.h>
#include<stdlib.h>
struct node{
char str;
struct node* lptr;
struct node* rptr;
};

void preorder(struct node* t){

if(t==NULL){
printf("empty tree");
}

else{
printf("%c",t->str);
 if(t->lptr!=NULL){
	preorder(t->lptr);
	}

 if(t->rptr!=NULL){
	preorder(t->rptr);
	}

}

}

void postorder(struct node* t){

if(t==NULL){
printf("empty tree");
}

else{

 if(t->lptr!=NULL){
	postorder(t->lptr);
	}

 if(t->rptr!=NULL){
	postorder(t->rptr);
	}
printf("%c",t->str);
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
printf("%c",t->str);
 if(t->rptr!=NULL){
	inorder(t->rptr);
	}

}


}


void main(){
struct node* a=(struct node*)malloc(sizeof(struct node));
struct node* b=(struct node*)malloc(sizeof(struct node));
struct node* c=(struct node*)malloc(sizeof(struct node));
struct node* d=(struct node*)malloc(sizeof(struct node));
struct node* e=(struct node*)malloc(sizeof(struct node));
struct node* f=(struct node*)malloc(sizeof(struct node));
struct node* g=(struct node*)malloc(sizeof(struct node));


a->str='a';
a->lptr=b;
a->rptr=c;

b->str='b';
b->lptr=d;
b->rptr=e;

c->str='c';
c->lptr=f;
c->rptr=g;

d->str='d';
d->lptr=NULL;
d->rptr=NULL;

e->str='e';
e->lptr=NULL;
e->rptr=NULL;

f->str='f';
f->lptr=NULL;
f->rptr=NULL;

g->str='g';
g->lptr=NULL;
g->rptr=NULL;

printf("preorder--");
preorder(a);
printf("\n");
printf("postorder--");
postorder(a);
printf("\n");
printf("inorder--");
inorder(a);
printf("\n");
}




















