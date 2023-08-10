#include <iostream>
#include <algorithm>

using namespace std;

struct bag  // 定义物品结构体
{
    double w;  // 物品重量
    double v;  // 物品价值
    double c;  // 物品单位重量的价值
}a[1001];  // 定义物品数组

bool cmp(bag a, bag b)  // 按照物品单位重量的价值从大到小排序的比较函数
{
    if(a.c >= b.c) return true;
    return false;
}

double knapsack(int n, bag a[], double c)  // 0-1背包问题的贪心算法
{
    sort(a, a+n, cmp);  // 按照物品单位重量的价值从大到小排序

    double cleft = c;  // 记录背包剩余容量
    int i = 0;  // 记录当前考虑的物品下标
    double b = 0;  // 记录已经获得的最大价值

    while(i < n && a[i].w <= cleft)  // 当背包未装满且还有物品可以考虑时
    {
        cleft -= a[i].w;  // 将当前物品放入背包中
        b += a[i].v;
        i++;
    }
    if(i < n)  // 如果还有剩余的容量，就将单位重量的价值最高的物品部分放入背包中
    {
        b += a[i].v * cleft / a[i].w;
    }
    return b;  // 返回获得的最大价值
}

int main()
{
    int n;
    double c;
    cout << "请输入物品数量和背包容量：";
    cin >> n >> c;

    for(int i = 0; i < n; i++)  // 读入每个物品的重量和价值，并计算单位重量的价值
    {
        cout << "请输入第" << i+1 << "个物品的重量和价值：";
        cin >> a[i].w >> a[i].v;
        a[i].c = a[i].v / a[i].w;
    }

    double max_value = knapsack(n, a, c);  // 使用贪心算法解决0-1背包问题

    cout << "可获得的最大价值为：" << max_value << endl;

    return 0;
}