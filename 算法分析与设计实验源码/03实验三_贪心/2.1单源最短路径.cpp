#include <iostream>
#include <cstring>

using namespace std;

#define NUM 100
#define maxint 0x3f3f3f3f  // 定义一个无穷大的常量

void dijkstra(int n, int v, int dist[], int prev[], int c[][NUM]) {
    int i, j;
    bool s[NUM];  // 记录每个顶点是否已经确定最短路径
    for(i = 1; i <= n; i++) {
        dist[i] = c[v][i];  // 初始化距离数组
        s[i] = false;  // 初始时所有顶点都没有确定最短路径
        if(dist[i] > maxint)
            prev[i] = 0;  // 如果两个顶点之间没有边，则设置前驱为0
        else
            prev[i] = v;  // 如果两个顶点之间有边，则设置前驱为起点
    }

    dist[v] = 0;  // 起点到自己的距离为0
    s[v] = true;  // 起点已经确定最短路径

    for(i = 1; i < n; i++) {  // 循环n-1次，每次确定一个顶点的最短路径
        int tmp = maxint;
        int u = v;
        for(j = 1; j <= n; j++) {  // 在未确定最短路径的顶点中，找到距离起点最近的顶点
            if((!s[j]) && (dist[j] < tmp)) {
                u = j;
                tmp = dist[j];
            }
        }
        s[u] = true;  // 将距离起点最近的顶点加入已确定最短路径的集合

        for(j = 1; j <= n; j++) {  // 更新其他顶点到起点的距离和前驱
            if((!s[j]) && (c[u][j] < maxint)) {
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j]) {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
    }
}

int main() {
    int n, m, v;
    int c[NUM][NUM];
    int dist[NUM];
    int prev[NUM];
    cin >> n >> m >> v;

    memset(c, maxint, sizeof(c));  // 初始化边权数组
    for(int i = 1; i <= n; i++) {
        c[i][i] = 0;  // 自己到自己的距离为0
    }

    for(int i = 0; i < m; i++) {  // 读入每条边的信息
        int x, y, w;
        cin >> x >> y >> w;
        c[x][y] = w;  // 有向图的边权矩阵
    }

    dijkstra(n, v, dist, prev, c);  // 使用Dijkstra算法求最短路径

    for(int i = 1; i <= n; i++) {  // 输出每个顶点到起点的最短路径
        if(dist[i] == maxint) {
            cout << "INF" << endl;  // 如果两个顶点之间没有路径，则输出INF
        } else {
            cout << dist[i] << endl;  // 否则输出两个顶点之间的最短路径
        }
    }

    return 0;
}