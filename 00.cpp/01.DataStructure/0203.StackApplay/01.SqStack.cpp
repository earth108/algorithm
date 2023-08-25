#include <iostream>

using namespace std;

#define ElemType char
#define MaxSize 10

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack &S)
{
    if (S.top == -1) return true;
    else return false;
}

bool Push(SqStack &S , ElemType x)
{
    if (S.top == MaxSize - 1) return false; 
    S.top ++;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S , ElemType &x)
{
    if (S.top == -1) return false;
    x = S.data[S.top];
    S.top --;
    return true;
}

bool BracketCheck(char str[] , int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i ++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S , str[i]);
        }
        else
        {
            if (StackEmpty(S)) return false;
            char TopElem;
            Pop(S , TopElem);
            if (str[i] == ')' && TopElem != '(') return false;
            if (str[i] == ']' && TopElem != '[') return false;
            if (str[i] == '}' && TopElem != '{') return false;
        }
    }
    return StackEmpty(S);
}


int main()
{
    char str[10] = "{[()]}";
    cout << BracketCheck(str , 6);
    return 0;
}

