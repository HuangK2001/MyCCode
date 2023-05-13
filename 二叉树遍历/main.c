#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    char data;
    struct BiTNode* lChild;
    struct BiTNode* rChild;
}BiTNode;
BiTNode* CreateTree();
void PreOrderTraverse(BiTNode*);//�����㷨
void InorderTraverse(BiTNode*);//�����㷨
void PostOrderTraverse(BiTNode*);//�����㷨
void NumOfLeafNode(BiTNode*, int*);
int GetHight(BiTNode*);
BiTNode* CopyTree(BiTNode*);
void DestroyTree(BiTNode*);
int main()
{
    printf("����������#�ŷ����������ַ���:\n");
    BiTNode* T;
    T=CreateTree();
    printf("\n���������\n");
    PreOrderTraverse(T);
    printf("\n���������\n");
    InorderTraverse(T);
    printf("\n���������\n");
    PostOrderTraverse(T);
    printf("\n");

    int n=0;
    NumOfLeafNode(T,&n);
    printf("�ö�����Ҷ�ӽ����ĿΪ��%d\n", n);

    int h = GetHight(T);
    printf("�ö������ĸ߶�Ϊ��%d\n", h);

    BiTNode* T1 = CopyTree(T);
    printf("��������¿����Ķ�������\n");
    InorderTraverse(T1);
    printf("\n");

    printf("���ٶ�����T1��\n");
    DestroyTree(T);

    return 0;
}


void PreOrderTraverse(BiTNode* T)
{
    if(T==NULL)return;
    printf("%c",T->data);
    PreOrderTraverse(T->lChild);
    PreOrderTraverse(T->rChild);
}




void InorderTraverse(BiTNode* T)
{
    if(T==NULL)return;
    InorderTraverse(T->lChild);
    printf("%c",T->data);
    InorderTraverse(T->rChild);
}





void PostOrderTraverse(BiTNode* T)
{
    if(T==NULL)return;
    PostOrderTraverse(T->lChild);
    PostOrderTraverse(T->rChild);
    printf("%c",T->data);
}



//#�ŷ����򴴽���
BiTNode* CreateTree()
{
    char ch;
    scanf("%c", &ch);
    //�ݹ��������
    if(ch == '#')return NULL;//#��������ʾ����ά��
    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = ch;
    root->lChild = CreateTree();
    root->rChild = CreateTree();
    return root;
}
//���������Ҷ�ӽڵ���Ŀ
void NumOfLeafNode(BiTNode* T, int* n)
{
    if(T==NULL)return;
    NumOfLeafNode(T->lChild,n);
    NumOfLeafNode(T->rChild,n);
    if(T->lChild==NULL && T->rChild==NULL)(*n)++;

}
//��������ĸ߶�
int GetHight(BiTNode* T)
{
    if(T==NULL)return 0;
    int h=0;
    int left=GetHight(T->lChild);
    int right=GetHight(T->rChild);
    h=left>right?left:right;
    return h+1;
}
//����������
BiTNode* CopyTree(BiTNode* T)
{
    if(T == NULL)return NULL;
    BiTNode* Tnew = (BiTNode*)malloc(sizeof(BiTNode));
    Tnew->data = T->data;
    Tnew->lChild = CopyTree(T->lChild);
    Tnew->rChild = CopyTree(T->rChild);
    return Tnew;
}
//���ٶ�����
void DestroyTree(BiTNode* T)
{
    if(T == NULL)return;
    //�����Ժ�������ķ�ʽ�������٣���ΪҪ��֤ÿ�������ĸ��������ͷ�
    DestroyTree(T->lChild);
    DestroyTree(T->rChild);
    printf("��ǰ�ͷŽ��ֵΪ��%c\n", T->data);
    free(T);
}
