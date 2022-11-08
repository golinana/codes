#include<stdio.h>

float solve(float x)
{
    return x*x*x - 4*x - 9;
}

float mean(float x1, float x2)
{
    return (x1+x2)/2;
}

int main()
{
    int iterations;
    float a,b,c;
    int i;
    printf("Enter the number of iterations : ");
    scanf("%d",&iterations);
    
    for(i=0;i<iterations;i++)
    {
        printf("Enter the value of a and b ");
        scanf("%f %f",&a,&b);

        if(solve(a) * solve(b) <0)
            break;
        else
            printf("incorrect ");
    }

    float x1,x2;
    
    while(i<=iterations)
    {
    c=mean(a,b);
        if(solve(c)*solve(a)>0)
           a=c;
        else
           b=c;

        i++;

        printf("x1 : %f\t x2 : %f\t Mean : %f\n ",a,b,mean(a,b));
       // c=mean(a,b);
    }
    printf("REAL ROOT : x1 : %f\n",a);
}
