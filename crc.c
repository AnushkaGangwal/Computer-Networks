#include <stdio.h>
#include <string.h>

char xor(char x,char y)
{
	if((x=='1' && y=='1') || (x=='0' && y=='0'))
		return '0';
	else
		return '1';
}

void main()
{
	int i,j,k,polylen,genlen;
	char poly[30],gen[10],msg[30];
	printf("Enter data string:\n");
	scanf("%s",poly);
	printf("Enter generator:\n");
	scanf("%s",gen);
	strcpy(msg,poly);
	polylen=strlen(poly);
	genlen=strlen(gen);
	for(i=polylen;i<polylen+genlen-1;i++)
		msg[i]='0';
	msg[i]='\0';
	printf("Appended string is:\n%s",msg);
	for(i=0;i<polylen;i++)
	{
		if(msg[i]=='1')
		{
			for(j=0,k=i;j<genlen;j++,k++)
				msg[k]=xor(msg[k],gen[j]);
		}
	}
	printf("\nRemainder is:\n%s",msg);
	printf("\nCRC is:\n%s",poly);
	for(i=polylen;i<polylen+genlen-1;i++)
		printf("%c",msg[i]);
}