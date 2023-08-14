#include <iostream>

using namespace std;

#define ElemType int 
#define InitSize 10

typedef struct {
    int *data;     //动态分配的数组指针
    int MaxSize;   //顺序表的容量
    int length;    //当前长度
}SeqList;

void InitList(SeqList &L)
{
    //malloc申请一片连续的存储空间
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L , int len)
{
    int *p = L.data;
    L.data = (int *)malloc( (L.MaxSize+len) * sizeof(int) );
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

//按位查找
ElemType GetElem(SeqList L , int i)
{
    return L.data[i - 1];
}

//按值查找
int LocateElem(SeqList L , ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;  //下标为i , 返回次序i + 1
        }
    }
    return 0;
}


int main()
{
    SeqList L;
    InitList(L);
    IncreaseSize(L , 5);
    return 0;
}