#include<stdio.h>
#include<stdlib.h>
int main()
{
    float a,b;
    char op;
    while(scanf("%f%c%f",&a,&op,&b)!=EOF)
    {
        switch(op)
        {
        case('+'):
            printf("%f\n",a+b);
            break;
        case('-'):
            printf("%f\n",a-b);
            break;
        case('*'):
            printf("%f\n",a*b);
            break;
        case('/'):
            printf("%f\n",a/b);
            break;
        default:
            printf("����������������\n");
        }
    }
}

