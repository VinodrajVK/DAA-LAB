#include <stdlib.h>
#include <time.h>
void main()
{
int i,j,a[10];
srand(time(0));
a[0]=rand()%10;

a[10/2]=rand()%10;
for(i=0,j=10/2;j<10-2;i+=2,j+=2)
{
a[i+1]=a[0]+rand()%100;
a[i+2]=a[i+1]-rand()%10;
a[j+1]=a[10/2]+rand()%100;
a[j+2]=a[j+1]-rand()%10;
}
a[10/2-1]=a[10/2-2]+rand()%10;
a[10-1]=a[10-2]+rand()%10;
for(i=0;i<10;i++)
printf("%d\t",a[i]);
}
