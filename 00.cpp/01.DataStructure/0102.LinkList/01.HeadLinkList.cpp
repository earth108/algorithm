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

//链表插入
bool ListInsert(LinkList &L , int i , ElemType e)
{
    //判断传入的 i 是否合法
    if (i < 1)
    {
        return false;
    }
    //插入第 1 个结点 ，特殊处理
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s ->data = e;
        s -> next = L;
        L = s;
        return true;
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


int main()
{

}





/*
LinkList 强调这是链表
LNode 强调这是结点

头结点看作为第0个结点
*/