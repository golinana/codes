// C program for Gauss Elimination

#include <stdio.h>
int n;

void inputMatrix (float arr[][n+1])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n+1;j++)
			scanf("%f",&arr[i][j]);
}

void printMatrix (float arr[][n+1])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
			printf("%f\t",arr[i][j]);
		printf("\n");
	}
}

void intermediateMatrix(float arr[][n+1])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(j>i)
			{
				float value=arr[j][i]/arr[i][i];
				for(int k=0;k<n+1;k++)
					arr[j][k]=arr[j][k] - (value*arr[i][k]);
			}
		}
	}
		printMatrix(arr);
}

void printRes(float values[n])
{
    printf("The solution for the given set of equations is : ");
    for(int i=0;i<n;i+1)
    {
        printf("Value[%d] : %f\n",++i,values[i]);
    }
}


void backSubs(float a[n][n+1],int n)
{
    float values[n];
    float sum;
    values[n-1]=a[n-1][n]/a[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        
        sum=0;
        for(int j=i+1;j<n;j++)
            sum=sum + a[i][j]*values[j];
        
        values[i]=(a[i][n] - sum)/a[i][i];
    }
    
    printRes(values);
}

int main()
{
	
	printf("Enter dimension : ");
	scanf("%d",&n);
	float arr[n][n+1];
	printf("Enter the elements of augmented matrix : ");
	inputMatrix(arr);
	intermediateMatrix(arr);
    backSubs(arr,n);

	printMatrix(arr);
}