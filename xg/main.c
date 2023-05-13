#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<signal.h>
#define _CRT_SECURE-NO-WARNINGS
struct student
{
    long int id;
    char name[20];
    int age;
    char sex[1];
    float Cscore;
    float Mscore;
    float Escore;
    float sum;
};//����дĳһ�����ݽṹ
struct Node
{
    //int data;
    struct student data;
    struct Node *next;
};
struct Node* createList();//������ͷ ��ͷһ�㲻�Ŷ���
struct Node * createNode(struct student data);//�����ڵ�
void insertNodeByhead(struct Node * headNode,struct student data);//����ڵ�
void printflist(struct Node* headNode);//��ӡ�ڵ�
struct Node* searchInfoByData(struct Node*headNode,int* id);//���ҽڵ�
void deleteAppoinNode(struct Node* headNode,int* id);//ɾ���ڵ�
void rankCNode1(struct Node * headNdoe);//���ĳɼ�����
void rankMNode1(struct Node * headNode);//��ѧ�ɼ�����
void rankENode1(struct Node * headNode);//Ӣ��ɼ�����
void rankSNode1(struct Node * headNode);//�ܳɼ�����
void rankSNode2(struct Node * headNode);//�ܳɼ�����(����)
void rankCNode2(struct Node * headNode);//���ĳɼ�����(����)
void rankMNode2(struct Node * headNode);//��ѧ�ɼ�����(����)
void rankENode2(struct Node * headNode);//Ӣ��ɼ�����(����)
//void judgeNode(struct Node * headNode,int *id);//�ж�ѧ���Ƿ��ظ�
void menu()//�˵����
{
    printf("-------------ѧ������ϵͳ---------------\n");
    printf("\t1.¼����Ϣ\n");
    printf("\t2.�����Ϣ\n");
    printf("\t3.�޸���Ϣ\n");
    printf("\t4.ɾ����Ϣ\n");
    printf("\t5.������Ϣ\n");
    printf("\t6.�ɼ�����(����)\n");
    printf("\t7.�ɼ�����(����)\n");
    printf("\t8.�˳�ϵͳ\n");
    printf("----------------------------------------\n");
}
//������ѡ����ѡ����Ž��в���
struct Node* list=NULL;
void keyDown()
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
        printf("�����˳�\n");
        system("pause");
        exit(0);
        break;
    case 1:

        printf("-----------¼����Ϣ------------\n");
 A:       printf("������ѧ��ѧ��:(������9λ��ֵ)");
        scanf("%ld",&data.id);
        fflush(stdin);



        while(data.id<100000000||data.id>999999999)
        {
            printf("�������,����������ѧ��:");
            scanf("%ld",&data.id);
        fflush(stdin);
        }
        result = searchInfoByData(list,data.id);
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
        printf("������ѧ�����Ա�:(M����W)");
        scanf("%s",data.sex);
        fflush(stdin);
        while(c)
        {
            if(*data.sex=='M')
            {
                c=0;
            }
            else if(*data.sex=='W')
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
        scanf("%f",&data.Cscore);
        fflush(stdin);
        while(data.Cscore<0||data.Cscore>100)
        {
            printf("�������������ĳɼ�:");
            scanf("%f",&data.Cscore);
            fflush(stdin);
        }
        printf("������ѧ������ѧ�ɼ�:");
        scanf("%f",&data.Mscore);
        fflush(stdin);
        while(data.Mscore<0||data.Mscore>100)
        {
            printf("������������ѧ�ɼ�:");
            scanf("%f",&data.Mscore);
            fflush(stdin);
        }
        printf("������Ӣ��ɼ�:");
        scanf("%f",&data.Escore);
        fflush(stdin);
        while(data.Escore<0||data.Escore>100)
        {
            printf("����������Ӣ��ɼ�:");
            scanf("%f",&data.Escore);
            fflush(stdin);
        }
        insertNodeByhead(list,data);
        }
        else
        {
            printf("��ѧ���Ѵ��ڣ���������\n");
            goto A;
        }

        break;
    case 2:
        printf("-----------�����Ϣ------------\n");
        printflist(list); //��ӡ
        break;
    case 3:
        printf("-----------�޸���Ϣ------------\n");
        printf("��������Ҫ�޸ĵ�ѧ��:");
        scanf("%ld",&data.id);
        result = searchInfoByData(list,data.id);
        if(result==NULL)
            printf("���޴���!�޷��޸�\n");
        else
        {
 B:           printf("��������ѧ��ѧ��");
            scanf("%ld",&result->data.id);
            fflush(stdin);
            while(result->data.id<100000000||result->data.id>999999999)
            {
                printf("�������,����������ѧ��:");
                scanf("%ld",&result->data.id);
            fflush(stdin);
            }
            jieguo = searchInfoByData(list,result->data.id);
            if(jieguo!=NULL)
        {
            printf("��ѧ���Ѿ����ڣ��������޸ģ�\n");
            goto B;
        }
        else
        {
            printf("��������ѧ����������");
            scanf("%s",result->data.name);
            fflush(stdin);
            printf("��������ѧ�������䣺");
            scanf("%d",&result->data.age);
            fflush(stdin);
            while(result->data.age<0||result->data.age>100)
            {
                printf("��������������:");
                scanf("%d",&result->data.id);
                fflush(stdin);
            }

            printf("��������ѧ�����Ա�");
            scanf("%s",result->data.sex);
            fflush(stdin);
            while(c)
            {
                if(*result->data.sex=='M')
                {
                    c=0;
                }
                else if(*result->data.sex=='W')
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

            printf("��������ѧ�������ĳɼ�:");
            scanf("%f",&result->data.Cscore);
            fflush(stdin);
            while(result->data.Cscore<0||result->data.Cscore>100)
            {
                printf("�������������ĳɼ�:");
                scanf("%f",&result->data.Cscore);
                fflush(stdin);
            }

            printf("��������ѧ������ѧ�ɼ�:");
            scanf("%f",&result->data.Mscore);
            fflush(stdin);
            while(result->data.Mscore<0||result->data.Mscore>100)
            {
                printf("������������ѧ�ɼ�:");
                scanf("%f",&result->data.Mscore);
                fflush(stdin);
            }

            printf("��������ѧ����Ӣ��ɼ�:");
            scanf("%f",&result->data.Escore);
            fflush(stdin);
            while(result->data.Escore<0||result->data.Escore>100)
            {
                printf("����������Ӣ��ɼ�:");
                scanf("%f",&result->data.Escore);
                fflush(stdin);
            }
            printf("�޸ĳɹ���");
        }

        }
        break;
    case 4:

        printf("-----------ɾ����Ϣ------------\n");
        printf("��������Ҫɾ����ѧ��:(9λ��)");
        scanf("%ld",&data.id);
        fflush(stdin);
            while(data.id<100000000||data.id>999999999)
            {
                printf("�������,����������ѧ��:");
                scanf("%ld",&data.id);
        fflush(stdin);
            }
        deleteAppoinNode(list,data.id);
        break;
    case 5:
        printf("-----------������Ϣ------------\n");
        printf("��������Ҫ���ҵ�ѧ��:(9λ��)\n");
        scanf("%ld",&data.id);
        fflush(stdin);
            while(data.id<100000000||data.id>999999999)
            {
                printf("�������,����������ѧ��:");
                scanf("%ld",&data.id);
        fflush(stdin);
            }
        result = searchInfoByData(list,data.id);
        if(result==NULL)
            printf("���޴���!\n");
        else
        {
            printf("ѧ����id:%ld\n",result->data.id);
            printf("ѧ��������:%s\n",result->data.name);
            printf("ѧ��������:%d\n",result->data.age);
            printf("ѧ�����Ա�:%s\n",result->data.sex);
            printf("ѧ�������ĳɼ�:%.2f\n",result->data.Cscore);
            printf("ѧ������ѧ�ɼ�:%.2f\n",result->data.Mscore);
            printf("ѧ����Ӣ��ɼ�:%.2f\n",result->data.Escore);
            printf("ѧ�����ܳɼ�:%.2f\n",result->data.sum);
        }
        break;
    case 6:
 C:       printf("----------�ɼ�����(����)----------\n");
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
D:        printf("----------�ɼ�����(����)----------\n");
        printf("\t1.���ĳɼ�����\n");
        printf("\t2.��ѧ�ɼ�����\n");
        printf("\t3.Ӣ��ɼ�����\n");
        printf("\t4.�ܳɼ�����\n");
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
list=createList();
   signal(SIGINT, SIG_IGN);
    system("color 0a");
    while(1)
    {
      menu();
        keyDown();
        system("pause");
        system("cls");
    }


    return 0;
}
//��ʼ�������

//������ͷ ��ͷһ�㲻�Ŷ���

struct Node* createList()
{
//    �ṹ�������ʾ
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}
//�����ڵ�
struct Node * createNode(struct student data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//void judgeNode(struct Node * headNode,int *id)//�ж�ѧ���Ƿ��ظ�
//{
//    struct Node* posNode=headNode->next;
//   if(posNode==NULL)
//   {
//       printf("���ݲ���\n");
//       return;
//   }
//   while(posNode->data.id!=id)
//   {
//     posNode=posNode->next;
//     if(posNode->data.id==id)
//     {
//         printf("���ظ�ѧ��");
//         return;
//     }
//
//   }return;
//}

//����ڵ�
void insertNodeByhead(struct Node * headNode,struct student data)
{
    struct Node* newNode=createNode(data);
//  ��ͷ������
    newNode->next=headNode->next;
    headNode->next=newNode;
}

//ָ��λ��ɾ��
void deleteAppoinNode(struct Node* headNode,int* id)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode=headNode;
    if(posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ����\n");
        return;
    }
    while(posNode->data.id!=id)
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
struct Node* searchInfoByData(struct Node*headNode,int* id)
{
    struct Node* pMove = headNode->next;
    if(pMove==NULL)
        return NULL;
    while(pMove->data.id!=id)
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
        printf("ѧ��:%ld\n",pMove->data.id);
        printf("����:%s\n",pMove->data.name);
        printf("����:%d\n",pMove->data.age);
        printf("�Ա�:%s\n",pMove->data.sex);
        printf("���ĳɼ�:%.2f\n",pMove->data.Cscore);
        printf("��ѧ�ɼ�:%.2f\n",pMove->data.Mscore);
        printf("Ӣ��ɼ�:%.2f\n",pMove->data.Escore);
        printf("�ܳɼ�:%.2f\n",pMove->data.Cscore+pMove->data.Mscore+pMove->data.Escore);
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
            if(posNodehead->data.Cscore<posNodehead->next->data.Cscore)
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
            if(posNodehead->data.Cscore>posNodehead->next->data.Cscore)
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
            if(posNodehead->data.Mscore<posNodehead->next->data.Mscore)
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
            if(posNodehead->data.Mscore>posNodehead->next->data.Mscore)
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
            if(posNodehead->data.Escore<posNodehead->next->data.Escore)
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
            if(posNodehead->data.Escore>posNodehead->next->data.Escore)
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
