#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> springs(n + 1);  // 存储每个弹簧的力量，springs[0]表示起点的弹簧力量，springs[n]表示终点的弹簧力量
    for (int i = 1; i <= n; i++) {
        cin >> springs[i];
    }
    vector<int> dp(n + 1, -1);  // dp[i]表示袋鼠跳到第i个弹簧时的最少跳数，初始化为-1
    dp[1] = 0;  // 起点的最少跳数为0
    for (int i = 2; i <= n; i++) {  // 从第2个弹簧开始，依次计算dp[i]的值
        for (int j = 1; j < i; j++) {  // 枚举前面所有的弹簧
            if (dp[j] != -1 && j + springs[j] >= i) {  // 如果第j个弹簧能够到达第i个弹簧
                if (dp[i] == -1 || dp[i] > dp[j] + 1) {  // 更新dp[i]的值
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    cout << dp[n] << endl;  // 输出袋鼠跳到终点的最少跳数
    return 0;
}