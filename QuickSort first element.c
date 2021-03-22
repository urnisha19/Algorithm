#include<stdio.h>
void quicksort(int a[],int l,int r)
{
    int q;
    if(l<r)
    {
        q=partion(a,l,r);
        quicksort(a,l,q-1);
        quicksort(a,q+1,r);
    }
}
int partion(int a[],int l,int r)
{
    int i, j,pivot,temp;
    pivot=a[l];
    i=l+1;
    for(j=l+1; j<=r; j++)
    {
        if(a[j]<pivot)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=i+1;
        }
    }
    temp=a[l];
    a[l]=a[i-1];
    a[i-1]=temp;
    return i-1;
}
int main()
{
    int i,n,a[10000];
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("Sorted elements: ");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}
