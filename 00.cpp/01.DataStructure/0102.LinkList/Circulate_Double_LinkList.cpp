#include <iostream>

using namespace std;

#define ElemType int


typedef struct DNode{
    ElemType data;
    struct DNode *prior , *next;
} DNOde , *DLinkList;


// 初始化空的循环双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *) malloc (sizeof(DNode));
    if (L == NULL) return false;
    L -> prior = L;
    L -> next = L;
    return true;
}

//判断循环双链表是否为空
bool Empty(DLinkList L)
{
    if ( L-> next == L) return true;
    else return false;
}

//判断结点 p 是否为循环双链表的尾结点
bool IsTail(DLinkList L , DNode *p)
{
    if (p -> next == L) return true;
    else return false;
}


int main()
{

}

