#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
# define maxsize 5
void insert();
void deletion();
void display();
int queue[maxsize];
int front=-1	,rear=-1;

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.INSERT..");
		printf("\n2.DELETE..");
		printf("\n3.DISPLAY..");
		printf("\n4.EXIT..");
		printf("\nENTER YOUR CHOICE:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:deletion();
			break;
			case 3:display();
			break;
			case 4:exit(1);
			break;
			default:printf("\nWRONG CHOICE..");
		}
	}
	return 0;
}
void insert()
{
	int item;
	if(rear==(maxsize-1))
	{
		printf("\nTHE REAR IS FULL..");
	}
	else
	{
		printf("\nENTER THE ELEMENT TO BE INSERTED:  ");
		scanf("%d",& item);
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			rear=rear+1;
		}
		queue[rear]=item;
	}
}
void deletion()
{
	int item;
	if(front==-1)
	{
		printf("\nQUEUE IS EMPTY..");
	}
	else
	{
		item=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
		printf("\nDELETE ELEMENT IS=%d",item);
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\nQUEUE IS EMPTY");
    }
		else
		{
			printf("\nTHE ELEMENT OF THE QUEUE ARE\n");
    	
			for(i=front;i<=rear;i++)
			{
				printf("%d	",queue[i]);
			}
    	}
	
}

