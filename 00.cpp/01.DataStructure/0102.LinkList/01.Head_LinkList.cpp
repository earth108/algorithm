#include <iostream>

using namespace std;

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode , *LinkList;


//带头结点的链表初始化
bool InitLinkList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L -> next = NULL;
    return true;
}

//带头结点单链表前插入
bool ListInsert(LinkList &L , int i , ElemType e)
{
    //判断传入的 i 是否合法
    if (i < 1)
    {
        return false;
    }
    LNode *p;      // p 指向当前扫描到的结点
    int j = 0;     // j 表示当前 p 指向的是第几个结点
    p = L;
    // 遍历查找到第 i - 1 个结点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j ++;
    }
    // 判断 i 的位置是否合法
    if (p == NULL)
    {
        return false;
    }
    //分配一片空间
    //s为指向该空间地址的指针
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s ->data = e;
    //在第 i 个位置插入数据 ， p 为第 i - 1 个位置 ， s为第 i 个位置
    s -> next = p -> next;
    p -> next = s;
    return true;
}

//指定结点后插操作   在 p 结点之后 ，插入元素 e
bool InsertNextNode (LNode *p , ElemType e)
{
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));

    if (s == NULL) return false;

    s -> data = e;
    s -> next = p -> next;
    p -> next = s;

    return true;
}

//指定结点前插操作 ， 在 p 结点之前 ， 插入元素 e
bool InsertPriorNode (LinkList L , LNode *p , ElemType e)
{
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s -> data = p -> data;
    p -> data = e;
    s -> next = p -> next;
    p -> next = s;

    return true;
}

//删除 第 i 个位置元素 ， 并用e返回删除元素的值
bool ListDelete(LinkList &L , int i , ElemType &e)
{
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p -> next;
        j ++;
    }

    if (p == NULL) return false;  //第 i - 1 个结点
    if (p -> next == NULL) return false;   //第 i 个结点

    LNode *q = p -> next;
    p -> next = q -> next;
    e = q -> data;
    free(q);
    return true;

}

//删除指定结点
bool DeleteNode(LNode *p)
{
    if (p == NULL) return false;
    
    LNode *q = p -> next;
    p -> data = q -> data;
    p -> next = q -> next;
    free(q);
    return true;
}

//带头结点 按位查找，返回第 i 个元素
LNode * GetElem(LinkList L , int i)
{
    if ( i < 0) return NULL;
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p -> next;
        j ++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L , ElemType e)
{
    LNode *p = L;
    while ( p!= NULL && p -> data != e)
    {
        p  = p -> next;
    }
    return p;
}

//求表的长度
int Length(LinkList L)
{
    LNode *p = L;
    int len = 0;
    while(p != NULL)
    {
        p = p -> next;
        len ++;
    }
    return len;
}



int main()
{
    LinkList L;
}





/*
LinkList 强调这是链表
LNode 强调这是结点

头结点看作为第0个结点
*/