#include<stdio.h>

float solve(float x)
{
    return x*x*x - 4*x - 9;
}

float formula(float x0, float x1)
{
    float fx0=solve(x0);
    float fx1=solve(x1);
    float res;
    res=((x0*fx1)-(x1*fx0))/(fx1-fx0);
    return res;
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
    int count=1;
    while(i<=iterations)
    {
        c=formula(a,b);
        if(solve(c)*solve(a)>0)
           a=c;
        else
           b=c;

        i++;

        printf("x%d :  %f\t F(x) : %f\n",count++,a,solve(c) );
        
    }
    printf("Real Root : x :  %f F(x) : %f\n",a,solve(c) );
}
