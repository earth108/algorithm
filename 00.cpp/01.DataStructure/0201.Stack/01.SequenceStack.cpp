#include <iostream>

using namespace std;

#define MaxSize 10
#define ElemType int


//顺序栈
typedef struct {
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top;   //栈顶指针
} SqStack;


//初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack S)
{
    if (S.top == -1) return true;
    else return false;
}

//新元素入栈
bool push(SqStack &S , ElemType x)
{
    if (S.top == MaxSize-1) return false; //栈满
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

//出栈操作
bool Pop(SqStack &S , ElemType &x)
{
    if (S.top == -1) return false;  //栈空
    x = S.data[S.top];
    S.top = S.top - 1;
    return true;
}

//读取栈顶元素
bool GetTop(SqStack S , ElemType &x)
{
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}




int main()
{
    SqStack S;
}