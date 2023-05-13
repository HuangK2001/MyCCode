#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define  MAXSIZE   512 /*���Ա����󳤶�*/
typedef char ElemType;//�ַ�������Ϊ˳���
typedef  struct
{
    ElemType  data[MAXSIZE];
    int  length;  /*��ǰ��ĳ���*/
}SeqList;
SeqList *Inits()
{
    SeqList *L=(SeqList *)malloc(sizeof(SeqList));
    L->length=0;
    return L;
}
int Pushs(SeqList *L,ElemType e)
{
    int k;
    if (L->length==MAXSIZE){printf("The stack is overflow!");return 0;}  //*�ռ�������������ջ
    L->data[L->length]=e;//*��ջ��β�巨
    L->length++;//*����1,L->length��Ȼ�Ǳ�ĳ���
    return 1;
}
int Pops(SeqList *L,ElemType *e)
{
    int  k;
    if(L->length==0)return 0;//*ջ�ճ�ջʧ��
    *e=L->data[L->length-1]; //*��ջ��βɾ��
    L->length--;
    return 1;
}

int Lc(char c)
{
    int i;
    char ss[7]="([{)]}";
    for(i=0;i<6;i++)if(ss[i]==c)break;
    return i;
}
int ExpMatch(char s[])//�жϱ��ʽ����ƥ��
{
  SeqList *L=NULL;
  char c;
  int m,j,n,i=0;
  n=strlen(s);
  L=Inits();
  for(i=0;i<n;i++)
  {
      m=Lc(s[i]);
      if(m==6)continue;
      if(m<3)Pushs(L,s[i]);
      else
      {
          Pops(L,&c);
          if(Lc(c)!=m-3){free(L);return 0;}
      }
  }
  if(L->length==0){free(L);return 1;}
  free(L);
  return 0;
}
int IsOp(char c)//�ж������
{
    if(c=='+'||c=='-'||c=='*'||c=='/')return 1;
    return 0;
}
char Precede(char c1,char c2)//��������ȼ�
{
    if((c1=='+'||c1=='-')&&(c2=='*'||c2=='/'))return 1;
    return 0;
}
int TwoResult(char op,int a,int b)//��������ĺ���
{
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
int MtoSuffix(char ss[],char sm[])/*ʵ����׺���ʽsm���׺���ʽssת��������Ԫ�ؼ�ӿո�ָ�*/
{
  SeqList *L=NULL;
  char c;
  int i,n;
  L=Inits();
  i=0;n=0;
  while(sm[i])
  {
      if(sm[i]>='0'&&sm[i]<='9')ss[n++]=sm[i];/*������ֱ������ɺ�׺���ʽ��*/
      if(sm[i]=='(')Pushs(L,sm[i]);/*����������ջ*/
      if(sm[i]==')')/*�������ų�ջ������ɺ�׺���ʽ�ֱ�������ţ������ų�ջ����*/
      {
          ss[n++]=0x20;//��ӿո�ָ���
          while(Pops(L,&c)){if(c=='(')break;ss[n++]=c;}
      }
      if(IsOp(sm[i]))/*��������ֵȼ��������*/
      {
          ss[n++]=' ';/*���������ӿո����ָ��������ڼ�������ʶ��*/
          while(Pops(L,&c))/*���������ջ������ɺ�׺���ʽ�ֱ��ջ��������ȼ����ͻ���������*/
          {
              if(Precede(c,sm[i])||c=='(')
              {
                  Pushs(L,c);
                  break;
              }
              else ss[n++]=c;
          }
          Pushs(L,sm[i]);
      }
      i++;
  }
  while(Pops(L,&c))ss[n++]=c;
  ss[n]=0;
}

typedef struct Node//����������ջ
{
    int data;
    struct Node *next;
}LNode;
LNode *InitStack()
{
    LNode  *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    return head;
}
void RuinList(LNode *L)
{
    LNode *p,*q;
    p=L;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L=NULL;
}
/* ʵ�ִ�ͷ�����ջPush ��Pop����*/
void Pushi(LNode *L,int e)
{
    LNode *p;
    p=(LNode *)malloc(sizeof(LNode));

    p->data=e;
    p->next=L->next;
    L->next=p;
}
void Popi(LNode *L,int *e)
{
    LNode *p=L->next;
    if(p==NULL)return -1;
    L->next=p->next;
    *e=p->data;
    free(p);
}
int Expression(char s[])/*ʵ����׺���ʽ��ֵ*/
{
  LNode *L=NULL;
  int i=0,x=0,r,y,z;
  L=InitStack();
  while(s[i])
  {
      if(s[i]>='0'&&s[i]<='9')
      {
          x=x*10+s[i]-'0';
          i++;
          continue;
      }
      if(s[i-1]>='0'&&s[i-1]<='9'&&i>0){Pushi(L,x);x=0;}
      if(IsOp(s[i]))//if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
      {
          Popi(L,&z);
          Popi(L,&y);
          r=TwoResult(s[i],y,z);//��ջ˳����ջ���Ⱥ�λ���෴
          Pushi(L,r);
      }
      i++;
  }
  Popi(L,&x);
  RuinList(L);
  return x;

}

int main()
{
	char exp[128],ss[256];
	gets(exp);
    if(!ExpMatch(exp)){printf("Match error!!!");return 0;}
    MtoSuffix(ss,exp);
    printf("\n��׺���ʽ:%s = %d\n",ss,Expression(ss));
	return 1;
}
