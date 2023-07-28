#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 1005;  // 站点数量的最大值

int n;  // 站点数量
int g[MAXN][MAXN];  // 租金矩阵
int dis[MAXN];  // 起点到各个站点的最短租金
bool vis[MAXN];  // 标记站点是否已经访问过

void dijkstra() {
    fill(dis, dis + n + 1, INT_MAX);  // 将dis数组初始化为INT_MAX，表示从起点1到任何站点的租金都是无限大
    dis[1] = 0;  // 起点1到自己的租金为0
    for (int i = 1; i <= n; i++) {  // 循环n次，每次确定一个距离最短的未访问过的站点
        int u = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (u == 0 || dis[j] < dis[u])) {  // 找到未访问过的距离最短的站点u
                u = j;
            }
        }
        vis[u] = true;  // 将站点u标记为已访问
        for (int v = 1; v <= n; v++) {  // 更新所有未访问过的站点v的租金
            if (g[u][v] != -1) {  // 如果从u到v之间有租金
                dis[v] = min(dis[v], dis[u] + g[u][v]);  // 更新dis[v]的值
            }
        }
    }
}

int main() {
    cin >> n;  // 输入站点数量
    for (int i = 1; i < n; i++) {  // 输入租金矩阵
        for (int j = i + 1; j <= n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];  // 租金矩阵是对称矩阵，因此g[j][i]和g[i][j]的值相等
        }
    }
    dijkstra();  // 使用Dijkstra算法计算最短租金
    cout << dis[n] << endl;  // 输出从起点1到终点n的最短租金
    return 0;
}