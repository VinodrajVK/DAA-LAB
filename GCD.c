#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE *fpc;
int gcdm(int m, int n)
{
int r,count=0;
while(n!=0)
{
count++;
r = m%n;
m = n;
n = r;
}
fprintf(fpc,"%d\t",count);
return m;
}

int gcds(int m,int n)
{
int count=0;
while(m!=n)
{
count++;
if(m>n)
m=m-n;
else
n=n-m;
}
fprintf(fpc,"%d\t",count);
return m;
}

int gcdc(int m, int n)
{
int min,count=0;
min = (m<n)?m:n;
while(min!=1)
{
count++;
if(m%min==0)
  if(n%min==0)
    break;
min--;
}
fprintf(fpc,"%d\n",count);
return min;
}

void main()
{
FILE *fp = fopen("GCD.txt","w+");
fpc = fopen("GCDC.txt","w+");
fprintf(fp,"m\tn\tGCDM\tGCDS\tGCDC\n");
int m,n;
int gm,gs,gc;
srand(time(0));
for(int i=1;i<=10;i++)
{
m = (rand()+1)%1000;
n = (rand()+1)%1000;
fprintf(fpc,"%d\t%d\t",m,n);
gm = gcdm(m,n);
gs = gcds(m,n);
gc = gcdc(m,n);
fprintf(fp,"%d\t%d\t%d\t%d\t%d\n",m,n,gm,gs,gc);
}
fclose(fp);
fclose(fpc);
FILE *fg = fopen("plot.gnu","w");
fprintf(fg,"set yrange [0:*]\nset xlabel \"m\"\nset ylabel \"Count\"\nset term png\nset output \"GCDGraph.png\"\nplot \"GCDC.txt\" u 1:3 w l ti \"Modulo Method\", \"GCDC.txt\" u 1:4 w l ti \"Subtraction Method\", \"GCDC.txt\" u 1:5 w l ti \"Consecutive Integer Method\"\nset term x11");
fclose(fg);
system("gnuplot \"plot.gnu\"");
system("eog GCDGraph.png");
}

