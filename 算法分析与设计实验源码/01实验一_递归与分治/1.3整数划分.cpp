#include <iostream>

using namespace std;

int split(int n , int m)
{
    if (n == 1 || m == 1) return 1; //递归出口

    else if (n < m) return split(n , n); //递归调用

    else if (n == m) return split(n , n-1) + 1; 
    
    else return split(n , m-1) + split(n-m , m); 
}

int main()
{
    int n;
    cin >> n;
    cout << split(n , n) << endl;

    return 0;
}
