#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct st
{
	int data;
	struct st*next;
};
typedef struct st stacknode;
stacknode*top=NULL;

void push(int);
void pop();
void display();

main()
{
	int ch,data;
	top=NULL;
	while(1)
	{
		printf("\n1.PUSH..");
		printf("\n2.POP");
		printf("\n3.DISPLAY");
		printf("\n4.EXIT");
		
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("\nENTER DATA:");
			scanf("%d",&data);
			push(data);
			break;
			case 2:pop();
			break;
			
			case 3:display();
			break;
			case 4:exit(1);
			break;
			default:printf("WRONG CHOICE..");
		}
	}
}

void push(int item)
{
	stacknode*temp;
	temp=(stacknode*)malloc(sizeof(stacknode));
	temp->data=item;
	temp->next=top;
	top=temp;
}

void pop()
{
	int item;
	stacknode*temp;
	temp=top;
	if(top==NULL)
	printf("\nSTACK IS EMPTY..");
	else
	{
		item=temp->data;
		printf("\n%d is deleted ..",item);
		top=top->next;
		free(temp);
	}
}

void display()
{
	stacknode*temp;
	temp=top;
	if(temp==NULL)
	printf("\nTHE STACK IS EMPTY");
	else
	{
	 printf("\nTHE STACK OF ELEMENTS ARE");
	 while(temp!=NULL)
    	{
    	 printf("\n%d",temp->data);
    	 temp=temp->next;	
			
    	}
    }
}

