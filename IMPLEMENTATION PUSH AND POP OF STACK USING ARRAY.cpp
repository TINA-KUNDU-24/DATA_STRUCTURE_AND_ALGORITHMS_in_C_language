#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.H>
#define MAX 5
void push();
void pop();
void display();
int stack[MAX];
int top=-1;
int main()
{
	int n,ch;
	while(1)
	{
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.DISPLAY");
		printf("\n4.EXIT");
		
		printf("\n ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(1);
			break;
			default:printf("wrong choice");
				
			
		}
	}
	return 0;
}
void push()

{
	int data;
	if(top==MAX-1)
	{
		printf("\n STACK OVERFLOW");
		return;
	}
	else
	{
	    printf("\nENTER DATA: ");
	    scanf("%d",&data);
		
		top=top+1;
		stack[top]=data;
		printf("\n DATA PUSHER INTO THE STACK..");
	}
}
void pop()
{
	   int val;
	   if(top==-1)
	   {
	   	printf("\nSTACK UNDERFLOW..");
	   	return;
	   }
	   else
	   {
	   	printf("\nPOPPED ELEMENT IS %d",stack[top]);
	   	top--;
	   }
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("\nSTACK EMPTY..");
		return;
	}
	else
	{
		printf("\nELEMENTS IN STACK");
		for(i=top;i>=0;i--)
		printf("\n%d",stack[i]);   
	}
}

