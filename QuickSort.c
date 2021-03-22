#include<stdio.h>
void quicksort_r(int a[],int l,int r)
{
    int q1,choice;
    if(l<r)
    {
        q1=partion_r(a,l,r);
        quicksort_r(a,l,q1-1);
        quicksort_r(a,q1+1,r);
    }
}
int partion_r(int a[],int l,int r)
{
    int i,j,pivot,temp;
    pivot=a[r];
    i=l-1;
    for(j=l; j<=r-1; j++)
    {
        if(a[j]<pivot)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[r];
    a[r]=a[i+1];
    a[i+1]=temp;
    return i+1;
}
void quicksort_l(int a[],int l,int r)
{
    int q2,choice;
    if(l<r)
    {
        q2=partion_l(a,l,r);
        quicksort_l(a,l,q2-1);
        quicksort_l(a,q2+1,r);
    }
}

int partion_l(int a[],int l,int r)
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
    int i,n,a[10000],choice;
    printf("Enter the total number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter 1 or 2:\n1.Use last element as pivot\n2.Use first element as pivot\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        quicksort_r(a,0,n-1);
        printf("Using last element as pivot the sorted elements: ");
        for(i=0; i<n; i++)
            printf("%d ",a[i]);
    }
    else if(choice==2)
    {
        quicksort_l(a,0,n-1);
        printf("Using last element as pivot the sorted elements: ");
        for(i=0; i<n; i++)
            printf("%d ",a[i]);
    }
    return 0;
}
