#include <stdio.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
FILE *fc;
void match(char *t, int n, char *p, int m)
{
int i,j,count=0;
for(i=0;i<n-m;i++)
{
j=0;
while(j<m)
{
count++;
  if(t[i+j]!=p[j]))
    break;
j++;
}
if(j==m)
break;
}
fprintf(fc,"%d\t",count);
}
void main()
{
int i,n,count,m=3;
char *t;
fc = fopen("strmatch.txt","w");
for(n=x;n<=y;n+=inc)
{
t=(char *)malloc(n*sizeof(char));
for(i=0;i<n;i++)
t[i]='a';
fprintf(fc,"%d\t",n);
//Best case
char pb[3]="aaa";
match(t,n,pb,3);

//Average Case
char pa[3]="aba";
match(t,n,pa,3);

//Worst case
char pw[3]="aab";
match(t,n,pw,3);

fprintf(fc,"\n");
}
fclose(fc);
}
