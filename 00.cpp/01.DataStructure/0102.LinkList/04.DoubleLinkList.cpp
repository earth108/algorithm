#include <iostream>

using namespace std;

#define ElemType int 

typedef struct DNode{
    ElemType data;
    struct DNode *prior , *next;
} DNode , *DLinkList;


// 初始化双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DLinkList) malloc(sizeof(DNode));    
    if ( L == NULL) return false;
    L -> prior = NULL;
    L -> next = NULL;
    return true;
}


// 双链表 在 p 结点之后插入 s 结点
bool InsertNextDNode(DNode *p , DNode *s)
{
    if (p == NULL || s == NULL) return false;
    s -> next = p -> next;
    if (p -> next != NULL)
    {
        p -> next -> prior = s;
    }
    s -> prior = p;
    p -> next = s;
}

//删除 p 结点的后续结点
bool DeleteNextDNode(DLinkList p)
{
    if (p == NULL) return false;
    DNode *q = p -> next;
    if (q == NULL) return false;
    p -> next = q -> next;
    if (q -> next != NULL)
    {
        q -> next -> prior = p;
    }
    free(q);
    return true;

}

// 销毁链表
void DestoryList(DLinkList &L)
{
    while (L -> next != NULL)
    {
        DeleteNextDNode(L -> next);
    }
    free(L);
    L -> next = NULL;
}





int main()
{

}



/*
DLinkList强调是一个双链表
DNode强调是一个结点


*/