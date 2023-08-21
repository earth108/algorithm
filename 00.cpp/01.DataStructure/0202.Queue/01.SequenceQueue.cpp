#include <iostream>

using namespace std;

#define ElemType int
#define MaxSize 10

typedef struct{
    ElemType data[MaxSize];
    int front , rear;
} SqQuence;

//初始化顺序队列
void InitQuence(SqQuence &Q)
{
    Q.rear = Q.front = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQuence Q)
{
    if (Q.rear += Q.front) return true;
    else return false;
}


//入队
bool EnQuence(SqQuence &Q , ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队
bool DeQuence(SqQuence &Q , ElemType &x)
{
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}













int main()
{
    SqQuence Q;
}