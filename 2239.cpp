#include <bits/stdc++.h>

using namespace std;

struct pos
{
    int x;
    int y;
    pos(){};
    pos(int a, int b) : x(a), y(b){};
};

void solve(int **board, bool **row_check, bool **col_check, bool **box_check,
           deque<pos> &pos_stack, bool &is_solved)
{
    if (pos_stack.empty() || is_solved)
    {
        is_solved = true;
        return;
    }

    auto pos = pos_stack.front();
    pos_stack.pop_front();

    int box_idx;

    for (int curr_ans = 1; curr_ans <= 9; curr_ans++)
    {
        box_idx = (pos.x / 3) * 3 + pos.y / 3;

        if (row_check[pos.y][curr_ans - 1] || col_check[pos.x][curr_ans - 1] || box_check[box_idx][curr_ans - 1])
            continue;

        board[pos.x][pos.y] = curr_ans;
        row_check[pos.y][curr_ans - 1] = true;
        col_check[pos.x][curr_ans - 1] = true;
        box_check[box_idx][curr_ans - 1] = true;
        solve(board, row_check, col_check, box_check, pos_stack, is_solved);

        if (is_solved)
            return;
        board[pos.x][pos.y] = 0;
        row_check[pos.y][curr_ans - 1] = false;
        col_check[pos.x][curr_ans - 1] = false;
        box_check[box_idx][curr_ans - 1] = false;
    }

    pos_stack.push_front(pos);

    return;
}

int main()
{
    int **board = new int *[9];
    for (int i = 0; i < 9; i++)
        board[i] = new int[9];

    bool **row_check = new bool *[9];
    for (int i = 0; i < 9; i++)
        row_check[i] = new bool[9]{
            false,
        };

    bool **col_check = new bool *[9];
    for (int i = 0; i < 9; i++)
        col_check[i] = new bool[9]{
            false,
        };

    bool **box_check = new bool *[9];
    for (int i = 0; i < 9; i++)
        box_check[i] = new bool[9]{
            false,
        };

    deque<pos> dq;
    bool solved = false;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d", &board[i][j]);
            if (board[i][j] == 0)
                dq.push_back(pos(i, j));

            row_check[j][board[i][j] - 1] = true;
            col_check[i][board[i][j] - 1] = true;
            box_check[(i / 3) * 3 + j / 3][board[i][j] - 1] = true;
        }
    }

    solve(board, row_check, col_check, box_check, dq, solved);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << '\n';
    }

    for (int i = 0; i < 9; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}