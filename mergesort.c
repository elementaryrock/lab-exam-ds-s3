#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int temp[high-low+1];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=high){
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++){
        a[i]=temp[i-low];
    }
}

void mergesort(int a[],int low,int high)
{
    if(low<high){
        {
            int mid =(low+high)/2;
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            merge(a,low,mid,high);
        }
    }
}

void main(){
    int a[10],n,low=0,high,i;
    printf("\nEnter array size: \n");
    scanf("%d",&n);
    high=n-1;
    printf("\nEnter array elements: \n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,low,high);
    for (i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}