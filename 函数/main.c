#include <stdio.h>
#include <stdlib.h>
int susu(int a)
{
    int b,c=0;
    if(a==1)
        {
            c=1;
        }
    for(b=2; b<a; b++)
    {
        if(a%b==0)

        {
            c=1;
        }
    }
return c;
}
int main()
{
    int a;
    scanf("%d",&a);
    if(susu(a)==1)
        printf("����������");
    if(susu(a)==0)
        printf("��������");
            return 0;
}
