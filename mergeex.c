#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
int i,a[10];
srand(time(0));
a[0]=rand()%10;
for(i=0;i<8;i+=2)
{
a[i+1]=a[i]+rand()%10;
a[i+2]=a[i+1]-rand()%10;
}
for(i=0;i<10;i++)
printf("%d ",a[i]);
}
