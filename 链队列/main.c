#include <stdio.h>
#include <stdlib.h>
typedef int QElemType; //* QElemType���͸���ʵ������������������Ϊint
typedef struct   //* ���ṹ
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct    //* ���е�����ṹ
{
   QueuePtr front,rear;      //* ��ͷ����βָ��
}LinkQueue;

//* ��ʼ��һ���ն���Q
LinkQueue *InitQueue()
{
    LinkQueue *Q=(LinkQueue *)malloc(sizeof(LinkQueue ));
    QNode  *head;
    head=(QNode *)malloc(sizeof(QNode));
    head->next=NULL;
    Q->front=head;
  Q->rear=head;
  return  Q;
}
//* ���ٶ���Q
void FreeQueue(LinkQueue *Q)
{
    QNode *q,*p;
    if(Q==NULL)return;
    p=Q->front;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(Q);
    Q=NULL;
}
//* ����Ԫ��eΪQ���µĶ�βԪ�� */typedef int Status;
int EnQueue(LinkQueue *Q,QElemType e)
{
  QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
  if(!s)exit(1);         //* �洢����ʧ��
  s->data=e;
  s->next=NULL;
  Q->rear->next=s;   //* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ��
  Q->rear=s;    //* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s
  return 1;
}
//* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR
int DeQueue(LinkQueue *Q,QElemType *e)
{  QueuePtr p;
  if(Q->front==Q->rear)
    return 0;
  p=Q->front->next;    //* ����ɾ���Ķ�ͷ����ݴ��p
  *e=p->data;    //* ����ɾ���Ķ�ͷ����ֵ��ֵ��e
  Q->front->next=p->next;
                                      //* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ�����
  if(Q->rear==p)    //* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ���
    Q->rear=Q->front;
  free(p);
  return 1;
}
int main()
{
    int i,n;
    QElemType e;
    LinkQueue *Q=InitQueue();
    printf("Please input the count of Queue-elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nPlease input No.%d-number:",i+1);
        scanf("%d",&e);
        EnQueue(Q,e);
    }
    printf("\r\nNow Queue is:");
    for(i=0;i<n;i++)
    {
        DeQueue(Q,&e);
        printf("%d  ",e);
    }
    FreeQueue(Q);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE   100 //*���е���󳤶�
typedef int QElemType;
//* QElemType���͸���ʵ������������������Ϊint

//* ѭ�����е�˳��洢�ṹ
typedef struct
{
  QElemType data[MAXSIZE];
  int front;      //* ͷָ��
  int rear;    //* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;
//* ��ʼ��һ���ն���Q
SqQueue *InitQueue()
{
    SqQueue *Q=(SqQueue *)malloc(sizeof(SqQueue ));
    Q->front=0;
  Q->rear=0;
  return  Q;
}
//* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ����
int QueueLength(SqQueue Q)
{
  return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
//* ������δ���������Ԫ��eΪQ�µĶ�βԪ��
int EnQueue(SqQueue *Q,QElemType e)
{
  if ((Q->rear+1)%MAXSIZE == Q->front)//* ���������ж�
    return 0;
  Q->data[Q->rear]=e;    //* ��Ԫ��e��ֵ����β
   //* rearָ�������һλ�ã�
        //* ���������ת������ͷ��
  Q->rear=(Q->rear+1)%MAXSIZE;

  return  1;
}
//* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
int DeQueue(SqQueue *Q,QElemType *e)
{
  if (Q->front == Q->rear)  //* ���пյ��ж�
    return 0;
  *e=Q->data[Q->front];  //* ����ͷԪ�ظ�ֵ��e
  //* frontָ�������һλ��
       //* ���������ת������ͷ��
  Q->front=(Q->front+1)%MAXSIZE;

  return  1;
}

int main()
{
    int i,n;
    QElemType e;
    SqQueue *Q=InitQueue();
    printf("Please input the count of Queue-elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nPlease input No.%d-number:",i+1);
        scanf("%d",&e);
        EnQueue(Q,e);
    }
    printf("\r\nNow Queue is:");
    for(i=0;i<n;i++)
    {
        DeQueue(Q,&e);
        printf("%d  ",e);
    }
    free(Q);
    return 0;
}
*/
