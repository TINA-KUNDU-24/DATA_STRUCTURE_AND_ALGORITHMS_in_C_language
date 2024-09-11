#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
struct dlinklist
{
	
		struct dlinklist*left;
		int data;
		struct dlinklist*right;
};
typedef struct dlinklist node;
node*start=NULL;
node*getnode()
{
	node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n Enter data");
    scanf("%d",&newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
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
		else{
			temp=start;
			while(temp->right!=NULL)
			temp=temp->right;
			temp->right=newnode;
			newnode->left=temp;
			 
		}
	}
}
void traverse_left_to_right()
{
	node*temp;
	temp=start;
	printf("\n The contents of list(left to right)\n");
	if(start==NULL)
	printf("\n Empty list");
	else
	{
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->right;
		}
	}
	printf("x");
	
}
void traverse_right_to_left()
{
	node*temp;
	temp=start;
	printf("\n The contents of list(right to left)\n");
	if(start==NULL)
	printf("\n Empty list");
	else
	{
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->left;
		}
	}
	printf("x");
	
}
void insert_at_beg()
{
	node*newnode;
	newnode=getnode();
	if(start==NULL)
	{
		start=newnode;
	}
	else {
		newnode->right=start;
		start->left=newnode;
		start=newnode;
	}
}
void insert_at_end()
{
	node*newnode,*temp;
	newnode=getnode();
	if(start==NULL)
	{
		start=newnode;
	}
	else {
		temp=start;
		while(temp->right!=NULL)
		temp=temp->right;
		temp->right=newnode;
		newnode->left=temp;
	}
}int countnode()
{
	int count=1;
	node*temp;
	temp=start;
	while(temp->right!=NULL)
	{
		count++;
		temp=temp->right;
	}
	return count;
}
void insert_at_pos()
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
			temp=temp->right;
		}
		newnode->left=temp;
		newnode->right=temp->right;
		temp->right->left=newnode;
		temp->right=newnode;
	}
	else
	{
		printf("%d is not a intermediate position",pos);
	}
}
void delete_at_beg()
{
	node*temp;
	if(start==NULL)
	{
		printf("\n no nodes are exist..\n");
		return;
	}
	else
	{
		temp=start;
		start=start->right;
		if(start!=NULL)
		start->left=NULL;
		free(temp);
		printf("\n node deleted..\n");
		
	}
}
void delete_at_last()
{
	node*temp;
	if(start==NULL)
	{
		printf("\n empty list..");
		return;
	}
	else
	{
		temp=start;
	
		while(temp->right!=NULL)
		
			temp=temp->right;
			temp->left->right=NULL;
		
		free(temp);
		printf("\n node deleted..\n");
		
		
	}
}
void delete_at_pos()
{
	int pos,nodectr,i;
	node*temp;
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
			return;
		
		}
		else if(pos>1&&pos<nodectr)
		{
			
			temp=start;
			for(i=1;i<pos;i++)
			{
				
				temp=temp->right;
				
			}
			temp->right->left=temp->left;
			temp->left->right=temp->right;
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
	
	printf("\n 1.create void list\n");
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
        	insert_at_beg();
        	break;
        	case 3:
        	insert_at_end();
        	break;
        	case 4:
        	insert_at_pos();
        	break;
        	case 5:
        	delete_at_beg();
        	break;
        	case 6:
        	delete_at_last ();
        	break;
        	case 7:
        	delete_at_pos();
        	break;
        	
			case 8:
        	traverse_left_to_right();
        	traverse_right_to_left();
        	
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