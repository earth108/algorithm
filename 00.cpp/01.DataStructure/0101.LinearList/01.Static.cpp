#include <iostream>

using namespace std;

#define ElemType int
#define MaxSize 10


//顺序表静态结构
typedef struct {
    ElemType data [MaxSize];
    int length;
}SqList;




//初始化顺序表
void InitList (SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

//顺序表插入元素
bool ListInsert(SqList &L , int i , int e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)
    {
        return false;
    }

    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除第i个位置的元素，并用e返回删除的元素的数值
bool ListDelete(SqList &L , int i , int &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j  = i; j >= i; j--)
    {
        L.data[j - 1] = L.data[j]; 
    }
    L.length --;
    return true;
}

//按位查找
ElemType GetElem(SqList L , int i )
{
    return L.data[i  -1];
}

//按值查找
int LocateElem(SqList L , ElemType e)
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
    SqList L;
    InitList(L);

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.length = 4;

    bool flag = ListInsert(L , 3 , 3);

    if (flag)
    {
        for (int i = 0; i < MaxSize; i++)
        {
            cout << "第" << i + 1 << "个元素是: " << L.data[i] << endl;
        }
    }

    return 0;

}
