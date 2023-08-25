#include <iostream>

using namespace std;

#define ElemType int

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode , *LinkStack;


void InitStack(LinkStack &S)
{
    S  = NULL;
}

bool StackEmpty(LinkStack S)
{
    if (S == NULL) return true;
    else return false;
}

bool Push(LinkStack &S , ElemType x)
{
    LinkNode *p = (LinkNode *) malloc (sizeof(LinkNode));
    p -> data = x;
    p -> next = S;
    S = p;
    return true;
}

bool Pop(LinkStack &S , ElemType &x)
{
    if (S == NULL) return false;
    LinkNode *p;
    x = S -> data;
    p = S;
    S = S -> next;
    free(p);
    return true;
}

bool demo(char str[] , int length)
{
    LinkStack S;
    InitStack(S);
    for (int i = 0; i< length; i++)
    {
        if (str[i]  == '1' || str[i] == '2')
        {
            Push(S , str[i]);
        }
        else
        {


        }

    }
}





int main()
{
    cout << 1 + 1 << endl;
    return 0;
}


// 15 7 1 1 + - / 3 * 2 1 1 + + -