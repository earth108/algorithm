#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);  // 存储给定的单调递增正整数序列
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    while (m--) {  // 处理m个询问
        int x;
        cin >> x;
        int l = 0, r = n - 1, ans = -1;  // 初始化l、r和ans的值
        while (l <= r) {  // 二分查找
            int mid = l + (r - l) / 2;
            if (nums[mid] <= x) {  // 如果nums[mid]小于等于x，说明ans的值应该在[mid+1, r]之间
                ans = nums[mid];  // 更新ans的值
                l = mid + 1;  // 将l赋值为mid+1
            } else {  // 否则，说明ans的值应该在[l, mid-1]之间
                r = mid - 1;  // 将r赋值为mid-1
            }
        }
        cout << ans << endl;  // 输出最后一个小于等于x的元素的值
    }
    return 0;
}