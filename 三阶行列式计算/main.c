#include<stdio.h>
int main()

{
    int select;
    printf("������һ������ʽ���ÿո�ֿ����س����С�������ظ�����\n");
    printf("��������ʽ�밴 3\n��������ʽ�밴 2\n�����س�ȷ��\n");
    scanf("%d",&select);
    if(select!=3&&select!=2)
    {
        printf("�����������������룺");
        scanf("%d",&select);
    }
    if (select==3)
    {
        printf("��������������ʽ\n");
        while(1)
        {
            int i,a[3][3],j,sum1,sum2,sum;
            for(i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                    scanf("%d",&a[i][j]);
            }
            sum1=a[0][2]*a[1][0]*a[2][1]+a[0][1]*a[1][2]*a[2][0]+a[0][0]*a[1][1]*a[2][2];
            sum2=a[2][2]*a[0][1]*a[1][0]+a[2][1]*a[1][2]*a[0][0]+a[0][2]*a[1][1]*a[2][0];
            sum=sum1-sum2;
            printf("���Ϊ��%d\n",sum);
        }
    }
    if(select==2)
    {
        printf("�������������ʽ\n");
        while(1)
        {
            int i,a[2][2],j,sum1,sum2,sum;
            for(i=0; i<2; i++)
            {
                for(j=0; j<2; j++)
                    scanf("%d",&a[i][j]);
            }
            sum1=a[0][0]*a[1][1];
            sum2=a[1][0]*a[0][1];
            sum=sum1-sum2;
            printf("���Ϊ��%d\n",sum);
        }
    }
}
