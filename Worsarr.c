int join(int arr[],int left[],int right[],int l,int m,int r){
    int i,j;
    for(i=0;i<=m-l;i++)
        arr[i]=left[i];
    for(j=0;j<r-m;j++)
        arr[i+j]=right[j];
}

int split(int arr[],int left[],int right[],int l,int m,int r){
    for(int i=0;i<=m-l;i++)
        left[i]=arr[i*2];
    for(int j=0;j<r-m;j++)
        right[j]=arr[j*2+1];
}

int genWorstCase(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        int left[m-l+1];
        int right[r-m];
        split(arr,left,right,l,m,r);
        genWorstCase(left,l,m);
        genWorstCase(right,m+1,r);
        join(arr,left,right,l,m,r);
    }
}
