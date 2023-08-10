#include <iostream>
using namespace std;

#define NUM 100
int a[NUM];

int LTS_n2(int n)
{
    int b[NUM] = {0};
    int i , j;
    b[1] = 1;
    int max = 1;
    for(int i = 2; i <= n; i++)
    {
        int k = 0;
        for(j = 1; j < i; j++)
        {
            if(a[j] < a[i] && b[j] > k)
            {
                k = b[j];
            }
        }
        b[i] = k + 1;
        if(max < b[i])
        {
            max = b[i];
        }
    }
    return max;
}

int main()
{
    int n = 8;
    a[1] = 5;
    a[2] = 3;
    a[3] = 4;
    a[4] = 8;
    a[5] = 6;
    a[6] = 7;
    a[7] = 2;
    a[8] = 9;

    int len = LTS_n2(n);
    cout << "最长的单调递增子序列是 " << len << endl;

    return 0;
}