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
