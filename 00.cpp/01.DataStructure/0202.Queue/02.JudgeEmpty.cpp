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
typedef struct{
    ElemType data[MaxSize];
    int front , rear;
} SqQuence;







// ----- 方案b -----
typedef struct{
    ElemType data[MaxSize];
    int front , rear;
    int size = 0;
} SqQuence;




// ----- 方案c -----
typedef struct{
    ElemType data[MaxSize];
    int front , rear;
    int tag = 0;
} SqQuence;






int main()
{

}