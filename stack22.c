#include<stdio.h>
int stack[max];
int isEmpty()
{
return top=max-1;
}
int isFull()
{
return top=max-1;
}
void push (int value)
{
if(isFull())
{
printf("stack overflow");
return;
}
top++;
stack[tp]=value;
printf("%d pushed to stack",value);
}
int pop()
{
if(ifEmpty())
{
printf("stack empty")
}
return stack[top];
}

