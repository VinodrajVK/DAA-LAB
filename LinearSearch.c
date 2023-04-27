#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count;
void ls(int *a,int n,int key)
{
count=0;
for(int i=0;i<n;i++)
{
count++;
if(a[i]==key)
return;
}
}
void main()
{
FILE *fp1,*fp2,*fp3,*fp4;
int *a,n,i,key;
fp1 = fopen("lsearch.txt","w");
fp2 = fopen("lsearchb.txt","w");
fp3 = fopen("lsearchw.txt","w");
fp4 = fopen("lsearcha.txt","w");
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
//Best Case
key = a[0];
fprintf(fp1,"\nKey best case : %d\n",key);
ls(a,n,key);
fprintf(fp2,"%d\t%d\n",n,count);

//Worst case
key = 9999;
fprintf(fp1,"Key worst case : %d\n",key);
ls(a,n,key);
fprintf(fp3,"%d\t%d\n",n,count);

//Average Case
key = a[n/2];
fprintf(fp1,"Key average case : %d\n",key);
ls(a,n,key);
fprintf(fp4,"%d\t%d\n",n,count);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
FILE *fg = fopen("plot.gnu","w");
fprintf(fg,"set yrange [0:*]\nset xlabel \"n\"\nset ylabel \"t\"\nplot \"lsearchb.txt\" w l ti \"Best Case\", \"lsearchw.txt\" w l smooth bezier ti \"Worst Case\", \"lsearcha.txt\" w l ti \"Average Case\"\nset term png\nset output \"LSGraph.png\"\nreplot\nset term x11");
fclose(fg);
system("gnuplot \"plot.gnu\"");
system("eog LSGraph.png");
}
