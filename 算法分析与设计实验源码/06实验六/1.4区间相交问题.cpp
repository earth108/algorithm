#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > intervals(n); // 存储n个闭区间
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = make_pair(l, r);
    }
    sort(intervals.begin(), intervals.end());  // 将闭区间按照左端点从小到大排序
    int cnt = 0, cur = intervals[0].second;  // cnt表示去掉的闭区间数，cur表示当前不相交区间的右端点
    for (int i = 1; i < n; i++) {  // 依次遍历每个闭区间
        if (intervals[i].first >= cur) {  // 如果当前闭区间和前面的区间不相交
            cur = intervals[i].second;  // 更新cur的值
        } else {  // 否则，需要去掉当前闭区间
            cnt++;  // 去掉当前闭区间
            cur = min(cur, intervals[i].second);  // 更新cur的值
        }
    }
    cout << cnt << endl;  // 输出去掉的闭区间数
    return 0;
}