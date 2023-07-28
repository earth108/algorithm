#include <iostream>
#include <algorithm>

using namespace std;

struct action  // 定义活动结构体
{
    int s;  // 活动开始时间
    int f;  // 活动结束时间
    int index;  // 活动编号，用于输出结果
};

action a[1000];  // 定义活动数组

bool cmp(action a, action b)  // 活动按照结束时间从小到大排序的比较函数
{
    if(a.f <= b.f) return true;
    return false;
}

void GreedySelector(int n, action a[], bool b[])  // 贪心选择活动的算法
{
    b[1] = true;  // 第一个活动一定被选中
    int preEnd = 1;  // 记录上一个选中的活动的结束时间
    for(int i = 2; i <= n; i++)  // 从第二个活动开始考虑
    {
        if(a[i].s >= a[preEnd].f)  // 如果当前活动的开始时间晚于等于上一个选中的活动的结束时间，就选择当前活动
        {
            b[i] = true;
            preEnd = i;  // 更新上一个选中的活动
        }
    }
}

int main()
{
    int n;
    cout << "请输入活动数量：";
    cin >> n;

    for(int i = 1; i <= n; i++)  // 读入每个活动的开始时间和结束时间
    {
        cout << "请输入第" << i << "个活动的开始时间和结束时间：";
        cin >> a[i].s >> a[i].f;
        a[i].index = i;
    }

    sort(a+1, a+n+1, cmp);  // 按照结束时间从小到大排序

    bool b[1000] = {false};  // 记录每个活动是否被选择

    GreedySelector(n, a, b);  // 使用贪心算法选择活动

    cout << "贪心选择的活动编号为：";
    for(int i = 1; i <= n; i++)  // 输出被选择的活动的编号
    {
        if(b[i])
        {
            cout << a[i].index << " ";
        }
    }
    cout << endl;

    return 0;
}