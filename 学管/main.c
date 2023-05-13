#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<signal.h>
#define _CRT_SECURE-NO-WARNINGS
struct student
{
    long int num;
    char name[20];
    int age;
    char sex[1];
    float cscore;
    float mscore;
    float escore;
    float sum;
    float ave;
};//���ݽṹ��
struct Node
{
    //int data;
    struct student data;
    struct Node *next;
};//����ṹ��
struct Node* makelist();//������ͷ ��ͷһ�㲻�Ŷ���
struct Node * makenode(struct student data);//�����ڵ�
void inputnode(struct Node * headNode,struct student data);//����ڵ�
void printflist(struct Node* headNode);//��ӡ�ڵ�
struct Node* searchbyID(struct Node*headNode,int* num);//���ҽڵ�
void deletebyID(struct Node* headNode,int* num);//ɾ���ڵ�
void rankCNode1(struct Node * headNdoe);//��������
void rankMNode1(struct Node * headNode);//��ѧ����
void rankENode1(struct Node * headNode);//Ӣ������
void rankSNode1(struct Node * headNode);//�ܳɼ�����
void rankSNode2(struct Node * headNode);//�ܳɼ�����(����)
void rankCNode2(struct Node * headNode);//��������(����)
void rankMNode2(struct Node * headNode);//��ѧ����(����)
void rankENode2(struct Node * headNode);//Ӣ������(����)
void menu()//�˵����
{
    printf("***************ѧ������ϵͳ*************\n");
    printf("*\t\t1.¼������             *\n");
    printf("*\t\t2.�������             *\n");
    printf("*\t\t3.�޸��޸�             *\n");
    printf("*\t\t4.ɾ������             *\n");
    printf("*\t\t5.��������             *\n");
    printf("*\t\t6.�ɼ�����(����)       *\n");
    printf("*\t\t7.�ɼ�����(����)       *\n");
    printf("*\t\t8.�˳�ϵͳ             *\n");
    printf("****************************************\n");
}
//������ѡ����ѡ����Ž��в���
struct Node* list=NULL;
void menuselect()
{
    int c=1;
    int a=0;//�ж�����ķ�ʽ
    int choice=0;
    struct Node * result=NULL;
    struct Node * jieguo=NULL;
    struct student data;
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
    case 8:
        system("pause");
        exit(0);
        break;
    case 1:

        printf("**********¼������**********\n");
 A:       printf("������ѧ��ѧ��:(������8λ��ֵ)");
        scanf("%ld",&data.num);
        fflush(stdin);



        while(data.num<10000000||data.num>99999999)
        {
            printf("ѧ�Ŵ���,����������ѧ��:");
            scanf("%ld",&data.num);
        fflush(stdin);
        }
        result = searchbyID(list,data.num);
        if(result==NULL)
        {
        printf("������ѧ��������:");
        scanf("%s",data.name);
        fflush(stdin);
        printf("������ѧ��������:");
        scanf("%d",&data.age);
        fflush(stdin);
        while(data.age<0||data.age>100)
        {
            printf("��������������:");
            scanf("%d",&data.age);
            fflush(stdin);
        }
        printf("������ѧ�����Ա�:(m����f)");
        scanf("%s",data.sex);
        fflush(stdin);
        while(c)
        {
            if(*data.sex=='f')
            {
                c=0;
            }
            else if(*data.sex=='m')
            {
                c=0;
            }
            else
            {
                printf("�����������Ա�:");
                scanf("%s",data.sex);
                fflush(stdin);
            }
        }
        printf("������ѧ�������ĳɼ�:");
        scanf("%f",&data.cscore);
        fflush(stdin);
        while(data.cscore<0||data.cscore>150)
        {
            printf("�������������ĳɼ�:");
            scanf("%f",&data.cscore);
            fflush(stdin);
        }
        printf("������ѧ������ѧ�ɼ�:");
        scanf("%f",&data.mscore);
        fflush(stdin);
        while(data.mscore<0||data.mscore>150)
        {
            printf("������������ѧ�ɼ�:");
            scanf("%f",&data.mscore);
            fflush(stdin);
        }
        printf("������Ӣ��ɼ�:");
        scanf("%f",&data.escore);
        fflush(stdin);
        while(data.escore<0||data.escore>150)
        {
            printf("����������Ӣ��ɼ�:");
            scanf("%f",&data.escore);
            fflush(stdin);
        }
        inputnode(list,data);
        }
        else
        {
            printf("��ѧ���Ѵ��ڣ���������\n");
            goto A;
        }

        break;
    case 2:
        printf("**********�������**********\n");
        printflist(list); //��ӡ
        break;
    case 3:
        printf("**********�޸�����********\n");
        printf("��������Ҫ�޸ĵ�ѧ��:");
        scanf("%ld",&data.num);
        result = searchbyID(list,data.num);
        if(result==NULL)
            printf("���޴���!\n");
        else
        {
 B:           printf("������ѧ��");
            scanf("%ld",&result->data.num);
            fflush(stdin);
            while(result->data.num<10000000||result->data.num>99999999)
            {
                printf("�������,����������ѧ��:");
                scanf("%ld",&result->data.num);
            fflush(stdin);
            }
            jieguo = searchbyID(list,result->data.num);
            if(jieguo!=NULL)
        {
            printf("��ѧ���Ѿ����ڣ��������޸ģ�\n");
            goto B;
        }
        else
        {
            printf("������������");
            scanf("%s",result->data.name);
            fflush(stdin);
            printf("���������䣺");
            scanf("%d",&result->data.age);
            fflush(stdin);
            while(result->data.age<0||result->data.age>100)
            {
                printf("��������������:");
                scanf("%d",&result->data.num);
                fflush(stdin);
            }

            printf("�������Ա�");
            scanf("%s",result->data.sex);
            fflush(stdin);
            while(c)
            {
                if(*result->data.sex=='f')
                {
                    c=0;
                }
                else if(*result->data.sex=='m')
                {
                    c=0;
                }
                else
                {
                    printf("�����������Ա�:");
                    scanf("%s",result->data.sex);
                    fflush(stdin);
                }
            }

            printf("���������ĳɼ�:");
            scanf("%f",&result->data.cscore);
            fflush(stdin);
            while(result->data.cscore<0||result->data.cscore>150)
            {
                printf("�������������ĳɼ�:");
                scanf("%f",&result->data.cscore);
                fflush(stdin);
            }

            printf("��������ѧ�ɼ�:");
            scanf("%f",&result->data.mscore);
            fflush(stdin);
            while(result->data.mscore<0||result->data.mscore>100)
            {
                printf("������������ѧ�ɼ�:");
                scanf("%f",&result->data.mscore);
                fflush(stdin);
            }

            printf("������Ӣ��ɼ�:");
            scanf("%f",&result->data.escore);
            fflush(stdin);
            while(result->data.escore<0||result->data.escore>100)
            {
                printf("����������Ӣ��ɼ�:");
                scanf("%f",&result->data.escore);
                fflush(stdin);
            }
            printf("�޸ĳɹ���");
        }

        }
        break;
    case 4:

        printf("**********ɾ������**********\n");
        printf("��������Ҫɾ����ѧ��:(8λ��)");
        scanf("%ld",&data.num);
        fflush(stdin);
            while(data.num<10000000||data.num>99999999)
            {
                printf("�������,����������ѧ��:");
                scanf("%ld",&data.num);
        fflush(stdin);
            }
        deletebyID(list,data.num);
        break;
    case 5:
        printf("**********��������**********\n");
        printf("��������Ҫ���ҵ�ѧ��:(8λ��)\n");
        scanf("%ld",&data.num);
        fflush(stdin);
            while(data.num<10000000||data.num>99999999)
            {
                printf("�������,����������ѧ��:");
                scanf("%ld",&data.num);
        fflush(stdin);
            }
        result = searchbyID(list,data.num);
        if(result==NULL)
            printf("���޴���!\n");
        else
        {
            printf("ѧ����ѧ��:%ld\n",result->data.num);
            printf("ѧ��������:%s\n",result->data.name);
            printf("ѧ��������:%d\n",result->data.age);
            printf("ѧ�����Ա�:%s\n",result->data.sex);
            printf("ѧ�������ĳɼ�:%.2f\n",result->data.cscore);
            printf("ѧ������ѧ�ɼ�:%.2f\n",result->data.mscore);
            printf("ѧ����Ӣ��ɼ�:%.2f\n",result->data.escore);
            printf("ѧ�����ܳɼ�:%.2f\n",result->data.sum=result->data.cscore+result->data.mscore+result->data.escore);
            printf("ƽ����:%.2f\n",result->data.ave=result->data.sum/3.0);
        }
        break;
    case 6:
 C:       printf("**********�ɼ�����(����)**********\n");
        printf("\t1.���ĳɼ�����\n");
        printf("\t2.��ѧ�ɼ�����\n");
        printf("\t3.Ӣ��ɼ�����\n");
        printf("\t4.�ܳɼ�����\n");
        scanf("%d",&a);
        fflush(stdin);
        switch(a)
        {
        case 1:
            rankCNode1(list);
            printflist(list);
            break;
        case 2:
            rankMNode1(list);
            printflist(list);
            break;
        case 3:
            rankENode1(list);
            printflist(list);
            break;
        case 4:
            rankSNode1(list);
            printflist(list);
            break;
        default:
            printf("ѡ������������룡\n");
            system("pause");
            goto C;

        }
        break;
    case 7:
D:        printf("**********�ɼ�����(����)**********\n");
        printf("\t  1.���ĳɼ�����\n");
        printf("\t  2.��ѧ�ɼ�����\n");
        printf("\t  3.Ӣ��ɼ�����\n");
        printf("\t  4.�ܳɼ�����\n");
        scanf("%d",&a);
        fflush(stdin);
        switch(a)
        {
printflist(list);
        case 1:
            rankCNode2(list);
            printflist(list);
            break;
        case 2:
            rankMNode2(list);
            printflist(list);
            break;
        case 3:
            rankENode2(list);
            printflist(list);
            break;
        case 4:
            rankSNode2(list);
            printflist(list);
            break;
        default:
            printf("ѡ������������룡\n");
            system("pause");
            goto D;

        }
        break;
        signal(SIGINT, SIG_IGN);
        system("color 0a");
    default:
        printf("ѡ������������룡\n");
        break;
    }
}
int main()
{
list=makelist();
   signal(SIGINT, SIG_IGN);
    system("color 0a");
    while(1)
    {
      menu();
        menuselect();
        system("pause");
        system("cls");
    }
    return 0;
}
//��ʼ�������

//������ͷ ��ͷһ�㲻�Ŷ���

struct Node* makelist()
{
//    �ṹ�������ʾ
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}
//�����ڵ�
struct Node * makenode(struct student data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void inputnode(struct Node * headNode,struct student data)
{
    struct Node* newNode=makenode(data);
//  ��ͷ������
    newNode->next=headNode->next;
    headNode->next=newNode;
}

//ָ��λ��ɾ��
void deletebyID(struct Node* headNode,int* num)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode=headNode;
    if(posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ����\n");
        return;
    }
    while(posNode->data.num!=num)
    {
        posFrontNode=posNode;
        posNode=posFrontNode->next;
        if(posNode==NULL)
        {
            printf("û���ҵ�ָ��λ���޷�ɾ����\n");
            return;
        }
    }
    posFrontNode->next=posNode->next;
    free(posNode);
}
//���ҽڵ�
struct Node* searchbyID(struct Node*headNode,int* num)
{
    struct Node* pMove = headNode->next;
    if(pMove==NULL)
        return NULL;
    while(pMove->data.num!=num)
    {
        pMove=pMove->next;
        if(pMove==NULL)
        {
            return pMove;
        }
    }
    return pMove;
}
//��ӡ����
void printflist(struct Node * headNode)
{
    struct Node *pMove=headNode->next;
//    ���ݴ���
    while(pMove!=NULL)
    {
        printf("ѧ��:%ld\n",pMove->data.num);
        printf("����:%s\n",pMove->data.name);
        printf("����:%d\n",pMove->data.age);
        printf("�Ա�:%s\n",pMove->data.sex);
        printf("���ĳɼ�:%.2f\n",pMove->data.cscore);
        printf("��ѧ�ɼ�:%.2f\n",pMove->data.mscore);
        printf("Ӣ��ɼ�:%.2f\n",pMove->data.escore);
        printf("�ܳɼ�:%.2f\n",pMove->data.sum=pMove->data.cscore+pMove->data.mscore+pMove->data.escore);
        printf("ƽ����:%.2f\n",pMove->data.ave=pMove->data.sum/3.0);
        printf("\n");
        pMove=pMove->next;
    }
    printf("\n");
}
void rankCNode1(struct Node * headNode)//���ĳɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.cscore<posNodehead->next->data.cscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankCNode2(struct Node * headNode)//���ĳɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.cscore>posNodehead->next->data.cscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankMNode1(struct Node * headNode)//��ѧ�ɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.mscore<posNodehead->next->data.mscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankMNode2(struct Node * headNode)//��ѧ�ɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.mscore>posNodehead->next->data.mscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankENode1(struct Node * headNode)//Ӣ��ɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.escore<posNodehead->next->data.escore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankENode2(struct Node * headNode)//Ӣ��ɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.escore>posNodehead->next->data.escore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankSNode1(struct Node * headNode)//�ܳɼ�����(����)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.sum<posNodehead->next->data.sum)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankSNode2(struct Node * headNode)//�ܳɼ�����(����)(������)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.sum>posNodehead->next->data.sum)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
