#include <iostream>
using namespace std;

#define NUM 100
int tri[NUM][NUM];

int triangle(int n)
{
    int i , j;
    for(i = n - 2; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            if(tri[i+1][j] > tri[i+1][j+1])
            {
                tri[i][j] += tri[i+1][j];
            }
            else
            {
                tri[i][j] += tri[i+1][j+1];
            }
        }
    }
    return tri[0][0];
}

int main()
{
    int n = 5;
    tri[0][0] = 7;
    tri[1][0] = 3;
    tri[1][1] = 8;
    tri[2][0] = 8;
    tri[2][1] = 1;
    tri[2][2] = 0;
    tri[3][0] = 2;
    tri[3][1] = 7;
    tri[3][2] = 4;
    tri[3][3] = 4;
    tri[4][0] = 4;
    tri[4][1] = 5;
    tri[4][2] = 2;
    tri[4][3] = 6;
    tri[4][4] = 5;

    int max_sum = triangle(n);
    cout << "路径最大和为 " << max_sum << endl;

    return 0;
}