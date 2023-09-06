#include <iostream>
#include <cstring>
using namespace std;

#define NUM 100

int c[NUM][NUM];
int b[NUM][NUM];

void LCSLength(int m , int n , const char x[] , char y[])
{
    int i , j;
    for(i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for(j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i] == y[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

int main()
{
    char x[] = "ABCBDAB";
    char y[] = "BDCABA";
    int m = strlen(x);
    int n = strlen(y);
    LCSLength(m, n, x, y);
    // cout << "Length of LCS is " << c[m][n] << endl;

    // 通过b数组反向追踪路径，输出最长公共子序列
    int i = m;
    int j = n;
    char lcs[NUM];
    int len = 0;
    while (i > 0 && j > 0) {
        if (b[i][j] == 1) {
            lcs[len] = x[i];
            i--;
            j--;
            len++;
        }
        else if (b[i][j] == 2) {
            i--;
        }
        else {
            j--;
        }
    }
    cout <<"最长公共子序列是";
    for (i = len - 1; i >= 0; i--) {
        cout << lcs[i];
    }
    cout << endl;

    return 0;
}