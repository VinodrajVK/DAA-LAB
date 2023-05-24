#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count;
int bs(int *a,int l,int r,int key)
{
if(l>r)
return -1;
int mid = (l+r)/2;
count++;
if(a[mid]==key)
return mid;
if(a[mid]>key)
return binarysearch(a,l,mid-1,key);
return binarysearch(a,mid+1,r,key);
}
void main()
{
FILE *fp1,*fp2;
int *a,n,i,key,pos;
fp1 = fopen("bsearchr.txt","w");
fp2 = fopen("bsearchrcount.txt","w");
srand(time(0));
for(n=x;n<=y;n+=inc)
{
a=(int *)malloc(n*sizeof(int));
fprintf(fp1,"\nArray :");
a[0]=rand()%100;
for(i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;

//Best case
key = a[(n-1)/2];
count=0;
fprintf(fp1,"\nKey best case : %d\n",key);
pos=binarysearch(a,0,n-1,key);
fprintf(fp1,"Best Case Position : %d\n",pos+1);
fprintf(fp2,"%d\t%d\t",n,count);

//Average Case
key = a[(n-1)/4];
count=0;
fprintf(fp1,"Key average case : %d\n",key);
pos=binarysearch(a,0,n-1,key);
fprintf(fp1,"Average Case Position : %d\n",pos+1);
fprintf(fp2,"%d\t",count);

//Worst case
key = 9999;
count=0;
fprintf(fp1,"Key worst case : %d\n",key);
pos=binarysearch(a,0,n-1,key);
fprintf(fp1,"Worst Case Position : %d\n",pos+1);
fprintf(fp2,"%d\n",count);
}
fclose(fp1);
fclose(fp2);
system("gedit bsearchr.txt bsearchrcount.txt");
}
