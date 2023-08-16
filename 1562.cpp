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
        for (int final_digit = 0; final_digit < NUM; final_digit++)
        {
            for (int bitmask = 0; bitmask < (1 << NUM); bitmask++)
            {
                if (dp[curr_len][final_digit][bitmask])
                {
                    if (final_digit - 1 >= 0)
                    {
                        dp[curr_len + 1][final_digit - 1][bitmask | (1 << (final_digit - 1))] = (dp[curr_len + 1][final_digit - 1][bitmask | (1 << (final_digit - 1))] + dp[curr_len][final_digit][bitmask]) % MOD;
                    }

                    if (final_digit + 1 < NUM)
                    {
                        dp[curr_len + 1][final_digit + 1][bitmask | (1 << (final_digit + 1))] = (dp[curr_len + 1][final_digit + 1][bitmask | (1 << (final_digit + 1))] + dp[curr_len][final_digit][bitmask]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int final_digit = 0; final_digit < NUM; final_digit++)
    {
        ans = (ans + dp[length][final_digit][(1 << NUM) - 1]) % MOD;
    }

    cout << ans;
    return 0;
}