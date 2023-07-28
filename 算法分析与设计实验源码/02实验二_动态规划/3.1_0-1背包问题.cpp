#include <iostream>
using namespace std;

#define NUM 100   // 物品数量的最大值
#define CAP 1500  // 背包容量的最大值

int w[NUM];   // 物品重量的数组
int v[NUM];   // 物品价值的数组
int p[NUM][CAP];   // 存储每个容量和物品组合下能够获得的最大价值

// 计算背包能够容纳的最大价值
void knapsack(int c, int n)
{
    // 针对最后一个物品初始化
    int jMax = min(w[n] - 1, c);
    for (int j = 0; j <= jMax; j++)
    {
        p[n][j] = 0;
    }
    for (int j = w[n]; j <= c; j++)
    {
        p[n][j] = v[n];
    }

    // 从后往前计算每个物品的最大价值
    for (int i = n - 1; i > 1; i--)
    {
        // 计算当前物品的最大容量
        jMax = min(w[i] - 1, c);

        // 不选取当前物品
        for (int j = 0; j <= jMax; j++)
        {
            p[i][j] = p[i + 1][j];
        }

        // 选取当前物品
        for (int j = w[i]; j <= c; j++)
        {
            p[i][j] = max(p[i + 1][j], p[i + 1][j - w[i]] + v[i]);
        }
    }

    // 处理第一个物品
    p[1][c] = p[2][c];
    if (c >= w[1])
    {
        p[1][c] = max(p[1][c], p[2][c - w[1]] + v[1]);
    }
}

int main()
{
    // 初始化物品重量和价值
    int c = 5;
    int n = 4;
    w[1] = 1;  v[1] = 1;
    w[2] = 2;  v[2] = 3;
    w[3] = 3;  v[3] = 5;
    w[4] = 4;  v[4] = 7;

    // 计算背包能够容纳的最大价值
    knapsack(c, n);

    // 输出背包能够容纳的最大价值
    cout << "最大价值是 " << p[1][c] << endl;

    return 0;
}