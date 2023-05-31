#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define inc 10
int count;
void ssort(int *a,int n){
	int i,j,t,min;
	count=0;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			count++;
			if(a[j]<a[min])
				min=j;
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
		}
	}

void main(){
	int n,i;
	int *a;
	FILE *fp,*fpc;
	fp = fopen("SSort.txt","w");
	fpc = fopen("SSortCount.txt","w");
	srand(time(0));
	for(n=x;n<=y;n+=inc){
		a=(int*)malloc(n*sizeof(int));

		fprintf(fp,"\nArray:");
		for(i=0;i<n;i++)
			{
			a[i]=rand()%100;
			fprintf(fp," %d",a[i]);
			}
		ssort(a,n);
		fprintf(fpc,"%d\t%d\n",n,count);
		}
		fclose(fp);
		fclose(fpc);
		free(a);
		FILE *fg = fopen("plot.gnu","w");
fprintf(fg,"set yrange [0:*]\nset xlabel \"Input\"\nset ylabel \"Operation Count\"\nset term png\nset output \"SSortGraph.png\"\nplot \"SSortCount.txt\" w l ti \"Selection Sort\"\nset term x11");
fclose(fg);
system("gnuplot \"plot.gnu\"");
system("eog SSortGraph.png");	
}
	
