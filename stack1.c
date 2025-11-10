#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

#define MAX 100

int stack[MAX];

int top=-1,max=100;

bool isFull()

{

if(top>max)

return 1;

else

return 0;

}

bool isEmpty()

{

if(top<-1)

return -1;

else

return 0;

}

void push() {

int data;

if(isFull()){

printf("stack is full");

return;

}

else{

printf("enter the data");

scanf("%d",&data);

top++;

stack[top]=data;

printf("\n%d pushed to stack",data);

}

}

void pop()

{

if(isEmpty()){

printf("stack is empty");

return;

}

else {

printf("%d is deleted",stack[top]);

top--;

}

}

void display()

{

if(isEmpty()) {

    

printf("stack is empty");

return;

}

else {

for(int i=0;i<=top;i++)

{

printf("\nstack[%d]=%d",i+1,stack[i]);

}

} }

void peek() {

if(isEmpty())

{

printf("stack is empty");

return;

}

else{

printf("top of the element is %d",stack[top]);

}

}

int main()

{

int opt;

while(opt)

{

printf("\n1)PUSH\n");

printf("2)POP\n");

printf("3)PEEK\n");

printf("4)DISPLAY\n");

printf("5)QUIET");

printf("\nchoose your option : \n");

scanf("%d",&opt);

switch(opt)

{

case 1:push();

break;

case 2:pop();

break;

case 3:peek();

break;

case 4:display();

break;

case 5: exit(0);

default: printf("invalid option\n");

}

}

}
