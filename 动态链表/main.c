#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node//�����ṹ��
{
    int value;//����ṹ������ݲ���
    struct node *next;//����ṹ���ָ�벿��
} lnode;//����������
int main()
{
    lnode *head=(lnode *)malloc(sizeof(lnode));//����һ��ͷָ�룬��Ϊ�俪�ٶ�̬�ڴ�
    lnode *flag=head;//ʹͷ�ڵ����ͷָ����λ�ڵ��ڴ�λ��
    scanf("%d",&flag->value);//����ڵ����������
    while(flag->value!=0)//����������0ʱ����
    {
        flag->next=(lnode *)malloc(sizeof(lnode));//Ϊ��һ���ڵ㴴��ָ�벿�֣���Ϊ�俪�ٶ�̬�ڴ�
        flag=flag->next;//ʹ��ǰѭ���ڵ�����ϸ��ڵ���ָ��ָ��λ��
        scanf("%d",&flag->value);//Ϊ��ǰѭ���ڵ���������
    }
    flag->next=NULL;//ʹ���һ���ڵ��ָ�벿�ֵ��ڿգ�Ҳ���ǽ�������
    flag=head;//ʹ�ڵ�ص�ͷ�ڵ�λ��
    while(flag!=NULL)//���ڵ�Ϊ�սڵ�ʱ����ֹ��ӡ
    {
        printf("%d ",flag->value);//�����ӡÿ���ڵ������
        flag=flag->next;//ÿ��ѭ��ʹ�ڵ�����ƽ�һλ
    }
    return 0;
}
