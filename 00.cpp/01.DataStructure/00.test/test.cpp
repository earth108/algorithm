#include <iostream>

using namespace std;

int f(int n)
{
    if (n == 1 || n == 0) return 1;
    else return f( n - 1) + f(n - 2);
}


int main()
{
    int x = 5;
    cout << f(x);
    return 0;
}