#include <bits/stdc++.h>
#define MAX_N 2000

using namespace std;

int arr[MAX_N];

bool ans[MAX_N][MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans[i][i] = true;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; i - j >= 0 && i + j < n; j++)
        {
            if (arr[i - j] == arr[i + j])
                ans[i - j][i + j] = true;
            else
                break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; i - 1 - j >= 0 && i + j < n; j++)
        {
            if (arr[i - 1 - j] == arr[i + j])
                ans[i - 1 - j][i + j] = true;
            else
                break;
        }
    }

    int query, s, e;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        cin >> s >> e;
        cout << int(ans[s - 1][e - 1]) << '\n';
    }

    return 0;
}