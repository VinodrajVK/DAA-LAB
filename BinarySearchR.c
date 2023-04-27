#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count=0;
int bs(int *a,int b,int e,int key)
{
int mid = (b+e)/2;
if(a[mid]==key)
return mid;
if(b>e)
return -1;
if(a[mid]>key)
return bs(a,b,mid-1,key);
return bs(a,mid+1,e,key);
}
void main()
{
FILE *fp1,*fp2,*fp3,*fp4;
int *a,n,i,key,pos;
fp1 = fopen("bsearchr.txt","w");
fp2 = fopen("bsearchrb.txt","w");
fp3 = fopen("bsearchrw.txt","w");
fp4 = fopen("bsearchra.txt","w");
srand(time(0));
for(n=x;n<=y;n+=inc)
{
count=0;
a=(int *)malloc(n*sizeof(int));
fprintf(fp1,"\nArray :");
for(i=0;i<n;i++)
{
a[i]=rand()%100;
fprintf(fp1," %d",a[i]);
}
//Best case
key = a[(n-1)/2];
fprintf(fp1,"\nKey best case : %d\n",key);
pos=bs(a,0,n-1,key);
fprintf(fp1,"Best Case Position : %d\n",pos+1);
fprintf(fp2,"%d\t%d\n",n,count);
//Worst case
key = 9999;
fprintf(fp1,"Key worst case : %d\n",key);
pos=bs(a,0,n-1,key);
fprintf(fp1,"Worst Case Position : %d\n",pos+1);
fprintf(fp3,"%d\t%d\n",n,count);
//Average Case
key = a[3*(n-1)/4];
fprintf(fp1,"Key average case : %d\n",key);
pos=bs(a,0,n-1,key);
fprintf(fp1,"Average Case Position : %d\n",pos+1);
fprintf(fp4,"%d\t%d\n",n,count);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
}
