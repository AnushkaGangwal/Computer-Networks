#include <stdio.h>
#include <unistd.h>

void main()
{
  int bucket[20],i,n;
  double rate;

  printf("Enter bucket size: ");
  scanf("%d",&n);

  printf("Enter rate of output (packets/sec): ");
  scanf("%lf",&rate);

  printf("Enter input:\n");
  for(int i=0;i<n;i++)
    scanf("%d",&bucket[i]);
  
  printf("Bucket Full\n");
  for(i=0;i<n;i++)
  {
    printf("Packet: %d\n",bucket[i]);
    usleep((1/rate)*1000000);
  }     
}