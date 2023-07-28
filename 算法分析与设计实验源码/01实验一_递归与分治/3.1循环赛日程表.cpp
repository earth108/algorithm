#include <iostream>

using namespace std;


#define MAX 100
int a[MAX][MAX];

void Copy(int tox , int toy , int fromx , int fromy , int r)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0 ; j < r; j++)
        {
            a[tox + i][toy + j] = a[fromx + i][fromy + j];
        }
    }
}

void Table(int k)
{
    int i , r;
    int n = 1 << k;
    for(i = 0; i < n; i++)
    {
        a[0][i] = i + 1;
    }
    for(r = 1; r < n; r << 1)
    {
        for(i = 0; i < n; i += 2*r)
        {
            Copy(r , r + 1 , 0 , i , r);
            Copy(r , i, 0 , r + i , r);
        }
    }
}


int main()
{
    int k;
    cout << "请输入k的值：";
    cin >> k;
    Table(k);
    int n = 1 << k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}