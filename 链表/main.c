#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} LNode;

LNode *createh(int n)
{
    LNode  *head,*pnew;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;

    //for(i=0;i<n;i++)Insert_LinkList(head,1,i*i);

    for(i=0;i<n;i++)
    {
        pnew=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&pnew->data);
        //pnew->data=i*i;

        pnew->next=head->next;//ͷ�巨�ؼ����
        head->next=pnew;//ͷ�巨�ؼ����
    }
    return head;
}

LNode *Inscreate(int n)
{
    LNode  *head;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;

    //for(i=0;i<n;i++)Insert_LinkList(head,i+1,i*i);
    for(i=0;i<n;i++)Insert_LinkList(head,1,i*i);

    return head;
}

LNode *create(int n)
{
    LNode  *head,*pnew,*prear;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;

    //for(i=0;i<n;i++)Insert_LinkList(head,i+1,i*i);

    prear=head;
    for(i=0;i<n;i++)
    {
        pnew=(LNode *)malloc(sizeof(LNode));
        //scanf("%d",&pnew->data);
        pnew->data=i*i;

	    prear->next=pnew;//β�巨�ؼ����
        prear=pnew;//β�巨�ؼ����
    }
    pnew->next=NULL;
    return head;
}

void travel(LNode *head)
{
    LNode *p=head->next;/* pָ���һ��Ԫ�ؽ��*/
	while(p!=NULL)/* ѭ����β�ж�ʵ�����������*/
	{
	    p->data;  //��ǰ�������Ԫ��ֵ
		p=p->next;
	}
}

void printl(LNode *head)
{
    LNode *p=head->next;/* pָ���һ��Ԫ�ؽ��*/
	while(p!=NULL )
	{
	    printf("%d ",p->data);  //���һ������Ϣ

		p=p->next;
	}
}

int  ListLength(LNode *head)
{
   LNode *p=head->next; /* pָ���һ��Ԫ�ؽ��*/
   int  i=0;          /*������i*/
   while(p!=NULL)
   {
       i++;

       p=p->next;
   }
   return  i;
}

LNode * GetElem(LNode *head, int  i)/*�ڵ�����head�в��ҵ�i��Ԫ�ؽ�㣬�ҵ�������ָ�룬���򷵻ؿ�*/
{
    LNode *p=head;
    int  j=0;     /*��������j */
    while(p->next!=NULL&&j<i){p=p->next;j++;}
    if(j==i)return p;
    return NULL;
}

LNode  *LocateElem(LNode *head,ElemType x)/*�ڵ�����head�в���ֵΪx�Ľ�㣬�ҵ��󷵻���ָ�룬���򷵻ؿ�*/
{
    LNode  *p=head;
    while(p->next!=NULL&&p->data!=x)p=p->next;
    if(p->data==x) return p;
    return NULL;
}

void  Insert_LinkList( LNode *head, int i, ElemType  x)
{
    LNode *pre,*s;

    pre=GetElem(head,i-1);   /*���ҵ�i-1�����*/
    if(pre==NULL){printf("\nPosition Error\n");return; }


    s=(LNode *)malloc(sizeof(LNode)); /*������װ���*/
    s->data=x;

    s->next=pre->next;  /*�½������ڵ�i-1�����ĺ���*/

    pre->next=s;
}

void Del_LinkList(LNode *head,int i)
{
    LNode *pre,*r;

    pre=GetElem(head,i-1);   /*���ҵ�i-1�����*/
    if(pre==NULL||pre->next==NULL){printf("\nPosition Error\n");return;}/*��i���ߵ�i-1����㲻����*/


    r=pre->next;       /*rָ���i�����*/

    pre->next=r->next; /*��������ɾ��*/
    free(r);           /*�ͷ�*r */
 }

void del(LNode *head,ElemType x)
{
    LNode *pre,*p;
	p=head;
    while(p->next!=NULL&&p->data!=x)
    {pre=p;p=p->next;} /*����ֵΪX������Ԫ�ؽ��*/
	if(p->data==x){pre->next=p->next;free(p);} /*�ҵ�ɾ��*/
	else printf("Delete error!\n");
}

void ConverseLink(LNode *head)
{
    LNode *p,*q;
    p=head->next;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p; p=p->next;
q->next=head->next;
        head->next=q;

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

int main()
{
    LNode *head=NULL;
    head=create(5);
    printl(head);
    printf("\nHello world!\n");
    ConverseLink(head);
    printl(head);
free(head);

    //FreeAll(head);
    return 0;
}
