#include <iostream>

using namespace std;

#define NUM 100

int n;  // 物品个数
int c;  // 背包容量
int w[NUM];  // 物品重量
int x[NUM];  // 当前解
int r;  // 剩余物品重量
int cw;  // 当前背包重量
int bestw;  // 最优背包重量
int bestx[NUM];  // 最优解

void backtrack(int t) 
{  
    if (t > n)
    {
        if (cw > bestw)
        {
            for (int i = 1; i <= n; i++)
            {
                bestx[i] = x[i];
            }
                bestw = cw;
        }
        return;
    }

    r -= w[t];
    if (cw + w[t] <= c)
    {
        x[t] = 1;
        cw += w[t];
        backtrack(t + 1);
        cw -= w[t];
    }
    if (cw + r > bestw)
    {
        x[t] = 0;
        backtrack(t + 1);
    }
    r += w[t];
}

int main() 
{
    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        r += w[i];
    }

    backtrack(1);  // 运行回溯算法

    cout << bestw << endl;  // 输出最优背包重量
    for(int i = 1; i <= n; i++) {  // 输出最优解
        if(bestx[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}


    // if(t > n) {  // 达到叶子节点
    //     if(cw > bestw) {  // 更新最优解
    //         for(int i = 1; i <= n; i++) {
    //             bestx[i] = x[i];
    //         }
    //         bestw = cw;
    //     }
    //     return;
    // }
    // r -= w[t];  // 调整剩余物品重量
    // if(cw + w[t] <= c) {  // 进行左子树搜索
    //     x[t] = 1;
    //     cw += w[t];
    //     Backtrack(t+1);
    //     cw -= w[t];
    // }
    // if(cw + r > bestw) {  // 进行右子树搜索
    //     x[t] = 0;
    //     Backtrack(t+1);
    // }
    // r += w[t];  // 恢复剩余物品重量