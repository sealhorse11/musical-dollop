#include <bits/stdc++.h>
#define MOD 1000000000
#define NUM 10
#define MAX_LENGTH 100

using namespace std;

int dp[MAX_LENGTH + 1][NUM][1 << NUM];

int main()
{
    int length;
    cin >> length;

    // not to start with 0
    for (int i = 1; i < NUM; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    // main solving part
    for (int curr_len = 1; curr_len < length; curr_len++)
    {
        for (int final_num = 0; final_num < NUM; final_num++)
        {
            for (int bitmask = 0; bitmask < (1 << NUM); bitmask++)
            {
                if (dp[curr_len][final_num][bitmask])
                {
                    if (final_num - 1 >= 0)
                    {
                        dp[curr_len + 1][final_num - 1][bitmask | (1 << (final_num - 1))] = (dp[curr_len + 1][final_num - 1][bitmask | (1 << (final_num - 1))] + dp[curr_len][final_num][bitmask]) % MOD;
                    }

                    if (final_num + 1 < NUM)
                    {
                        dp[curr_len + 1][final_num + 1][bitmask | (1 << (final_num + 1))] = (dp[curr_len + 1][final_num + 1][bitmask | (1 << (final_num + 1))] + dp[curr_len][final_num][bitmask]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int final_num = 0; final_num < NUM; final_num++)
    {
        ans = (ans + dp[length][final_num][(1 << NUM) - 1]) % MOD;
    }

    cout << ans;
    return 0;
}