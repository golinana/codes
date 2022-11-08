//find root sof eqn 4x^3 - 4x -9.

#include<stdio.h>
#include<math.h>

float eqn(float x)
{
    return x*x*x - 4*x -9;
}

float derivative (float x)
{   
    return 3*x*2- 4;
}

int main()
{
    int a,b;

    while(1)
    {
        printf("Enter the value of a and b : ");
        scanf("%d %d",&a,&b);

        if(eqn(a)*eqn(b)<1)
        {
            break;
        }
        else
        {
            printf("Enter correct range\n ");
        }
    }
    printf("The root lies between %d and %d.\n ",a,b);

    float x,xn;
    
    x=(a+b)/2;

    while(1)
    {
        xn=x-(eqn(x)/derivative(x));
        printf("Root : %f\t Error : %f\n", xn,xn-x);
        if(fabs(xn-x)==0)
            break;
        x=xn;
    }
}
