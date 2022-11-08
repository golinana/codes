#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int n;


void printRes(int it, float values[n])
{
    printf("Iterations : %d\n",it);
    for(int i=0;i<n;i++)
        printf("%f\t",values[i]);
    printf("\n");
    
}

bool diagonallyDominating ( float a[n][n+1])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            float sum=0;
            if(i!=j)
                sum+=a[i][j];

            if(fabs(a[i][i] >sum ))
                continue;
            else
                return false;
        }
    }
    return true;
}

void gaussSeidal(float a[n][n+1])
{
    float sum;
    float values_old[n],values_new[n];
    for(int i=0;i<n;i++)
        values_old[i]=0;
    for(int i=0;i<n;i++)
        values_new[i]=0;
     int count=0;
    while(1)
    {
        count++;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
                if(i!=j)
                    sum+=a[i][j]*values_new[j] ;

            values_new[i]=(a[i][n]-sum)/a[i][i];
        }

        int flag=0;
        for(int k=0;k<n;k++)
        {
            if(fabs(values_new[k]- values_old[k]) <  0.01)
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Result found : ");
            printRes(count,values_new);
            return;
        }
        printRes(count,values_new);

        for(int l=0;l<n;l++)
            values_old[l]=values_new[l];
        
        

    }
}

int main()
{
    printf("Enter number of unknowns : ");
    scanf("%d",&n);
    float a[n][n+1];
    
    for(int i =0;i<n;i++)
        for(int j=0;j<n+1;j++)
            scanf("%f", &a[i][j]);
    
    if(!diagonallyDominating(a))
    {
        printf("We cannot apply Gauss-Seidal Method to solve this set of linear equations.\n");
        return -1;
    }

    gaussSeidal(a);

}

/*

3
27 6 -1 85
6 15 2 72
1 1 54 110

*/