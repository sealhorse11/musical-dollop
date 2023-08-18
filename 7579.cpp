#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_COST 100
#define MAX_M 10000000

using namespace std;

int dp[MAX_N][MAX_N * MAX_COST + 1], memory[MAX_N], cost[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> memory[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int curr_cost = 0; cost[0] + curr_cost <= MAX_COST * n; curr_cost++)
        dp[0][cost[0] + curr_cost] = memory[0];

    for (int i = 1; i < n; i++)
    {
        for (int curr_cost = 0; curr_cost <= MAX_COST * n; curr_cost++)
        {
            dp[i][curr_cost] = dp[i - 1][curr_cost];

            if (curr_cost - cost[i] >= 0 && dp[i - 1][curr_cost - cost[i]] + memory[i] > dp[i][curr_cost])
                dp[i][curr_cost] = dp[i - 1][curr_cost - cost[i]] + memory[i];

            if (curr_cost > 0 && dp[i][curr_cost - 1] > dp[i][curr_cost])
                dp[i][curr_cost] = dp[i][curr_cost - 1];
        }
    }

    for (int curr_cost = 0; curr_cost <= MAX_COST * n; curr_cost++)
    {
        if (dp[n - 1][curr_cost] >= m)
        {
            cout << curr_cost;
            return 0;
        }
    }
}