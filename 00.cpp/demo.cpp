#include <iostream>

using namespace std;

#define ElemType int

typedef struct StackNode{
    ElemType data;
    StackNode *next;
} StackNode , *LinkStack;

//链栈初始化
bool InitStack(LinkStack &S)
{
    S -> next = NULL;
    return true;
}



//入栈
bool Push(LinkStack &S , ElemType x)
{
    StackNode *p = (StackNode *) malloc (sizeof(StackNode));
    //StackNode *p = new StackNode;
    p -> data = x;
    p -> next = S;
    S = p;
    return true;
}


//出栈
bool Pop(LinkStack &S , ElemType &e)
{
    StackNode *p;
    if (S -> next == NULL) return false;
    p = S -> next;
    e = p -> data;
    S -> next = p -> next;
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
    int x;
    int top;
    LinkStack S;
    InitStack(S);
    Push(S , 3);
    Push(S , 4);
    Push(S , 5);
    Push(S , 6);

    Pop(S , x);
    cout << x << ' ';
    Pop(S , x);
    cout << x << ' ';
    Pop(S , x);
    cout << x << ' ';
    cout << endl;

    top = GetTop(S);
    cout << " 栈顶元素为：";
    cout << top;
    return 0;

}