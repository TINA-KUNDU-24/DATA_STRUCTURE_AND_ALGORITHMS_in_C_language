 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<malloc.h>
 struct st
 {
 	int data;
 	struct st*next;
 };
 typedef struct st queue;
 queue*front=NULL;
 queue*rear=NULL;
 
 void insert();
 void deletion();
 void display();
 
 int main()
 {
 	int n,ch;
 	while(1)
 	{
 	printf("\n1.INSERT..");
 	printf("\n2.DELETE..");
 	printf("\n3.DISPLAY..");
 	printf("\n4.EXIT..");
 	
 	printf("ENTER YOUR CHOICE: ");
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
	default:printf("\nWRONG CHOICE..");	
	}
    }
    return 0;
 }
 
 void insert()
 {
 	queue*temp;
 	int item;
 	printf("\nENTER THE ELEMENT TO BE INSERTED: ");
 	scanf("%d",&item);
 	temp=(queue*)malloc(sizeof(queue));
 	temp->data=item;
 	temp->next=NULL;
 	if(rear==NULL)
 	{
 		front=temp;
 		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=rear->next;
	}
 	
 }
 
 void deletion()
 {
 	queue*temp;
 	int item;
 	temp=front;
 	if(front==NULL)
 	{
 	rear=NULL;
	 printf("\nQUEUE IS EMPTY..");	
	}
	else
	{
		item=temp->data;
		front=temp->next;
		free(temp);
		printf("\n%d IS DELETED",item);
	}
 }
 
 void display()
 {
 	queue*temp;
 	if(front==NULL)
 	printf("\nTHE QUEUE IS EMPTY..");
 	else
    {
 		printf("\nTHE ELEMENTS OF THE QUEUE ARE: ");
 		temp=front;
 		while(temp!=NULL)
 		{
 			printf("%d	",temp->data);
 			temp=temp->next;
		 }
	}
 	
 }
