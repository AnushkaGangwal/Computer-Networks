#include <stdio.h>
#include <string.h>

void main()
{
	int i,n,k,length,m,j=0,count,escape,frame=1;
	char data[30],output[200],c[30];
	printf("Enter the number of frames: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter data for frame %d \n",i+1);
		scanf("%s",data);
		length=strlen(data);
		output[j]='#';
		count=0;
		k=0;
		while(k!=length+count)
		//for(k=0;k<length;k++)
		{
			if(data[k]=='#' || data[k]=='$')
			{
				for(m=length+count;m>k;m--)
					data[m]=data[m-1];
				data[k]='$';
				count++;
				k=k+2;
			}
			else
				k++;
		}
		data[length+count]='#';
		for(k=0;k<=length+count;k++)
			output[++j]=data[k];
		j++;
	}
	output[j]='\0';
	printf("Recieved packet:\n");
	printf("%s\n",output);
	i=0;
	j=0;
	while(output[i]!='\0')
	{
		if(output[i]=='#')
		{
			m=0;
			j=i+1;
			while(output[j]!='#')
			{
				if(output[j]=='$')
				{
					for(k=i+1;k<j;k++)
						data[m++]=output[k];
					data[m++]=output[j+1];
					j=j+2;
					i=j;
					escape=1;
				}
				else
				{
					escape=0;
					j++;
				}
			}
			if(escape==0)
			{
				for(k=i+1;k<j;k++)
					data[m++]=output[k];
				i=j;
			}
			data[m++]='\0';
			j++;
			i++;
			printf("Frame %d: %s\n",frame++,data);
		}
	}
}