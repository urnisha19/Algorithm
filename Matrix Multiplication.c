#include<stdio.h>
int main()
{
    int i,j,k,row1,col1,row2,col2,A[10][10],B[10][10],AB[10][10],sum=0;

    printf("Enter the number of row and column of A matrix\n");
    scanf("%d %d",&row1,&col1);

    printf("Enter the elements:\n");
    for(i=0; i<row1; i++)
    {
        for(j=0; j<col1; j++)
        {
            printf("A[%d][%d]= ",i,j);
            scanf("%d",&A[i][j]);
        }
    }

    printf("Enter the number of row and column of B matrix\n");
    scanf("%d %d",&row2,&col2);

    printf("Enter the elements:\n");
    for(i=0; i<row2; i++)
    {
        for(j=0; j<col2; j++)
        {
            printf("B[%d][%d]= ",i,j);
            scanf("%d",&B[i][j]);
        }
    }

    if(row1!=col2)
    {
        printf("Can't be multiplied\n");
    }
    else
    {
        printf("Product matrix AB:\n");
        for(i=0; i<row1; i++)
        {
            for(j=0; j<col2; j++)
            {
                sum=0;
                for(k=0; k<col1; k++)
                {
                    sum+=A[i][k]*B[k][j];
                    AB[i][j]=sum;
                }
                printf("%d ",AB[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
