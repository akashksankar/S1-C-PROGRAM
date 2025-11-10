#include<stdio.h>

#include<stdlib.h>

#define N 5

int queue[N];

int rear=-1, front =-1;

void enqueue() {

int val;

printf("enter the data");

scanf("%d",&val);

if(rear==-1 && front==-1)

{

rear=front=0;

queue[rear]=val;

}

else if((rear+1)%N==front)

{

printf("queue is overflow");

return;

}

else

{

rear=(rear+1)%N;

queue[rear]=val;

}

}

void dequeue() {

if(rear==-1 && front==-1)

{

printf("queue is underflow");

return;

}

else if(rear==front)

rear=front=-1;

else{

printf("deleted item is %d ",queue[front]);

front=(front+1)%N;

}

}

void search()

{

int data,flag=0,count=0;

if(rear==-1 && front==-1)

{

printf("queue is underflow");

return;

}

else

{

printf("enter the data");

scanf("%d",&data);

while(front!=rear)

{

if(data==queue[front]){

flag=1;

break;

}
else{

front=(front+1)%N;

count++;

}

}

if(flag==1)

printf("the element is founded at %d position",count);

else

printf("element is not found");

}

}

void display(){

int i=front;

if(rear==-1 && front==-1)

{

printf("queue is underflow");

return;

}

else

{

while(i!=rear)

{

printf("%d ",queue[i]);

i=(i+1)%N;

}

printf("%d ",queue[rear]);

}

}

int main()

{

int opt;

do

{

printf("\n1.enqueue\n");

printf("2.dequeue\n");

printf("3.display\n");

printf("4.search\n");

printf("5.exit\n");

printf("enter the option ");

scanf("%d",&opt);

switch(opt)

{

case 1:enqueue();

break;

case 2:dequeue();

break;

case 3:display();

break;
case 4:search();

break;

case 5:exit(0);

default:printf("invalid option");

}

}while(1);

}
