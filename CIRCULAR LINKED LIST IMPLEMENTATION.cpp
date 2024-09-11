#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
struct clinklist
{
		int data;
		struct clinklist*next;
};
typedef struct clinklist node;
node*start=NULL;
node*getnode()
{
	node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nenter data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

void create_list(int n)
{
	int i;
	node*newnode,*temp;
	for(i=0;i<n;i++)
	{
		newnode=getnode();
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			temp=temp->next;
			temp->next=newnode;
		}
	}
	newnode->next=start;
}

	void traverse()
{
	node*temp;
	temp=start;
	printf("\n The contents of list(left to right)\n");
	if(start==NULL)
	printf("\n Empty list");
	else
	{
	do
	{
		printf("\t%d",temp->data);
		temp=temp->next;
	}
		while(temp!=start);
}
}

void cll_insert_beg()
{
	node*newnode,*last;
	newnode=getnode();
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		last=start;
		while(last->next!=start)
		last=last->next;
		newnode->next=start;
		start=newnode;
		last->next=start;
	}
		
}

void cll_insert_end()
{
node*newnode,*temp;
	newnode=getnode();
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		temp=temp->next;
		temp->next=newnode;
		newnode->next=start;
	}	
}
int countnode()
{
	int count=1;
	node*temp;
	temp=start;
	do
	

	{
		count++;
		temp=temp->next;
	}
		while(temp->next!=start);
	return count;
}
void cll_insert_at_pos()
{
	node*newnode,*temp;
	int pos,nodectr,i;
	newnode=getnode();
	printf("\n enter the position");
	scanf("%d",&pos);
	nodectr=countnode();
	if(pos>(nodectr+1))
	{
		printf("position out of range");
		return;
	}
	else if(pos>1&&pos<=nodectr)
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	else
	{
		printf("%d is not a intermediate position",pos);
	}
}
void cll_delete_beg()
{
	node*temp,*last;
	if(start==NULL)
	{
		printf("\n no nodes exit");
		return;
	}
	else
	{
		last=temp=start;
		while(last->next!=start)
		last=last->next;
		start=start->next;
		last->next=start;
		free(temp);
	
	}
	
}
void cll_delete_last()
{
	node*temp,*prev;
	if(start==NULL)
	{
		printf("\n no nodes exit");
		return;
	}
	else
	{
		temp=prev=start;
		while(temp->next!=start)
		{
			prev=temp;
			temp=temp->next;
		}
		
		prev->next=start;
		free(temp);
}
}

void cll_delete_at_pos()
{
	int pos,nodectr,i;
	node*temp,*prev;
		if(start==NULL)
		{
		printf("\n empty list..");
		return;
	}
	else
	{
		printf("enter the position you want to delete");
		scanf("%d",&pos);
		nodectr=countnode();
		if(pos>nodectr)
		{
			printf("the node does not exist");
		
		}
		else if(pos>1&&pos<=nodectr)
		{
			prev=NULL;
			temp=start;
			for(i=1;i<pos;i++)
			{
				prev=temp;
				temp=temp->next;
				
			}
			prev->next=temp->next;
			free(temp);
			printf("node deleted");
		}
		else
		printf("%d is not intermediate position",pos);
		
		
		
}
}
int main()
{
	int num,ch;
	while(1)
	{
	
	printf("\n1.create a circular list\n");
	printf("2.insert at beginning\n");
	printf("3.insert at end\n");
	printf("4.insert at intermediate position\n");
	printf("5.delete at beginning\n");
	printf("6.delete at end\n");
	printf("7.delete at intermediate position\n");
	printf("8.display\n");
	printf("9.exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter the number of element you want to insert\n:");
				scanf("%d",&num);
				create_list(num);
				break;
        case 2:
        	cll_insert_beg();
        	break;
        	case 3:
        	cll_insert_end();
        	break;
        	case 4:
        	cll_insert_at_pos();
        	break;
        	case 5:
        	cll_delete_beg();
        	break;
        	case 6:
        	cll_delete_last ();
        	break;
        	case 7:
        	cll_delete_at_pos();
        	break;
        	
			case 8:
        	traverse();
        	break;
			case 9:
        	exit(0);
        	break;
        	default:
        		printf("wrong choice\n:");
        	}
        }
		return 0;
		}
