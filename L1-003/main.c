#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
    scanf("%f",&num);
    while(1)
    {
        if(num%10==0)
        {
            n0++;
            num=num/10;
        }
        if(num%10==1)
        {
            n1++;
            num=num/10;
        }
        if(num%10==2)
        {
            n2++;
            num=num/10;
        }
        if(num%10==3)
        {
            n3++;
            num=num/10;
        }
        if(num%10==4)
        {
            n4++;
            num=num/10;
        }
        if(num%10==5)
        {
            n5++;
            num=num/10;
        }
        if(num%10==6)
        {
            n6++;
            num=num/10;
        }
        if(num%10==7)
        {
            n7++;
            num=num/10;
        }
        if(num%10==8)
        {
            n8++;
            num=num/10;
        }
        if(num%10==9)
        {
            n9++;
            num=num/10;
        }
        if(num<1)
            break;
    }
    if(n0>0)
    {
        printf("0:%d\n",n0);
    }
    if(n1>0)
    {
        printf("1:%d\n",n1);
    }
    if(n2>0)
    {
        printf("2:%d\n",n2);
    }
    if(n3>0)
    {
        printf("3:%d\n",n3);
    }
    if(n4>0)
    {
        printf("4:%d\n",n4);
    }
    if(n5>0)
    {
        printf("5:%d\n",n5);
    }
    if(n6>0)
    {
        printf("6:%d\n",n6);
    }
    if(n7>0)
    {
        printf("7:%d\n",n7);
    }
    if(n8>0)
    {
        printf("8:%d\n",n8);
    }
    if(n9>0)
    {
        printf("9:%d",n9);
    }
    return 0;
}
