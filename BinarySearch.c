#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count;
void bs(int *a,int b, int e,int key)
{
int mid;
count=0;
while(b<=e)
{
count++;
mid=(b+e)/2;
if(a[mid]==key)
return;
if(a[mid]>key)
e=mid-1;
else
b=mid+1;
}
}
void main()
{
FILE *fp1,*fp2,*fp3,*fp4;
int *a,n,i,key;
fp1 = fopen("bsearch.txt","w");
fp2 = fopen("bsearchb.txt","w");
fp3 = fopen("bsearchw.txt","w");
fp4 = fopen("bsearcha.txt","w");
srand(time(0));
for(n=x;n<=y;n+=inc)
{
a=(int *)malloc(n*sizeof(int));
fprintf(fp1,"\nArray :");
a[0]=rand()%100;
for(i=1;i<n;i++)
a[i]=rand()%100;
for(i=0;i<n;i++)
fprintf(fp1," %d",a[i]);

//Best Case
key = a[(n-1)/2];
fprintf(fp1,"\nKey best case : %d\n",key);
bs(a,0,n-1,key);
fprintf(fp2,"%d\t%d\n",n,count);

//Worst case
//key = a[0];
key=9999;
fprintf(fp1,"Key worst case : %d\n",key);
bs(a,0,n-1,key);
fprintf(fp3,"%d\t%d\n",n,count);

//Average case
key = a[3*(n-1)/4];
fprintf(fp1,"Key average case : %d\n",key);
bs(a,0,n-1,key);
fprintf(fp4,"%d\t%d\n",n,count);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
FILE *fg = fopen("plot.gnu","w");
fprintf(fg,"set yrange [0:10]\nset xlabel \"n\"\nset ylabel \"t\"\nplot \"bsearchb.txt\" w l ti \"Best Case\", \"bsearchw.txt\" w l smooth bezier ti \"Worst Case\", \"bsearcha.txt\" w l ti \"Average Case\"\nset term png\nset output \"BSGraph.png\"\nreplot\nset term x11");
fclose(fg);
system("gnuplot \"plot.gnu\"");
system("eog BSGraph.png");
}
