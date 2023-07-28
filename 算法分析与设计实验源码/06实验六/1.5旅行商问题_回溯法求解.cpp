#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, ans;
vector<vector<int>> graph;
vector<int> path, best_path;
vector<bool> visited;

void backtrack(int cur, int cost) {
    if (cost >= ans) {  // 剪枝：如果当前路径长度已经大于等于已知的最短路径长度，就不需要继续搜索了
        return;
    }
    if (cur == 0) {  // 如果已经遍历完所有城市
        if (cost < ans) {  // 更新最短路径长度和最短路径
            ans = cost;
            best_path = path;
        }
        return;
    }
    for (int i = 1; i < n; i++) {  // 枚举所有未访问的城市
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            backtrack(i, cost + graph[cur][i]);  // 递归搜索下一个城市
            path.pop_back();
            visited[i] = false;
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
        visited.assign(n, false);
        visited[0] = true;
        path.clear();
        path.push_back(0);
        backtrack(0, 0);  // 从第0个城市开始
        cout << 1;
        for (int i = 1; i < n; i++) {
            cout << " " << best_path[i];
        }
        cout << "\n" << ans << endl;
    }
    return 0;
}