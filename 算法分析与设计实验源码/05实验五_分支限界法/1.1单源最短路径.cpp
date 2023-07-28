#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define inf 1000000
#define NUM 100

int n;              // 图的顶点数
int edge;           // 图的边数
int c[NUM][NUM];    // 图的邻接矩阵
int prev[NUM];      // 记录最短路径中每个节点的前驱节点
int dist[NUM];      // 记录从源节点到每个节点的最短距离

struct MinHeapNode {    // 定义最小堆中的节点结构体
    int i;              // 节点编号
    int length;         // 距离值
    friend bool operator<(const MinHeapNode& a, const MinHeapNode& b) // 定义小于运算符，用于堆的排序
    {
        if (a.length > b.length) return true;
        else return false;
    }
};

void ShortestPaths(int v)   // 求解从源节点v到其他所有节点的最短路径
{
    priority_queue<MinHeapNode, vector<MinHeapNode> , less<MinHeapNode> > H; // 定义最小堆H

    MinHeapNode E;
    E.i = v;
    E.length = 0;
    dist[v] = 0;        // 源节点到自身的距离为0

    while (true)
    {
        for (int j = 1; j <= n; j++)
        {
            if (c[E.i][j] < inf && (E.length + c[E.i][j] < dist[j])) // 如果当前节点能够到达节点j，并且经过当前节点到达节点j的距离比原先的最短距离更短
            {
                dist[j] = E.length + c[E.i][j];     // 更新节点j的最短距离
                prev[j] = E.i;                      // 更新节点j的前驱节点为当前节点
                MinHeapNode N;
                N.i = j;
                N.length = dist[j];
                H.push(N);                          // 将节点j加入最小堆H中，等待扩展
            }
        }
        if (H.empty()) break;           // 如果最小堆H为空，说明所有的节点都已经被扩展完成了，退出循环
        else
        {
            E = H.top();                // 从最小堆H中取出距离值最小的节点E
            H.pop();                    // 将节点E从最小堆H中移除
        }
    }
}

int main()
{
    // 输入图的邻接矩阵
    cin >> n >> edge;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) c[i][j] = 0;        // 自身到自身的距离为0
            else c[i][j] = inf;             // 未直接相连的节点之间的距离初始化为无穷大
        }
    }
    for (int i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;                        // 更新邻接矩阵中节点u到节点v之间的距离为w
    }

    // 求解从源节点1到其他所有节点的最短路径
    ShortestPaths(1);

    // 输出从源节点1到所有其他节点的最短距离和路径
    for (int i = 1; i <= n; i++)
    {
        cout << "从节点1到节点" << i << "的最短距离为" << dist[i] << endl;
        cout << "从节点1到节点" << i << "的最短路径为 ";
        int p = i;
        while (p != 1)
        {
            cout << p << " <- ";            // 输出路径中的节点
            p = prev[p];                    // 更新节点p为当前节点的前驱节点
        }
        cout << "1" << endl;
    }

    return 0;
}