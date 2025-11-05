#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*newnode,*temp,*head=NULL;

void insert()

{

newnode = (struct node*)malloc(sizeof(struct node));

printf("enter the data: ");

scanf("%d",&newnode->data);

if(head==NULL)

{

head=newnode;

head->next = NULL; }

else

{

newnode->next = head;

head = newnode;

}}

void delete()

{

struct node*temp;

temp=head;

head=head->next;

free(temp);

}

void search()

{

struct node*temp;

int flag = 0,data,count=1;

printf("enter the data to be search: ");

scanf("%d",&data);

if(head==NULL)

{

printf("list is empty.\n");

return;

}

else

{

temp=head;

while(temp->next!=0)

{

if(data==temp->data)

{

flag=1;

break; }

temp=temp->next;

count++; }

if(flag==1)

printf("the data %d is found at position %d\n",data,count);

else

{

printf("the data %d not found",data);

}

} }
void display()

{

struct node*temp;

temp=head;

if(head==NULL)

printf("list is empty");

else

{

while(temp!=0)

{

printf(" %d ",temp->data);

temp=temp->next;

}

} }

int main()

{

int opt;

do

{

printf("\n1.insert\n");

printf("2.deletion \n");

printf("3.display\n");

printf("4.search the data\n");

printf("5.exit\n");

printf("choose an option ");

scanf("%d",&opt);

switch(opt)

{

case 1: insert();

break;

case 2: delete();

break;

case 3: display();

break;

case 4: search();

break;

case 5: exit(0);

default: printf("invalid option\n");

}

}while(opt!=0);

}
