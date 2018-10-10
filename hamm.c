#include <stdio.h>

void main()
{
	int i,data[7],rec[7],p1,p2,p4,p;
	printf("7-BIT EVEN PARITY HAMMING CODE:\n\n");
	printf("Enter data string to be encoded:\n");
	scanf("%d %d %d %d",&data[0],&data[1],&data[2],&data[4]);
	data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
	printf("Hamming code is:\n");
	for(i=0;i<7;i++)
		printf("%d",data[i]);
	printf("\n");
	printf("\nEnter received code:\n");
	for(i=0;i<7;i++)
		scanf("%d",&rec[i]);
	p1=rec[6]^rec[4]^rec[2]^rec[0];
	p2=rec[5]^rec[4]^rec[1]^rec[0];
	p4=rec[3]^rec[2]^rec[1]^rec[0];
	p=4*p4+2*p2+p1;
	if(p==0)
		printf("Received code is correct!\n");
	else
	{
		printf("Error at position %d\n",p);
		printf("Correct code is:\n");
		if(rec[7-p]==0)
			rec[7-p]=1;
		else
			rec[7-p]=0;
		for(i=0;i<7;i++)
			printf("%d",rec[i]);
	}
}