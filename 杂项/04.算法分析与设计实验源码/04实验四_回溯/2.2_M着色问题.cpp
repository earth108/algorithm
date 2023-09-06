#include <iostream>

using namespace std;

#define NUM 100

int n;  // 矩阵大小
int m;  // 颜色数
int a[NUM][NUM];  // 矩阵
int x[NUM];  // 当前解
int sum;  // 解的总数

void BackTrack(int t) {  // 回溯算法
    int i;
    if(t > n) {  // 达到叶子节点
        sum++;  // 统计解的总数
        for(i = 1; i <= n; i++) {
            cout << x[i] << " ";  // 输出当前解
        }
        cout << endl;
    } else {
        for(i = 1; i <= m; i++) {  // 枚举颜色
            x[t] = i;  // 将第t个顶点涂上第i种颜色
            if(Same(t)) {  // 如果当前解合法，则继续搜索下一个顶点
                BackTrack(t+1);
            }
        }
    }
}

bool Same(int t) {  // 检查当前解是否合法
    int i;
    for(i = 1; i <= n; i++) {
        if(a[t][i] == 1 && x[t] == x[i]) {  // 如果相邻的两个顶点颜色相同，则解不合法
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;  // 输入矩阵大小和颜色数
    for(int i = 1; i <= n; i++) {  // 输入矩阵
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    BackTrack(1);  // 运行回溯算法

    cout << "共有" << sum << "种涂色方案" << endl;  // 输出解的总数

    return 0;
}