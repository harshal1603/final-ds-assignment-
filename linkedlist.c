#include<stdlib.h>
#include<stdio.h>

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

void insertPosition(int pos, int data, struct Node** head)
{
    int size = calcSize(*head);

    if(pos<1 || size < pos) 
    { 
        printf("Can't insert, %d is not a valid position\n",pos); 
    } 
    else 
    { 
        struct Node* temp = *head; 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->data = data;
        newNode->next = NULL;

        while(--pos)
        {
            temp=temp->next;
        }
         
        newNode->next= temp->next;
        
        temp->next = newNode;
        
    }
}

void insertStart(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;

    
    *head = newNode;
}

void insertLast(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    
    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node* node){

    
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
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

void delete(struct Node** head,int n){
struct Node* temp=*head;
struct Node* pred;
while(--n){
pred=temp;
temp=temp->next;
}
pred->next=temp->next;
}

void count(struct Node** head){
struct Node* temp=*head;
int size=0;
while(temp!=NULL){
temp=temp->next;
size++;
}
printf("count of nodes is %d",size);

}
int flag=1;

void copy(struct Node** head){
struct Node* temp=*head;
struct Node* pred;
struct Node* newnode=NULL;
//struct Node* first=newnode;
while(temp!=NULL){
if(newnode==NULL){
newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=temp->data;
newnode->next=NULL;
pred=newnode;
}
else{
pred->next=(struct Node*)malloc(sizeof(struct Node));
pred=pred->next;
pred->data=temp->data;
pred->next=NULL;

}
temp=temp->next;
}
display(newnode);
}

int main()
{
	int pos,val,op,n;
    struct Node* head = NULL;
while(op!=8){
    printf("enter 1. for insertion from first\n2. for inslast\n3.for insord\n4.for deleting node\n5.for counting nodes\n6. For copy\n7.for insertposition\n8.for quit");
    scanf("%d",&op);
	switch(op){

		case 1: //printf("enter which position you want to enter");
			//scanf("%d",&pos);
			printf("enter value");
			scanf("%d",&val);
			insertStart(&head,val);
			//if(pos==1){insertStart(&head,val);  }
			//else if(pos==0){ insertLast(&head,val);}
			//else if(pos>1){insertPosition(pos,val,&head);  }
			break;
		case 2: printf("enter value");
			scanf("%d",&val);
			insertLast(&head,val);
			break;

		case 3: //printf("enter which position you want to enter");
			//scanf("%d",&pos);
			printf("enter value");
			scanf("%d",&val);
			insord(&head,val);
			break;
		case 4: printf("enter node to be deleted");
			scanf("%d",&n); 
			delete(&head,n);
			break;

		case 5: count(&head);
			break;

		case 6: copy(&head);
			break;
		case 7: printf("enter which position you want to enter");
			scanf("%d",&pos);
			printf("enter value");
			scanf("%d",&val);
			insertPosition(pos,val,&head);
			break;
			
 

		}
}

   
    display(head); 
    return 0; 
}
