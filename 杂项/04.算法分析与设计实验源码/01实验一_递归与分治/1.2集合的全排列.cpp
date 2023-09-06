#include <iostream>

using namespace std;

void Perm(int list[] , int k , int m)
{
    if(k == m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout<< list[i] << ' ';
        }
        cout << endl;
        
    }
    else
    {
        for (int j = k; j <= m; j++)
        {
            swap(list[k] , list[j]);
            Perm(list , k + 1 , m);
            swap(list[k] , list[j]);
        }
        
    }
}

int main()
{
    int list[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> list[i];
    }

    Perm(list, 1, n);

    return 0;

}