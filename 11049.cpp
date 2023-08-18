#include <bits/stdc++.h>
#define MAX_N 500

using namespace std;

struct matrix
{
    int r;
    int c;

    matrix()
    {
        r = c = 0;
    }

    int operator*(matrix &other)
    {
        return r * c * other.c;
    }
};

matrix matrix_arr[MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> matrix_arr[i].r >> matrix_arr[i].c;
    }

    for (int range = 1; range < n; range++)
    {
        matrix result_cal;
        for (int start = 0; start + range < n; start++)
        {
            int curr_cal = INT_MAX;
            for (int split = start; split < start + range; split++)
            {
                int count_cal = matrix_arr[start].r * matrix_arr[split].c * matrix_arr[start + range].c;

                if (curr_cal > dp[start][split] + dp[split + 1][start + range] + count_cal)
                {
                    curr_cal = dp[start][split] + dp[split + 1][start + range] + count_cal;
                }
            }
            dp[start][start + range] = curr_cal;
        }
    }

    cout << dp[0][n - 1];
    return 0;
}