#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define  MAXSIZE   100 /*���Ա����󳤶�*/
typedef int Status;
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */
/* ˳��ջ�ṹ */
typedef struct
{
    SElemType data[MAXSIZE];
    int top; /* ����ջ��ָ�� */
}SqStack;


SqStack *InitStack()
{
    SqStack *S=(SqStack *)malloc(sizeof(SqStack));
    S->top=-1;
    return S;
}
/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1)return ERROR; /* ջ�� */
        S->top++;  /* ջ��ָ���1 */
        S->data[S->top]=e;
        return OK;
}
/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack *S,SElemType *e)
{
        if(S->top==-1)return ERROR;
        *e=S->data[S->top];  /* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
        S->top--;    /* ջ��ָ���1 */
        return OK;
}
void Dec2R(int r, int d)//ʮ������dת��Ϊr������
{
    int x = 0 ;
    SqStack* s= InitStack() ;
    while(d > 0)
    {
        Push(s, d % r) ;
        d = d / r ;
    }
    while(s->top != -1)
    {
        Pop(s, &x) ;
        printf("%d", x) ;
    }
    printf("\n") ;
    free(s);
}


int main()
{
    Dec2R(2,13);
    return 0;
}
