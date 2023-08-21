#include <iostream>

using namespace std;

#define ElemType int

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct{
    LinkNode *front , *rear;
}LinkQueue;



//初始化队列（带头结点）
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *) malloc (sizeof(LinkNode));
    Q.front -> next = NULL;
}

//判断是否为空
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear) return true;
    else return false;
}

//入队
void EnQueue(LinkQueue &Q , ElemType x)
{
    LinkNode *s = (LinkNode *) malloc (sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    Q.rear -> next = s;
    Q.rear = s;
}

//出队
bool DeQueue(LinkQueue &Q , ElemType &x)
{
    if (Q.front == Q.rear) return false;
    LinkNode *p = Q.front -> next;
    x = p -> data;
    Q.front -> next = p -> next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}










// ---------------不带头结点----------------

//初始化（不带头结点）
void InitQueue(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}

//判断是否为空
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == NULL) return true;
    else return false;
}

//入队
void EnQueue(LinkQueue &Q , ElemType x)
{
    LinkNode *s = (LinkNode *) malloc (sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    if (Q.front == NULL)
    {
        Q.front = s;
        Q.rear = s;
    }
    else
    {
        Q.rear -> next = s;
        Q.rear = s;
    }
}

//出队
bool DeQueue(LinkQueue &Q , ElemType &x)
{
    if (Q.front == NULL) return false;
    LinkQueue *p = Q.front;
    x = p -> data;
    Q.front = p -> next;
    if (Q.rear == p)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}


int main()
{

}