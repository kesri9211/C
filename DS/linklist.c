//PROGRAM TO IMPLEMENT SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
    struct node*link;
}*ptr,*tmp,*head;

static int ctr;
void createNodeList(struct node*,int);
void displayList(struct node*);
void insert_at_beg(struct node**);
void insert_at_last(struct node*);
void insert_at_a_position(struct node*);
void delete_at_beg(struct node**);
void delete_at_last(struct node**);
void delete_at_pos(struct node**);
int main()
{   int n;
    head=malloc(sizeof(struct node));
	printf("How many nodes you want to create?:");
	scanf("%d",&n);
	ctr=n;
	createNodeList(head,n);
	printf("Created Linked list is:");
	displayList(head);
     insert_at_beg(&head);
	insert_at_last(head);
	insert_at_a_position(head);
     delete_at_beg(&head);
	delete_at_last(&head);
	delete_at_pos(&head);
	
	
}

void createNodeList(struct node *head,int n)
{
 int i;
  if(head==NULL){
	printf("Memory not allocated...\n");
	exit(1);
  }
  else{
	printf("Input data for node 1:");
	scanf("%d",&head->data);
	head->link=NULL;
	tmp=head;
	for(i=2;i<=n;i++){
		ptr=malloc(sizeof(struct node));
		if(ptr==NULL){
			printf("Memory not allocated!!!\n");
			exit(1);
		  }
		else
		{ printf("Input data for node %d:",i);
		  scanf("%d",&ptr->data);
		  ptr->link=NULL;
		
		  tmp->link=ptr;
		  tmp=ptr;
			
	    }
	  }
  }	
}

void displayList(struct node*head){
    ptr=head;
	if(head==NULL)
	printf("Linked list is empty!!\n");
	else
	{  while(ptr!=NULL)
	   { if(ptr->link==NULL)
	     printf("%d",ptr->data);
	     else
		 printf("%d->",ptr->data);
		 ptr=ptr->link;
	   }
		
	}
	printf("\n---------------------------------------------------------------\n");
}

void delete_at_beg(struct node**head)
{ tmp=*head;
  *head=tmp->link;
  free(tmp);
  printf("\nLinked list after deletion at beginning:");
  displayList(*head);
  ctr=ctr-1;
	
}
void delete_at_last(struct node**head)
{   struct node*prevnode;
	tmp=*head;
	while(tmp->link!=0)
	{ prevnode=tmp;
	  tmp=tmp->link;
	}
	prevnode->link=NULL;
	free(tmp);
	printf("\nLinked List after deleting element at last is:");
	displayList(*head);
	ctr=ctr-1;
}

void delete_at_pos(struct node**head)
{int pos,i=1;
 struct node*nextnode; 
 tmp=*head;
 printf("Enter the position of the elment you want to delete:");
 scanf("%d",&pos);
 if(pos==1)
 {
	delete_at_beg(head);
    exit(1);
 }
 while(i<pos-1){
	tmp=tmp->link;
	i++;
 }
 nextnode=tmp->link;
 tmp->link=nextnode->link;
 printf("Linked list after deletion from specified position :");
 displayList(*head);
 ctr=ctr-1;
}

void insert_at_beg(struct node**head){
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{ printf("Memory could not be allocated...\n");
	  exit(1);
    } 
    else
    {printf("\nEnter the data for node to insert at beginning:");
     scanf("%d",&ptr->data);
     ptr->link=*head;
     *head=ptr;
     printf("Linked list after insertion at beginning: ");
     displayList(*head);
     ctr++;
	}
	
}

void insert_at_last(struct node*head){
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{printf("\nMemory could not be allocated..\n");
	 exit(1);
	}
	else
	{ tmp=head;
	  printf("Enter the data to insert at the end:");
	  scanf("%d",&ptr->data);
	  ptr->link=NULL;
	  while(tmp->link!=NULL)
	  {
		tmp=tmp->link;
	  }
	  tmp->link=ptr;
	  ctr++;
	  printf("Counter in insert_at_last=%d\n",ctr);
	}
	printf("Linked list after insertion at end is:");
	displayList(head);
}

void insert_at_a_position(struct node*head)
{ int pos,i=1;
  printf("Enter the position at which you want to insert an element:");
  scanf("%d",&pos);
  if(pos>ctr)
  { printf("Invalid postion......\n");
   exit(1);
  }
  else
  {
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("Memory not available....\n");
		exit(1);
	  }
	else
	{ tmp=head;
	  while(i<pos-1)
	  {
		tmp=tmp->link;
		i++;
	  }
	  printf("Enter the data:");
	  scanf("%d",&ptr->data);
	  ptr->link=tmp->link;
	  tmp->link=ptr;
	  printf("Linked list after insertion at specified position:");
	  displayList(head);
		
	}
  }	
}

