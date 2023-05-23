#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
#define inc 10
int count;
void worstarr(int *a,int n)
{
int i;
srand(time(0));
a[0]=rand()%10;
for(i=0;i<n-2;i+=2)
{
a[i+1]=a[i]+rand()%10;
a[i+2]=a[i+1]-rand()%10;
}
}
void copy(int *a,int l, int r, int *b)
{
int i=l;
int j=0;
while(i<r&&j<r)
b[j++]=a[i++];
}
void merge(int *b,int *c, int *a)
{
int i=0,j=0,k=0;
int n1=sizeof(b)/sizeof(b[0]);
int n2=sizeof(c)/sizeof(c[0]);
while(i<n1&&j<n2)
{
count++;
if(b[i]<=c[j])
a[k]=b[i++];
else 
a[k]=c[j++];
k++;
}
while(i<n1)
a[k++]=b[i++];
while(j<n2)
a[k++]=c[j++];
}
void mergesort(int *a,int n)
{
if(n>1)
{
count++;
int *b,*c;
copy(a,0,(n-1)/2,b);
copy(a,(n-1)/2,n-1,c);
mergesort(b,(n-1)/2);
mergesort(c,(n-1)/2);
merge(b,c,a);
}
}
void main()
{
int *a,i,n;
FILE *fp = fopen("MSortCount.txt","w");
srand(time(0));
for(n=x;n<=y;n+=inc)
{
a = (int*)malloc(n*sizeof(int));
//Best Case
a[0]=rand()%100;
for(i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
count=0;
mergesort(a,n);
fprintf(fp,"%d\t%d\t",n,count);

//Average Case
for(i=0;i<n;i++)
a[i]=rand()%100;
count=0;
mergesort(a,n);
fprintf(fp,"%d\t",count);

//Worst Case
worstarr(a,n);
count=0;
mergesort(a,n);
fprintf(fp,"%d\n",count);
}
fclose(fp);
system("gedit MSortCount.txt");
}
