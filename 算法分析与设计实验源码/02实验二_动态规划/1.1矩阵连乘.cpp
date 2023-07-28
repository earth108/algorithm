#include <iostream>
using namespace std;

#define NUM 51

int p[NUM];
int m[NUM][NUM];
int s[NUM][NUM];

void MatrixChain(int n)
{
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for(int r = 2; r <= n; r++)
    {
        for(int i = 1; i <= n-r+1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(int k = i+1; k < j; k++)
            {
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void PrintOptimalParens(int s[][NUM], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}


int main()
{
    int n = 7;
    p[0] = 50;
    p[1] = 10;
    p[2] = 40;
    p[3] = 30;
    p[4] = 5;
    p[5] = 20;
    p[6] = 15;

    MatrixChain(n);

    cout << "最小值是 " << m[1][n-1] << endl;


    // 输出最优解的坐标
    cout << "最优解的坐标为：" << endl;
    PrintOptimalParens(s, 1, n);
    cout << endl;

    return 0;
}