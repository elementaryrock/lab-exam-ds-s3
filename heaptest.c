#include<stdio.h>
void heap(int a[],int n,int i)
{
    int largest=i,temp,r,l;
    l=2*i+1;
    r=2*i+2;
    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heap(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)
    {
        heap(a,n,i);
    }
    printf("\nMax heap is: \n");
    for (i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heap(a,i,0);
    }
}
void main(){
    int i,n,a[10];
    printf("\nEnter array size: \n:");
    scanf("%d",&n);
    printf("\nEnter array elements: \n:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("\nThe sorted array is: \n:");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}