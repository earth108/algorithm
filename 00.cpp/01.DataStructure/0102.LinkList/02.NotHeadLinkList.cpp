#include <iostream>

using namespace std;


#define ElemType int




typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode , *LinkList;


// 不带头结点的单链表初始化
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

//无头结点的单链表插入数据
bool InitList(LinkList &L , int i , ElemType e)
{
    
}

int main()
{
    LinkList L;
    InitList(L);


    return 0;
}



/*
LinkList 强调这是链表
LNode 强调这是结点


*/