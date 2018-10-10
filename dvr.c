#include <stdio.h>

struct node
{
	int dist[20];
	int from[20];
}rt[10];

void main()
{
	int i,j,k,count,n,dm[20][20];
	printf("Enter number of nodes:\n");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&dm[i][j]);
			dm[i][i]=0;
			rt[i].dist[j]=dm[i][j];
			rt[i].from[j]=j;
		}
	}
	do
	{
		count=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(rt[i].dist[j]>dm[i][k]+rt[k].dist[j])
					{
						rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j]=k;
						count++;
					}
				}
			}
		}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		printf("\n\nFor router %d:",i+1);
		for(j=0;j<n;j++)
		{
			printf("\nNode %d via %d Distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
		}
	}
}