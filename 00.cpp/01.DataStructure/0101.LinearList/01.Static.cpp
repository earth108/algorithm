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

int main()
{
    SqList L;
    InitList(L);


    for (int i = 0; i <= MaxSize; i++)
    {
        cout << L.data[i] << ' ';
    }

    return 0;

}
