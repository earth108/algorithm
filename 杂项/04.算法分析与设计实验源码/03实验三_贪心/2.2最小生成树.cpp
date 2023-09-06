#include <iostream>
#include <cstring>

using namespace std;

#define NUM 1000
#define maxint 0x3f3f3f3f  // 定义一个无穷大的常量

void Prim(int n, int c[][NUM]) 
{
    int lowcost[NUM];  // 记录当前顶点到已确定最小生成树的距离
    int closest[NUM];  // 记录当前顶点到已确定最小生成树中的最近顶点
    bool s[NUM] = {false};  // 记录每个顶点是否已经确定最小生成树

    for(int i = 1; i <= n; i++) {  // 初始化
        lowcost[i] = c[1][i];  // 初始化每个顶点到起点的距离
        closest[i] = 1;  // 初始化每个顶点到已确定最小生成树中的最近顶点为起点
        s[i] = false;  // 初始时所有顶点都没有确定最小生成树
    }

    s[1] = true;  // 起点已经确定最小生成树

    for(int i = 1; i < n; i++) {  // 循环n-1次，每次确定一个顶点的最小生成树
        int min = maxint;  // 记录离已确定最小生成树最近的顶点的距离
        int j = 1;
        for(int k = 2; k <= n; k++) {  // 在未确定最小生成树的顶点中，找到距离已确定最小生成树最近的顶点
            if((!s[k]) && (lowcost[k] < min)) {
                min = lowcost[k];
                j = k;
            }
        }
        cout << closest[j] << " " << j << endl;  // 输出已确定最小生成树的一条边
        s[j] = true;  // 将距离已确定最小生成树最近的顶点加入已确定最小生成树的集合

        for(int k = 2; k <= n; k++) {  // 更新其他顶点到已确定最小生成树的距离和最近顶点
            if((!s[k]) && (c[j][k] < lowcost[k])) {
                lowcost[k] = c[j][k];
                closest[k] = j;
            }
        }
    }
}

int main() 
{
    int n, m;
    int c[NUM][NUM];  // 存储边权的邻接矩阵
    cin >> n >> m;

    memset(c, maxint, sizeof(c));  // 初始化边权矩阵

    for(int i = 0; i < m; i++) {  // 读入每条边的信息
        int x, y, w;
        cin >> x >> y >> w;
        c[x][y] = w;  // 无向图的边权矩阵
        c[y][x] = w;  // 无向图，因此边权矩阵需要对称
    }

    Prim(n, c);  // 使用Prim算法求最小生成树

    return 0;
}