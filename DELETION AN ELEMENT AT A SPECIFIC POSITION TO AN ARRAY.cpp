#include<stdio.h>
int main()
{
	int arr[10],i,n,val,pos;
	printf("ENTER THE SIZE OF AN ARRAY: ");
	scanf("%d",&n);
	
	printf("ENTER THE ELEMENT OF AN ARRAY: ");
	for(i=0;i<n;i++)
	{
	
	scanf("%d",& arr[i]);
   }
	printf("ENTER THE POSITION WHERE YOU WANT TO DELETE: ");
	scanf("%d",& pos);
	for(i=pos-1;i<n;i++)
	{
		arr[i]=arr[i+1];
	}
	printf("THE RESULTANT ARRAY: ");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
	
}
