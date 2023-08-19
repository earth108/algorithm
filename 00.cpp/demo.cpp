#include <iostream>

using namespace std;


#define ElemType int


typedef struct DNode{
    ElemType data;
    struct DNode *prior , *next;
}DNode , *DLinkList;



// 双链表 在 p 结点之后插入 s 结点
bool InsertNextDNode(DNode *p , DNode *s)
{
    s -> next = p -> next;
    if (p ->next != NULL)
    {
        p ->next -> prior = s;
    }
    p -> next = s;
    s -> prior = p;
}


//删除 p 结点的后续结点
bool DeleteNextDNode(DLinkList p)
{
    if (p == NULL) return false;
    DNode *q = p -> next;
    p -> next = q -> next;
    if (q -> next != NULL)
    {
        q -> next -> prior = p;
    }
    free(q);
    return true;
}



int main()
{
    cout << "Hello World!" << endl;
    int n;
    cin >> n;
    cout << n + 1 << endl;
    return 0;
}