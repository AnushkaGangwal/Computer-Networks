#include <stdio.h>
int str[100];

void main()
{
	int i,j,n,stuff,count;
	printf("Enter length of input string: ");
	scanf("%d",&n);
	printf("Enter input string as sequence of 1s and 0s:\n");
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);
	i=0;
	while(i<n)
	{
		if(str[i]==1)
		{
			stuff=1;
			for(j=i+1;j<i+6;j++)
			{
				if(str[j]!=1)
				{
					stuff=0;
					i=j;
					break;
				}
			}
			if(stuff==1)
			{
				n++;
				for(j=n-1;j>i+5;j--)
				{
					str[j]=str[j-1];
				}
				str[i+5]=0;
				i=i+5;
			}
		}
		else
			i++;
	}
	printf("Stuffed output:\n");
	for(i=0;i<n;i++)
		printf("%d ",str[i]);
	i=1;
	printf("\nUnstuffed output:\n");
	printf("%d ",str[0]);
	while(i<n)
	{
		if(str[i]==1)
		{
			printf("%d ",str[i]);
			i++;
		}
		else
		{
			count=0;
			for(j=i-1;j>=i-5;j--)
			{
				if(str[j]==1)
					count++;
				else 
					break;
			}
			if(count==5)
				i++;
			else
			{
				printf("%d ",str[i]);
				i++;
			}
		}
	}
}