#include <stdio.h>
#include <string.h>

void main()
{
	int i,n,k,length,j=0,count=1;
	char data[30],output[200],c[30];
	printf("Enter the number of frames: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter data for frame %d \n",i+1);
		scanf("%s",data);
		length=strlen(data);
		output[j]=length+1+48;
		for(k=0;k<length;k++)
		{
			output[++j]=data[k];
		}
		j++;
	}
	output[j]='\0';
	printf("Recieved packet:\n");
	printf("%s\n",output);
	i=0;
	while(output[i]!='\0')
	{
		length=output[i]-48-1;
		for(k=0;k<length;k++)
		{
			data[k]=output[++i];
		}
		data[k]='\0';
		i++;
		printf("Frame %d: %s\n",count++,data);
	}
}