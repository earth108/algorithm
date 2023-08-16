#include <iostream>

using namespace std;

#define ElemType int


typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode , *LinkList;


// 初始化一个循环单链表
bool InitList(LinkList &L)
{
    L = (LNode *) malloc (sizeof(LNode));
    if (L == NULL) return false;
    L ->next = L;
    return true;
}

//判断循环单链表是否为空
bool Empty(LinkList L)
{
    if ( L -> next = L) return true;
    else return false;
}

//判断结点 p 是否为 循环单链表的表尾结点
bool IsTail(LinkList L , LNode *p)
{
    if (p -> next == L) return true;
    else return false;
}

int main()
{
    
}



/*
循环单链表 ， 从一个结点出发
可以找到其他任何一个结点

*/