#include <iostream>
#include <cmath>

using namespace std;

#define NUM 20

int n;  // 皇后个数
int x[NUM];  // 当前解
int sum;  // 解的总数

inline bool Place(int t) {  // 检查放置皇后是否合法
    int i;
    for(i = 1; i < t; i++) {
        if((abs(t - i) == abs(x[i] - x[t])) || (x[i] == x[t])) {  // 判断是否在同一列或对角线
            return false;
        }
    }
    return true;
}

void Backtrack(int t) {  // 回溯算法
    int i;
    if(t > n) {  // 达到叶子节点
        sum++;  // 统计解的总数
        for(i = 1; i <= n; i++) {
            cout << x[i] << " ";  // 输出当前解
        }
        cout << endl;
    } else {
        for(i = 1; i <= n; i++) {  // 枚举皇后放置的列
            x[t] = i;  // 放置皇后
            if(Place(t)) {  // 如果放置皇后合法，则继续搜索下一行
                Backtrack(t+1);
            }
        }
    }
}

int main() {
    cin >> n;

    Backtrack(1);  // 运行回溯算法

    cout << sum << endl;  // 输出解的总数

    return 0;
}