#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define inc 10
int cnt;
void bsort(int *a,int n){
	int i,j,t,flag=0;
	cnt=0;
	for(i=0;i<n-1;i++){flag=0;
		for(j=0;j<n-1-i;j++){
			cnt++;
			if(a[j]>a[j+1]){
				flag=1;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				}
			}
		if(flag==0)break;
		}
	}

void main(){
	int n,i;
	int *a;
	FILE *b,*w,*avg,*ba,*wa,*avga;
	srand(time(0));
	b=fopen("bsortb.txt","w");
	w=fopen("bsortw.txt","w");
	avg=fopen("bsortavg.txt","w");
	ba=fopen("bsortba.txt","w");
	wa=fopen("bsortwa.txt","w");
	avga=fopen("bsortavga.txt","w");
	for(n=x;n<=y;n+=inc){
		cnt=0;
		a=(int*)malloc(n*sizeof(int));
		
		//average case
		fprintf(avga,"\nArray:");
		for(i=0;i<n;i++){
			a[i]=rand()%100;
			fprintf(avga," %d",a[i]);
			}
		bsort(a,n);
		fprintf(avg,"%d\t%d\n",n,cnt);

		//worst case
		cnt=0;
		fprintf(wa,"\nArray:");
		a[n-1]=rand()%100;
		for(i=n-1;i>0;i--){
			a[i-1]=a[i]+rand()%100;
			//fprintf(wa," %d",a[i]);
			}
		for(i=0;i<n;i++)
			fprintf(wa," %d",a[i]);
		bsort(a,n);
		fprintf(w,"%d\t%d\n",n,cnt);
		
		//best case
		cnt=0;
		fprintf(ba,"\nArray:");
		a[0]=rand()%100;
		for(i=1;i<n;i++){
			a[i]=a[i-1]+rand()%100;
			fprintf(ba," %d",a[i]);
			}
		bsort(a,n);
		fprintf(b,"%d\t%d\n",n,cnt);
		}
		fclose(avg);
		fclose(avga);
		fclose(b);
		fclose(ba);
		fclose(w);
		fclose(wa);
		free(a);
		FILE *fg = fopen("plot.gnu","w");
fprintf(fg,"set yrange [0:*]\nset xlabel \"n\"\nset ylabel \"t\"\nset term png\nset output \"BSortGraph.png\"\nplot \"bsortb.txt\" w l ti \"Best Case\", \"bsortw.txt\" w l smooth bezier ti \"Worst Case\", \"bsortavg.txt\" w l ti \"Average Case\"\nset term x11");
fclose(fg);
system("gnuplot \"plot.gnu\"");
system("eog BSortGraph.png");

	
}
	
