#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define NULL 0
struct student
{
    char num[20];
    char name[20];
    float cscore;
    float mscore;
    float escore;
};//���ݽṹ��
typedef struct Node
{
    //int data;
    struct student data;
    struct Node *next;
} LNode;
LNode *create(int n);
void printl(LNode *head);
void LocateByNum(LNode *head);
int s=0;
int main()
{
    int n;
    printf("\n\n\t|********��ӭ����ѧ����Ϣ����ϵͳ*******************|\n");
    printf("\t|*********1.¼��ѧ����Ϣ****************************|\n");
    printf("\t|*********2.��ʾѧ����Ϣ****************************|\n");
    printf("\t|*********3.��ѯѧ����Ϣ****************************|\n");
    printf("\t|*********4.�޸�ѧ����Ϣ****************************|\n");
    printf("\t|*********5.���ѧ����Ϣ****************************|\n");
    printf("\t|*********6.ɾ��ѧ����Ϣ****************************|\n");
    printf("\t|*********7.���ܷ�������****************************|\n");
    printf("\t|*********0.�˳�************************************|\n");
    while(1)
    {
        int s;
        LNode *Head;
        printf("��������Ҫ�������ܵ���ţ�");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            printf("������¼��ѧ��������");
            scanf("%d",&n);
            Head=create(n);
            break;
        case 2:
            printf("ѧ��             ����    ���ĳɼ�       ��ѧ�ɼ�         Ӣ��ɼ�\n");
            printl(Head);
            break;
        case 3:
            printf("������Ҫ��ѯ��ѧ��:");
            LocateByNum(Head);
            break;
        case 4:
            printf("������Ҫ�޸����ݶ�Ӧ��ѧ�ţ�");
            change(Head);
            break;
        case 5:
            Insert(Head,n);
            break;
        case 6:
            DeleteByNum(Head);
            break;
        case 7:

            break;
        case 0:
            FreeAll(Head);
            system("cls");
            exit(0);
            break;
        }
    }

}
LNode *create(int n)
{
    char tnum[20];
    LNode  *head,*pnew,*prear;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    //for(i=0;i<n;i++)Insert_LinkList(head,i+1,i*i);
    prear=head;
    for(i=0; i<n; i++)
    {
        pnew=(LNode *)malloc(sizeof(LNode));
A:
        printf("�������%d��ѧ��ѧ�ţ�",i+1);
        scanf("%s",tnum);
        if (strspn(tnum,"0123456789")==strlen(tnum))
        {
            strcpy(pnew->data.num,tnum);
        }
        else
        {
            printf("ѧ����������!\n");
            goto A;
        }
        printf("�������%d��ѧ��������",i+1);
        scanf("%s",pnew->data.name);
        printf("�������%d��ѧ�����ĳɼ���",i+1);
        scanf("%f",&pnew->data.cscore);
        printf("�������%d��ѧ����ѧ�ɼ���",i+1);
        scanf("%f",&pnew->data.mscore);
        printf("�������%d��ѧ��Ӣ��ɼ���",i+1);
        scanf("%f",&pnew->data.escore);
        prear->next=pnew;
        prear=pnew;
    }
    pnew->next=NULL;
    return head;
}
void printl(LNode *head)
{
    LNode *p=head->next;/* pָ���һ��Ԫ�ؽ��*/
    while(p!=NULL )
    {
        printf("%s      %s     %f       %f        %f\n",p->data.num,p->data.name,p->data.cscore,p->data.mscore,p->data.escore);
        p=p->next;
    }
}
void LocateByNum(LNode *head)
{
    char tnum[20];
    int i=0;
    LNode  *p=head->next;
    scanf("%s",tnum);
    while(p!=NULL)
    {
        if(strcmp(p->data.num,tnum)==0)
        {
            printf("ѧ��             ����    ���ĳɼ�       ��ѧ�ɼ�         Ӣ��ɼ�\n");
            printf("%s      %s     %f       %f        %f\n",p->data.num,p->data.name,p->data.cscore,p->data.mscore,p->data.escore);
            i=1;
            break;
        }
        p=p->next;
    }
    if(i==0)
        printf("û�и�ѧ����Ϣ��\n");
}
LNode * GetElem(LNode *head, int  i)/*�ڵ�����head�в��ҵ�i��Ԫ�ؽ�㣬�ҵ�������ָ�룬���򷵻ؿ�*/
{
    LNode *p=head;
    int  j=0;     /*��������j */
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(j==i)
        return p;
    return NULL;
}
void DeleteByNum(LNode *head)
{
    char tnum[20];
    int i=0;
    LNode  *p=head->next;
    scanf("%s",tnum);
    LNode *pre;
    while(p->next!=NULL)
    {
        s++;
        if(strcmp(p->data.num,tnum)==0)
        {
            i=1;
            break;
        }
        pre=p;
        p=p->next;
    } /*����ֵΪX������Ԫ�ؽ��*/
    if(i=1)
    {
        pre->next=p->next;    /*�ҵ�ɾ��*/
        free(p);
    }
    else
    {
        printf("û�и�ѧ����Ϣ��\n");
        return;
    }
}
void FreeAll(LNode *head)
{
    LNode *q,*p=head;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    head=NULL;
}
void  Insert( LNode *head, int i)
{
    LNode *pre,*s;
    s=(LNode *)malloc(sizeof(LNode)); /*������װ���*/
    char tnum[20];
    pre=GetElem(head,i-1);   /*���ҵ�i-1�����*/
    if(pre==NULL)
    {
        printf("�������");
        return;
    }
C:
    printf("�������%d��ѧ��ѧ�ţ�",i+1);
    scanf("%s",tnum);

    if (strspn(tnum,"0123456789")==strlen(tnum))
    {
        strcpy(s->data.num,tnum);
    }
    else
    {
        printf("ѧ����������!\n");
        goto C;
    }
    printf("�������%d��ѧ��������",i+1);
    scanf("%s",s->data.name);
    printf("�������%d��ѧ�����ĳɼ���",i+1);
    scanf("%f",&s->data.cscore);
    printf("�������%d��ѧ����ѧ�ɼ���",i+1);
    scanf("%f",&s->data.mscore);
    printf("�������%d��ѧ��Ӣ��ɼ���",i+1);
    scanf("%f",&s->data.escore);

    s->next=pre->next;  /*�½������ڵ�i-1�����ĺ���*/

    pre->next=s;
}
void change(LNode *head)
{
    char tnum[20];
    int i=0,select;
    LNode  *p=head->next;
    scanf("%s",tnum);
    while(p!=NULL)
    {
        if(strcmp(p->data.num,tnum)==0)
        {
            printf("��ѡ��Ҫ�޸ĵ����ݣ�");
            printf("1.����   2.���ĳɼ�   3.��ѧ�ɼ�   4.Ӣ��ɼ�\n���ѡ��");
            scanf("%d",&select);
            switch(select)
            {
            case 1:
                printf("������ѧ��������");
                scanf("%s",p->data.name);
                break;
            case 2:
                printf("������ѧ�����ĳɼ���");
                scanf("%f",&p->data.cscore);
                break;
            case 3:
                printf("������ѧ����ѧ�ɼ���");
                scanf("%f",&p->data.mscore);
                break;
            case 4:
                printf("������ѧ��Ӣ��ɼ���");
                scanf("%f",&p->data.escore);
                break;
            }
            i=1;
            break;
        }
        p=p->next;
    }
    if(i==0)
        printf("û�и�ѧ����Ϣ��\n");
}
