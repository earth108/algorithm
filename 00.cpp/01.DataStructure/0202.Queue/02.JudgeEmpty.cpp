#include <iostream>

using namespace std;

#define ElemType int
#define MaxSize 10

//循环队列，用模运算将存储空间在逻辑上变为“环状”


//确定判空判满的方法
/*
a.牺牲一个存储空间

b.增加size变量记录队列长度

c.增加tag = 0/1 用于标记
最近一次的操作是出队/入队
*/


// ----- 方案a -----
//循环队列
// 本质上，队列留出一个空的位置，以便于判断队列是否满

typedef struct{
    ElemType data[MaxSize];
    int front , rear;
} a_SqQuence;

//初始化
bool a_InitQurnce(a_SqQuence &Q)
{
    Q.rear = Q.front = 0;
    return true;
}

//入队
bool a_EnQuence(a_SqQuence &Q , ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队
bool a_DeQuence(a_SqQuence &Q , ElemType &e)
{
    if (Q.rear == Q.front) return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//获取队头元素
bool a_GetHead(a_SqQuence &Q , ElemType &x)
{
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    return true;
}

//获取队列元素个数
int a_GetLength(a_SqQuence &Q)
{
    int x = (Q.rear + MaxSize - Q.front) % MaxSize;
    return x;
}



// -----------------------------------------------------------------------------------



// ----- 方案b -----
typedef struct{
    ElemType data[MaxSize];
    int front , rear;
    int size = 0;
} b_SqQuence;

//初始化
bool b_InitQurnce(b_SqQuence &Q)
{
    Q.rear = Q.front = 0;
    Q.size = 0;
    return true;
}
//入队
bool b_EnQuence(b_SqQuence &Q , ElemType x)
{
    if (Q.size == MaxSize) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.size++;
    return true;
}
//出队
bool b_DeQuence(b_SqQuence &Q , ElemType &e)
{
    if (Q.size == 0) return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}
// 获取队头元素
bool b_GetHead(b_SqQuence &Q , ElemType &x)
{
    if (Q.size == 0) return false;
    x = Q.data[Q.front];
    return true;
}
// 获取队列元素个数
int b_GetLength(b_SqQuence &Q)
{
    return Q.size;
}



// -----------------------------------------------------------------------------------


// ----- 方案c -----
/*
增加tag = 0/1 用于标记
/最近一次的操作是出队/入队
*/

typedef struct{
    ElemType data[MaxSize];
    int front , rear;
    int tag = 0;
} c_SqQuence;



//初始化
bool c_InitQurnce(c_SqQuence &Q)
{
    Q.rear = Q.front = 0;
    Q.tag = 0;
    return true;
}
//入队
bool c_EnQuence(c_SqQuence &Q , ElemType x)
{
    if (Q.rear == Q.front && Q.tag == 1) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}
//出队
bool c_DeQuence(c_SqQuence &Q , ElemType &e)
{
    if (Q.rear == Q.front && Q.tag == 0) return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}
// 获取队头元素
bool c_GetHead(c_SqQuence &Q , ElemType &x)
{
    if (Q.rear == Q.front && Q.tag == 0) return false;
    x = Q.data[Q.front];
    return true;
}
// 获取队列元素个数
int c_GetLength(c_SqQuence &Q)
{
    int x = (Q.rear + MaxSize - Q.front) % MaxSize;
    return x;
}


int main()
{

}