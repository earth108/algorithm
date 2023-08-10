
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, ans;
vector<vector<int>> graph;

struct Node {  // 定义状态结构体
    int cur, cost, lb;
    vector<int> path;
    bool operator<(const Node& other) const {  // 重载<运算符
        return lb > other.lb;  // 优先队列中按照lb从小到大排序
    }
};

int get_lb(const Node& node) {  // 计算下界
    int sum = node.cost;
    vector<int> min1(n, INF), min2(n, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] < min1[i]) {  // 找到第i行的最小值和次小值
                min2[i] = min1[i];
                min1[i] = graph[i][j];
            } else if (graph[i][j] < min2[i]) {
                min2[i] = graph[i][j];
            }
        }
        sum += min1[i] + min2[i];  // 计算下界
    }
    if (node.path.size() == n - 1) {  // 如果还剩下最后一个城市未遍历
        int last = 0;  // 找到最后一个城市
        for (int i = 0; i < n - 1; i++) {
            if (find(node.path.begin(), node.path.end(), i) == node.path.end()) {
                last = i;
                break;
            }
        }
        sum += graph[last][0];  // 加上从最后一个城市到第一个城市的距离
    }
    return sum;
}

void branch_and_bound() {
    priority_queue<Node> pq;
    pq.push({0, 0, get_lb({0, 0, 0, {}}), {0}});
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        if (node.lb >= ans) {  // 剪枝：如果当前节点的下界大于等于已知的最短路径长度，就不需要继续搜索了
            continue;
        }
        if (node.cur == 0 && node.path.size() == n) {  // 如果已经遍历完所有城市
            if (node.cost < ans) {  // 更新最短路径长度和最短路径
                ans = node.cost;
                node.path.push_back(0);
                for (int i = 0; i < n; i++) {
                    cout << node.path[i] + 1 << " ";
                }
                cout << "\n" << ans << endl;
            }
            continue;
        }
        for (int i = 1; i < n; i++) {  // 枚举所有未访问的城市
            if (find(node.path.begin(), node.path.end(), i) == node.path.end()) {
                pq.push({i, node.cost + graph[node.cur][i], get_lb({i, node.cost + graph[node.cur][i], 0, node.path}), node.path});
            }
        }
    }
}

int main() {
    while (cin >> n >> m && n != 0) {
        graph.assign(n, vector<int>(n, INF));  // 初始化邻接矩阵
        for (int i = 0; i < m; i++) {  // 读入边的信息
            int u, v, w;
            cin >> u >> v >> w;
            graph[u - 1][v - 1] = graph[v - 1][u - 1] = w;  // 无向图，需要将(u,v)和(v,u)都设置为w
        }
        ans = INF;
        branch_and_bound();
    }
    return 0;
}