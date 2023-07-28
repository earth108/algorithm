#include <iostream>

using namespace std;
//二分搜索
const int N = 100010;

int BinarySearch(int a[] , int n , int x)
{
    int left  = 0; //左边界
    int right = n - 1; //右边界
    while(left <= right)  
    {
        int mid = (left + right) / 2; //中间值
        if (a[mid] == x) return mid; //找到了
        else //没找到
        if (x > a[mid]) left = mid + 1; //x在右边
        else right = mid - 1; //x在左边
    }
}


int main()
{
    int n , x;//n个数，查找x
    int a[N];
    cout << "请输入n：" << endl;
    cin >> n;

    cout << "请输入n个数：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "请输入要查找的数：" << endl;
    cin >> x;

    cout << BinarySearch(a , n , x);

    return 0;
}

