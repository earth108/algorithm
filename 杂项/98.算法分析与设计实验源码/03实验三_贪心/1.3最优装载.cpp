#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct load {  // 定义货物结构体
    int index;  // 货物编号
    int w;  // 货物重量
}box[1001];  // 定义货物数组

bool cmp(load a, load b) {  // 按照货物重量从大到小排序的比较函数
    return a.w > b.w;
}

int x[1001];  // 记录每个货物是否被选择

int main() {
    int c, n;
    while(scanf("%d %d", &c, &n) != EOF) {  // 循环读入测试数据
    
        memset(box, 0, sizeof(box));  // 初始化货物数组
        memset(x, 0, sizeof(x));  // 初始化选择数组

        for(int i = 1; i <= n; i++) {  // 读入每个货物的重量和编号
            scanf("%d", &box[i].w);
            box[i].index = i;
        }
        stable_sort(box+1, box+n+1, cmp);  // 按照货物重量从大到小排序

        if(box[1].w > c) {  // 如果最重的货物重量都大于背包容量，无解
            printf("No answer!\n");
            continue;
        }

        int i;

        for(i = 1; i <= n && box[i].w <= c; i++) {  // 从重量最大的货物开始，选择可以放入背包的货物
            x[box[i].index] = 1;  // 标记被选择的货物
            c -= box[i].w;  // 更新背包剩余容量
        }

        printf("%d\n", i-1);  // 输出被选择的货物数量

        for(i = 1; i <= n; i++) {  // 输出被选择的货物编号
            if(x[i]) printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}