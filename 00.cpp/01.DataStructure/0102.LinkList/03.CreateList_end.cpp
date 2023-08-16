#include <iostream>

using namespace std;


#define ElemType int


typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode , LinkList;

//初始化一个单链表 ， 带头结点
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if ( L  == NULL) return false;
    L ->next = NUll;
    return true;
}



//尾插法建立单链表
//在第 i 个位置插入元素 e（带头结点）
bool ListInsert(LinkList &L , int i , ElemType e)
{
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p -> next;
        j ++;
    }
    if (p == NULL) return false; // i 值不合法
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s -> data = e;
    s ->next = p -> next;
    p -> next = s;
    return true;
}


int main()
{

}