#include <iostream>

using namespace std; 

int board[1025][1025];
static int tile = 1;

//棋盘覆盖算法
void ChessBoard(int tr , int tc , int dr , int dc  ,int size)
{

    if (size == 1) return;

    int t = tile++;
    int s = size / 2;
    //左上角子棋盘
    if (dr < tr + s && dc < tc + s) //特殊方格在左上角子棋盘中
    {
        ChessBoard(tr , tc , dr , dc , s);
    }
    else
    {
        board[tr + s - 1][tc + s - 1] = t; //标记L型骨牌覆盖的格子
        ChessBoard(tr , tc , tr + s - 1 , tc + s - 1 , s); //覆盖左上角子棋盘
    }
//右上角子棋盘
    if (dr < tr + s && dc >= tc + s)
    {
        ChessBoard(tr , tc + s , dr , dc , s); //特殊方格在右上角子棋盘中
    }
    else
    {
        board[tr + s - 1][tc + s] = t;  //标记L型骨牌覆盖的格子
        ChessBoard(tr , tc + s , tr + s - 1 , tc + s , s); //覆盖右上角子棋盘
    }
//左下角子棋盘
    if (dr >= tr + s && dc < tc + s)
    {
        ChessBoard(tr + s , tc , dr , dc , s); //特殊方格在左下角子棋盘中
    }
    else
    {
        board[tr + s][tc + s - 1] = t; //标记L型骨牌覆盖的格子
        ChessBoard(tr + s , tc , tr + s , tc + s - 1 , s); //覆盖左下角子棋盘
    }
//右下角子棋盘
    if (dr >= tr + s && dc >= tc + s)
    {
        ChessBoard(tr + s , tc + s , dr , dc , s); //特殊方格在右下角子棋盘中
    }
    else
    {
        board[tr + s][tc + s] = t; //标记L型骨牌覆盖的格子  
        ChessBoard(tr + s , tc + s , tr + s , tc + s , s); //覆盖右下角子棋盘
    }

}

int main()
{
    int k = 0;
    int tr , tc , dr , dc , size;
    cout << "请输入棋盘的k值：";
    cin >> k;
    size = 1 << k;
    cout << "请输入特殊方格的位置：";
    cin >> dr >> dc;
    tr = 0;
    tc = 0;
    ChessBoard(tr , tc , dr , dc , size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;

}