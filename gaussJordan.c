#include<stdio.h>
int n;

void printMatrix(float a[][n+1])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for( j=0;j<n+1;j++)
            printf("%4.2f ",a[i][j]);
        printf("\n");
    }
}

void printResult(float a[][n+1])
{
    int c=0;
    for (int i=0;i<n;i++)
        printf("Root%d = %.2f \n",i+1,(a[i][n]/a[i][i]));
}

void diagonalMatrix(float a[][n+1])
{

    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){

            if(j!=i)
            {
                float ratio= a[j][i]/a[i][i];
                for(int k=0;k<n+1;k++)
                    a[j][k]=a[j][k] - (ratio*a[i][k]);
            }
        }
    }
    printMatrix(a);
}

int main()
{
    printf("Enter the dimensions of the matrix : ");
    scanf("%d",&n);

    float a[n][n+1];
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            scanf("%f",&a[i][j]);

    diagonalMatrix(a);

    printMatrix(a);

    printResult(a);
}