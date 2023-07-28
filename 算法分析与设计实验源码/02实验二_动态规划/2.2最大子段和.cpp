#include <iostream>
using namespace std;

#define NUM 1001
int a[NUM];

int MaxSum(int n , int &besti , int &bestj)
{
    int sum = 0;
    int b = 0;
    int begin = 0;
    besti = 0;
    bestj = 0;
    for(int i = 0; i < n; i++)
    {
        if(b > 0)
        {
            b += a[i];
        }
        else
        {
            b = a[i];
            begin = i;
        }
        if(b > sum)
        {
            sum = b;
            besti = begin;
            bestj = i;
        }
    }
    return sum;
}

int main()
{
    int n = 9;
    a[0] = 6;
    a[1] = -1;
    a[2] = 2;
    a[3] = -4;
    a[4] = 3;
    a[5] = 1;
    a[6] = -2;
    a[7] = 7;
    a[8] = -5;

    int besti, bestj;
    int sum = MaxSum(n, besti, bestj);
    cout << "最大子段和是 " << sum << endl;
    cout << "开始在" << besti + 1 << " 结束在 " << bestj + 1 << endl;

    return 0;
}