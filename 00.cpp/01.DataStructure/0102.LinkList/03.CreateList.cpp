#include <iostream>

using namespace std;


#define ElemType int 


typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode , *LinkList;

//初始化一个单链表 ， 带头结点
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if ( L == NULL) return false;
    L -> next = NULL;
    return true;
}


//在 p 元素之后插入元素 e
bool InsertNextNode(LNode *p , ElemType e)
{
    if  (p == NULL ) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s ->data = e;
    s ->next = p -> next;
    p ->next = s;
    return true;
}


// 尾插法
LinkList List_TailInsert(LinkList &L)
{
    int x;

    L = (LinkList) malloc(sizeof(LNode));   // 建立头结点
    LNode *s , *r = L;                      // r 为指向表尾结点的指针
    cout << " 请输入元素的值" << endl;
    cin >> x;
    while(x != 9999) // 输入 9999 表示结束
    {
        s = (LNode *) malloc(sizeof(LNode));
        s -> data = x;
        r -> next = s;
        r = s;      // r 指向新的表尾结点
        cout << " 请输入元素的值" << endl;
        cin >> x;
    }

    r -> next = NULL;
    return L;
}


// 头插法
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    LNode *s;
    L = (LinkList) malloc(sizeof(LNode));
    L -> next = NULL;
    cout << " 请输入元素的值：" << endl;
    cin >> x;
    while( x != 9999)
    {
        s = (LNode *) malloc(sizeof(LNode));
        s -> data = x;
        s -> next = L -> next;
        L -> next = s;     // 将新结点插入表中 , L为头指针
        cout << " 请输入元素的值：" << endl;
        cin >> x;
    }   
    return L;
}





int main()
{
    LinkList L;

    List_TailInsert(L);
    LNode *p = L -> next;
    while(p != NULL)
    {
        cout << " 值为： ";
        cout << p -> data << ' ' ;
        p = p -> next;
    }
    return 0;

}