#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define NULL 0
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

SeqList  *init_SeqList()
{
    SeqList *L=(SeqList *)malloc(sizeof(SeqList));
    L->length=0;
    return L;
}
//void OtherList();
SeqList *MergeList();
int main()
{
    int n;
    SeqList *L;
    SeqList *Lb;
    SeqList *Lc;
//    Lp=init_SeqList( );
    SeqList Ls;
    Ls.length=0;
    L=&Ls;
    ElemType x;
    int Location;
    int s;
    printf("\n\n\t|********˳����������***************|\n");
    printf("\t|*********1.��λ�ò���****************|\n");
    printf("\t|*********2.��ֵ����******************|\n");
    printf("\t|*********3.����**********************|\n");
    printf("\t|*********4.ɾ��**********************|\n");
    printf("\t|*********5.���**********************|\n");
    printf("\t|*********6.���������Ա��ϲ�********|\n");
    printf("\t|*********0.�˳�**********************|\n");
    printf("******Ҫ�����������ܣ���Ҫִ��3�Ź�����������******\n");
    while(1)
    {
        printf("��������Ҫ�������ܵ���ţ�");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            printf("������Ҫ�������ݵ��±꣺");
            scanf("%d",&Location);
            if(LocateByEdress(L,Location))
            {
                ElemType d=LocateByEdress(L,Location);
                printf("���ҵ�������Ϊ��%d\n",d);
            }
            else
                printf("λ���±�����\n");
            break;
        case 2:
            printf("������Ҫ���ҵ�ֵ��");
            scanf("%d",&x);
            ElemType i=LocateByData(L,x);
            if(LocateByData(L,x)==-1)
                printf("���޴����ݣ�");
            else
                printf("Ҫ���ҵ�ֵ�±�Ϊ��%d\n",i);
            break;
        case 3:
            printf("������Ҫ�����ֵ(β�巨)��");
            scanf("%d",&x);
            if(InsertList(L,L->length,x))
                printf("����ɹ���\n");
            break;
        case 4:
            printf("������Ҫɾ�����ݵ��±꣺");
            scanf("%d",&Location);
            if(DeleteList(L,Location))
                printf("ɾ���ɹ���\n");

            break;
        case 5:
            PutList(L);
            break;
        case 6:
            Lb=init_SeqList();
            Lc=init_SeqList();
            if(Lb)
                printf("�����Ա��Ѵ�����\n");
            printf("��������ϲ���������ȣ�");
            scanf("%d",&n);
            printf("����Ԫ��ֵ:");
            for(i=0; i<n; i++)
            {
                scanf("%d",&x);
                InsertList(Lb,Lb->length,x);
            }
            Lc=MergeList(L,Lb);
            printf("�ϲ��ɹ� !\n");
            PutList(Lc);
            //printf("�����������Ա�Ԫ�أ�");
            //scanf("%d",&x);
            //InsertList(Lb,Lb->length,x);
            //PutList(OtherList(x));
            break;
        case 0:
            if(L!=NULL)
                free(L);
            if(Lb!=NULL)
                free(Lb);
            if(Lc!=NULL)
                free(Lc);
            system("cls");
            exit(0);
            break;
        }
    }

}
int LocateByData(SeqList  *L, ElemType x)
{
    int i;
    for(i=0; i<L->length; i++)
        if(L->data[i]==x)
            return i;
    return -1;
}
ElemType LocateByEdress(SeqList  *L,int Edress)
{
    if(Edress<0||Edress>=L->length)
    {
        return 0;
    }
    return L->data[Edress];
}
int InsertList(SeqList  *L,int i, ElemType x)
{
    int k;
    if (L->length==MAXSIZE)
    {
        printf("���Ա������Χ��\n");
        return 0;
    }
    if (i<0 || i>L->length)
    {
        printf("����λ������\n");
        return 0;
    }
    for(k=L->length-1; k>=i; k--)
        L->data[k+1]=L->data[k];
    L->data[i]=x;
    L->length++;
    return 1;
}
int DeleteList(SeqList  *L,int i)
{
    int  k;
    if(i<0 || i>=L->length)
    {
        printf ("ɾ��λ������\n");
        return 0;
    }
    if(L->length==0)
    {
        printf("���Ա�Ϊ�գ�\n");
        return 0;
    }

    for(k=i+1; k<=L->length-1; k++)
        L->data[k-1]=L->data[k];
    L->length--;
    return 1;
}
void PutList(SeqList *L)
{
    printf("���Ա�����Ϊ��");
    for(int i = 0; i < L->length; i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
//void OtherList(ElemType x)
//{
//    SeqList *Lb;
//    Lb=init_SeqList();
//    if(Lb)printf("�����Ա��Ѵ�����\n");
//    InsertList(Lb,Lb->length,x);
//}
SeqList *MergeList(SeqList *La, SeqList *Lb)
{
    int i=0,j=0,k=0;
    SeqList *Lc;
    Lc=init_SeqList();
    while(i<La->length&&j<Lb->length)
    {
        if (La->data[i]<=Lb->data[j])
        {
            InsertList(Lc,k, La->data[i]);
            i++,k++;
        }
        else
        {
            InsertList(Lc,k, Lb->data[j]);
            j++,k++;
        }
    }
    while(i<La->length)
    {
        InsertList(Lc,k,La->data[i]);
        i++,k++;
    }
    while(j<Lb->length)
    {
        InsertList(Lc,k,Lb->data[j]);
        j++,k++;
    }

    return Lc;
}
