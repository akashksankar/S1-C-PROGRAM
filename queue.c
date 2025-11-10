#include<stdio.h>
void main(){
int queue[10];
int size,val,rear=-1,front=-1,i,ch;
printf("Enter the size of the queue: ");
scanf("%d",&size);
do{
printf("\n\n--- MENU ---\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice (1–4): ");
scanf("%d",&ch);
switch(ch){
case 1:
if(rear==size-1){
printf("Queue is full!\n");
}
else{
printf("Enter the value to insert: ");
scanf("%d",&val);
if(front==-1 && rear==-1){
front=rear=0;
}
else{
rear++;
}
queue[rear]=val;
printf("Value inserted!\n");
}
break;

case 2:
if(front==-1 && rear==-1){
printf("Queue is empty!\n");
}
else if(front==rear){
val=queue[front];
printf("Value deleted: %d\n",val);
front=rear=-1;
}
else{
val=queue[front];
printf("Value deleted: %d\n",val);
front++;
}
break;

case 3:
if(front==-1 && rear==-1){
printf("Queue is empty!\n");
}
else{
printf("Queue elements: ");
for(i=front;i<=rear;i++){
printf("%d ",queue[i]);
}
printf("\n");
}
break;

case 4:
printf("Exiting program...\n");
break;

default:
printf("Invalid choice! Please try again.\n");
}
}while(ch!=4);
}

