#include <iostream>
#include <algorithm>

using namespace std;

#define NUM 100

int c;  // 背包容量
int n;  // 物品个数
int cw;  // 当前背包重量
int cv;  // 当前价值
int bestv;  // 最优价值

struct Object {  // 物品结构体
    int w;  // 物品重量
    int v;  // 物品价值
    double d;  // 单位重量价值
} Q[NUM];

int Bound(int i) {  // 计算上界函数
    int cleft = c - cw;  // 剩余背包容量
    int b = cv;  // 当前价值
    while(i <= n && Q[i].w <= cleft) {  // 尽量装满背包
        cleft -= Q[i].w;
        b += Q[i].v;
        i++;
    }
    if(i <= n) {  // 装满剩余背包容量的物品
        b += cleft*Q[i].d;
    }
    return b;
}

bool cmp(Object a, Object b) {  // 按单位重量价值降序排序
    if(a.d > b.d) return true;
    return false;
}

void Backtrack(int i) {  // 回溯算法
    if(i + 1 > n) {  // 达到叶子节点
        bestv = cv;  // 更新最优解
        return;
    }
    if(cw + Q[i].w <= c) {  // 进行左子树搜索
        cw += Q[i].w;
        cv += Q[i].v;
        Backtrack(i+1);
        cw -= Q[i].w;
        cv -= Q[i].v;
    }
    if(Bound(i + 1) > bestv) {  // 进行右子树搜索
        Backtrack(i+1);
    }
}

int main() {
    cin >> c >> n;
    for(int i = 1; i <= n; i++) {
        cin >> Q[i].w >> Q[i].v;
        Q[i].d = (double)Q[i].v/Q[i].w;
    }

    sort(Q+1, Q+n+1, cmp);  // 对物品按单位重量价值排序

    Backtrack(1);  // 运行回溯算法

    cout << bestv << endl;  // 输出最优价值

    return 0;
}