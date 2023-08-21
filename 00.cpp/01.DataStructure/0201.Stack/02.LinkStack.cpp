#include <iostream>

using namespace std;

#define ElemType int

//链头作为栈顶

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
} StackNode , *LinkStack;


//链栈初始化
bool InitStack(LinkStack &S)
{
    S = NULL;
    return true;
}

//入栈
bool Push(LinkStack &S , ElemType e)
{
    StackNode *p;
    p = (StackNode *) malloc(sizeof(StackNode));
    p -> data = e;
    p -> next = S;    //新节点插入栈顶
    S = p;            //修改栈顶指针为p
}


//出栈
bool Pop(LinkStack &S , ElemType &e)
{
    StackNode *p;
    if (S == NULL) return false;
    e = S -> data;
    p = S;
    S = S -> next;
    free(p);
    return true;
}

//取栈顶元素
ElemType GetTop(LinkStack S)
{
    if (S != NULL)
    {
        return S -> data;
    }
}







int main()
{

}