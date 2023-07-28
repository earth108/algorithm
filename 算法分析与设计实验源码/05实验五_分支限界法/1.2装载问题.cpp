#include <iostream>
#include <queue>

#define NUM 100
using namespace std;

int n;      // 货物数量
int c;      // 载重限制
int w[NUM]; // 货物重量

int MaxLoading()
{
    queue <int> Q;      // 队列Q用于维护当前已知的可行解集合
    Q.push(-1);         // 用-1作为分隔符，表示当前可行解集合中的所有解都已经被扩展完成
    int i = 0;          // i表示当前扩展的节点的下标
    int Ew = 0;         // Ew表示当前扩展的节点的剩余载重
    int bestw = 0;      // bestw表示找到的最优解的载重
    int r = 0;          // r表示剩余货物的总重量
    for (int j = 1; j <= n; j++)    // 计算r的初始值
    {
        r += w[j];
    }
    while (true)
    {
        int wt = Ew + w[i];     // wt表示将第i个货物装入当前扩展的节点后得到的新节点的剩余载重
        if (wt <= c)    // 如果新节点是可行解
        {
            if (wt > bestw)     // 如果新节点的载重优于当前最优解的载重
            {
                bestw = wt;     // 更新最优解的载重
            }
            if (i < n - 1)      // 如果还有未扩展的节点
            {
                Q.push(wt);     // 将新节点加入队列，作为可行解集合的一部分
            }
        }
        if (Ew + r > bestw && i < n - 1)    // 如果剩余货物的总重量加上当前扩展的节点的载重仍然大于当前最优解的载重，并且还有未扩展的节点
        {
            Q.push(Ew);     // 将当前扩展的节点不装入货物的情况加入队列，作为可行解集合的一部分
        }
        Ew = Q.front();     // 从队列中取出下一个待扩展的节点
        Q.pop();
        if (Ew == -1)       // 如果取出的节点是分隔符
        {
            if (Q.empty())      // 如果队列已经空了
            {
                return bestw;   // 返回找到的最优解的载重
            }
            Q.push(-1);         // 将分隔符重新加入队列
            Ew = Q.front();     // 从队列中取出下一个待扩展的节点
            Q.pop();
            i++;                // 扩展下一个节点
            r -= w[i];          // 更新剩余货物的总重量
        }
    }
    return bestw;
}

int main()
{
    // 输入数据
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    // 用分支限界算法求解装载问题
    int maxw = MaxLoading();

    // 输出结果
    cout << maxw << endl;

    return 0;
}