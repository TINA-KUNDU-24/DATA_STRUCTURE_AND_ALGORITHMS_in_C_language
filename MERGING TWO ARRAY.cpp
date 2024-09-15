#include<stdio.h>
int main()

{
	int arr1[10],arr2[10],s1,s2,i,k,merge_arr[10];
	printf("ENTER THE SIZE OF ARRAY 1: ");
	scanf("%d",&s1);
	
	printf("ENTER THE ELEMENT OF ARRAY 1: ");
	for(i=0;i<s1;i++)
	{
		scanf("%d",&arr1[i]);
		merge_arr[i]=arr1[i];
	}
	printf("ENTER THE SIZE OF ARRAY 2: ");
	scanf("%d",&s2);
	k=i;
	
	printf("ENTER THE ELEMENTS OF ARRAY 2: ");
	for(i=0;i<s2;i++)
	{
		scanf("%d",&arr2[i]);
		merge_arr[k]=arr2[i];
		k++;
	}
	printf("ENTER THE NEW ARRAY AFTER MERGING:  ");
	for(i=0;i<k;i++)
	printf("%d	",merge_arr[i]);
	return 0;
	
	


}
