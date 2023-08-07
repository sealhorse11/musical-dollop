#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

int n, m, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct point{
    int x;
    int y;

    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}

    point& operator+=(point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    point operator+(point& other)
    {
        return point(this->x + other.x, this->y + other.y);
    }

    bool safe()
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int **board = new int *[n];
    int **dp = new int *[n];

    for (int i = 0; i < n; i++){
        board[i] = new int[m];
        dp[i] = new int[m];
        for (int j = 0; j < m; j++)
            dp[i][j] = INF;
    }

    point goal;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                goal.x = i;
                goal.y = j;
                dp[i][j] = 0;
            }
        }
    }

    queue<point> q;
    q.push(goal);

    point curr_pos, next_pos, dpos;
    while(!q.empty())
    {
        point curr_pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            dpos = point(dx[i], dy[i]);
            next_pos = curr_pos + dpos;
            if(next_pos.safe() && dp[next_pos.x][next_pos.y] > dp[curr_pos.x][curr_pos.y] + 1 && board[next_pos.x][next_pos.y] == 1){
                dp[next_pos.x][next_pos.y] = dp[curr_pos.x][curr_pos.y] + 1;
                q.push(next_pos);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(dp[i][j] >= INF){
                if(board[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -1;
            }
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < n; i++){
        delete[] dp[i];
        delete[] board[i];
    }
    delete[] dp;
    delete[] board;

    return 0;
}