#include <iostream>
#define NUM 1001

using namespace std;

int a[NUM];
//选择问题
int select(int left , int right , int k)
{
    //避免递归溢出
    if (left >= right) return a[left];

    int i = left;
    int j = right + 1; 
    int pivot = a[left];
    while(true)  
    {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j) break; 
        swap(a[i] , a[j]); 
    }
    
    if(j - left + 1 == k) return pivot;
    a[left] = a[j];
    a[j] = pivot;
    if (j - left + 1 < k)
     return select(j + 1 , right , k - j + left - 1); 
    else
     return select(left , j - 1 , k);
}

int main()
{
    int n , k; //n个数，第k小
    cout << "请输入n" << endl;
    cin >> n;
    cout << "请输入第k小的数" << endl;
    cin >> k;
    cout << "请输入n个数：" << endl;
    for (int i = 0; i < n; i++) //输入
    {
        cin >> a[i];
    }
    cout << select(0 , n - 1 , k);
    return 0;
}