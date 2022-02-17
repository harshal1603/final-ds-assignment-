#include<stdlib.h>
#include<stdio.h>
struct Node* head = NULL;
struct Node* tail;
struct Node{
    int data;
    struct Node *next;
};
int calcSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}
void display(struct Node* head,struct Node* tail){

    
   struct Node* h=head;
  struct Node* t=tail;
//struct Node* temp;
	do{
printf("->%d",h->data);
h=h->next;
	
		}
	while(h!=t->next);
	
    printf("\n");
}

void insertPosition(int pos, int data, struct Node** head)
{
    //int size = calcSize(*head);

    //if(pos<1 || size < pos) 
    //{ 
      //  printf("Can't insert, %d is not a valid position\n",pos); 
    //} 
   
        struct Node* temp = *head; 
	struct Node* pred;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->data = data;
        //newNode->next = NULL;

        while(--pos)
        {
	    pred=temp;
            temp=temp->next;
        }
	
         
        newNode->next= pred->next;
        
        pred->next = newNode;
        
    
}

void insertStart(struct Node** h,struct Node** t, int data){

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp1=*h;
	struct Node* temp2=*t;
	
    	newnode->data = data;
	if(temp1==NULL){
	newnode->next=newnode;
	*h=newnode;
	*t=newnode;
	//printf("%p  %p",temp1,temp2);
	}
	else{
	printf("in else");
	newnode->next=temp1;
	temp2->next=newnode;
	*h=newnode;	

		}



}

void insertLast(struct Node** head,struct Node** tail, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp1=*head;
	struct Node* temp2=*tail;
    newNode->data = data;
    
    if(temp1==NULL){
	newNode->next=newNode;
        *head = newNode;
	*tail=newNode;
        
    }

    //struct Node* temp = *head;

    else{
	newNode->next=temp1;
	temp2->next=newNode;
	*tail=newNode;
	
	}
}



void insord(struct Node** head, int data){
struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=data;
if(*head==NULL){
*head=newnode;
}
else{
struct Node* temp = *head; 
while(temp->data<data-1 && temp->next!=NULL){
temp=temp->next;
}
//temp--;
newnode->next=temp->next;
//printf("%d",newnode->next);
temp->next=newnode;

}

}

void delete(struct Node** head,struct Node** tail,int n){
struct Node* temp=*head;
struct Node* pred;
while(--n){
pred=temp;
temp=temp->next;
}
if(pred==NULL){
printf("empty");
}
else{
struct Node* h=*head;
struct Node* t=*tail;
if(pred==*head){
*head=h->next;
t->next=*head;
}
else if(temp==*tail){
*tail=pred;
}
else{
pred->next=temp->next;
}

}
pred->next=temp->next;
}

void count(struct Node** head){
struct Node* temp=*head;
int size=0;
while(temp->next!=*head){
temp=temp->next;
size++;
}
printf("count of nodes is %d",size);

}
int flag=1;

void copy(struct Node** head){
struct Node* temp=*head;
struct Node* pred;
struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
struct Node* first=newnode;
while(temp!=NULL){
newnode->data=temp->data;
temp=temp->next;
pred=newnode;
struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
pred->next=newnode;
}
pred->next=NULL;
//display(first);


}

int main()
{
int pos,val,op,n;
  
while(op!=8){
    printf("enter 1. for insertion from first\n2. for inslast\n3.for insord\n4.for deleting node\n7. for insert position\n8.for quit");
    scanf("%d",&op);
	switch(op){

		case 1:
			printf("enter value");
			scanf("%d",&val);
			//struct Node* t;
			insertStart(&head,&tail,val);
			break;

		case 2: printf("enter value");
			scanf("%d",&val);
			insertLast(&head,&tail,val);
			break;


		case 3: printf("enter value");
			scanf("%d",&val);
			insord(&head,val);
			break;

		case 4:printf("enter node to be deleted");
			scanf("%d",&n); 
			delete(&head,&tail,n);
			break;

		case 5:  count(&head);
			break;

		case 6:copy(&head);
			break;

		case 7: printf("enter which position you want to enter");
			scanf("%d",&pos);
			printf("enter value");
			scanf("%d",&val);
			insertPosition(pos,val,&head);
			break;
 

		}
}

   display(head,tail);
    //display(head); 
    return 0; 
}
