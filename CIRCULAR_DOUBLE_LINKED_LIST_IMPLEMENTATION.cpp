#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
struct cdlinklist

{
    int data;
    struct cdlinklist*left;
    struct cdlinklist*right;
};
typedef struct cdlinklist node;
node*start=NULL;
node*getnode()
{
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("ENTER DATA:");
    scanf("%d",&newnode->data);

    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
//CREATING A CIRCULAR DOUBLE LINKEDLIST
void createlist(int n)
{
int i;
node*newnode,*temp;
for(i=0;i<n;i++)
{
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
        newnode->left=start;
        newnode->right=start;
    }
    else
    {
        newnode->left=start->left;
        newnode->right=start;
        start->left->right=newnode;
        start->left=newnode;

    }
}
}
//DISPLAYING A CIRCULAR DOUBLE LINKEDLIST
void traverse_left_to_right()
{
    node*temp;
    temp=start;
    if(start==NULL)
    printf("EMPTY LIST..");
    else
    {
        printf("THE CONTENT OF LIST:");
        do
        {
         printf("%d->",temp->data);
         temp=temp->right;   /* code */
        } while (temp!=start);
        printf("x");
    }
    
}
    void traverse_right_to_left()
    {
        node*temp;
        temp==start;
        if(start==NULL)
        printf("EMPTY LIST..");
        else
        {
            printf("\nTHE CONTENT OF LIST:");
            do
            {
                temp=temp->left;
                printf("%d->",temp->data);
            } while (temp!=start);
            printf("x\n");
            printf("        ");
            
            
        }
    }
//INSERT CIRCULAR LINKEDLIST AT THE BEGINNING.
void insert_at_beg()
{
    
    node*newnode;
    newnode=getnode();
        if(start==NULL)
        {
            start=newnode;
            newnode->left=start;
            newnode->right=start;

    
        }
        else
        {
            newnode->left=start->left;
            newnode->right=start;
            start->left->right=newnode;
            start->left=newnode;
            start=newnode;
        }

    
    
}
//INSERT A NODE AT THE END OF A CIRCULAR DOUBLE LINKED LIST
void insert_at_end()

{
node*newnode,*temp;
newnode=getnode();
if(start==NULL) 
{
    start=newnode;
    newnode->left=start;
    

    newnode->right=start;
}
    else
    {
        newnode -> left = start ->left;
newnode -> right = start;
start -> left -> right=newnode;  
start -> left = newnode;


    }
}
//INSERT A NODE AT A INTERMEDIATE POSITION
int countnode()
{
    int count=1;
    node*temp;
    temp=start;
    do
    {
        count++;
        temp=temp->right;
    } while (temp->right!=start);
    return count;
    
}
void insert_pos()
{
    node*newnode,*temp;
    int pos,nodectr,i;
    newnode=getnode();
    printf("ENTER THE POSITION:");
    scanf("%d",&pos);
    nodectr=countnode();
    if(pos>nodectr+1)
    {
        printf("POSITION OUT OF RANGE..");
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
    printf("POSITION %d OF LIST IS NOT  A INTERMEDIATE POSITION");
}
//DELETE CIRCULAR DOUBLE LINKEDLIST FROM THE BEGINNING.
void delete_beg()
{
	node*temp;
	if(start==NULL)
	{
		printf("\n NO NODES EXIT.");
		return;
	}
    else
	
	{
		temp=start;
		start=start->right;
		temp->left->right=start;
		start->left=temp->left;
		free(temp);
		printf("\n NODE DELETED AT BEGINNING");
	}
}
//DELETE CIRCULAR DOUBLE LINKEDLIST FROM THE END.
void delete_end()
{
	node*temp;
	if(start==NULL)
	{
		printf("NO NODES EXIT");
		return;
	}
	else
	{
		temp=start;
		while(temp->right!=start)
		temp=temp->right;
		temp->left->right=temp->right;
		temp->right->left=temp->left;
		free(temp);
		printf("NODE DELETED FROM END");
	}
}
//DELETE CIRCULAR DOUBLE LINKEDLIST FROM THE INTERMEDIATE POSITION.
void delete_pos()
{
	int i,pos,nodectr;
	node*temp;
	if(start==NULL)
	{
		printf("NO NODES EXIST");
		return ;  
	}
	else
	{
		printf("ENTER THR POSITION OF THE NODE:");
		scanf("%d",&pos);
		nodectr=countnode();
		if(pos>nodectr)
		{
			printf("THE NODES DOES NOT EXIST");
			return;
		}
		else if(pos>1&&pos<nodectr)
		{
			temp=start;
			i=1;
			while(i<pos)
			{
				temp=temp->right;
				i++;
			}
			temp->right->left=temp->left;
			temp->left->right=temp->right;
			free(temp);
		}
		else
		{
			printf("IT IS NOT A INTERMEDIATE POSITION..");
		}
	}
	
}


int main()
{
    int num,ch;
    while(1)
    {
        printf("\n1.create a circular double linkedlist.\n");
         printf("2.insert at beg.\n");
          printf("3.insert at end.\n");
           printf("4.insert at pos.\n");
            printf("5.delete from beginning.\n");
            printf("6.delete from end.\n");
            printf("7.delete from intermediate position.\n");
            printf("8.display.\n");
             printf("9.exit");
             
              printf("\n\nENTER YOUR CHOICE:");
              scanf("%d",&ch);
              switch(ch)
              {
                case 1:
                 printf("\nENTER THE NUMBER OF ELEMENT YOU WANT TO INSERT:");
                 scanf("%d",&num);
                 createlist(num);
                 break;
                 case 2:
                 insert_at_beg();
                 break;
                 case 3:
                 insert_at_end();
                 break;
                 case 4:
                 insert_pos();
                 break;
                 case 5:
                 delete_beg();
                 break;
                 case 6:
                 delete_end();
                 break;
                 case 7:
                 delete_pos();
                 break;
                 case 8:
                 traverse_left_to_right();
                 traverse_right_to_left();
                 break;
                 case 9:
                 exit(0);
                 break;
                 default:
                 printf("WRONG CHOICE");
              }

    }
return 0;

}

