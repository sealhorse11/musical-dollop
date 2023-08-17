#include <bits/stdc++.h>
#define MAXN 32000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> connected_point[MAXN];
    int condition[MAXN] = {
        0,
    };

    bool visited[MAXN] = {
        false,
    };

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        connected_point[start - 1].push_back(end - 1);
        condition[end - 1]++;
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (condition[i] == 0)
        {
            visited[i] = true;
            q.push(i);
        }
    }

    while (true)
    {
        if (q.empty())
            break;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int curr_idx = q.front();
            q.pop();

            ans.push_back(curr_idx + 1);

            for (int next : connected_point[curr_idx])
            {
                condition[next]--;
                if (condition[next] == 0 && !visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }

    for (int idx : ans)
    {
        cout << idx << ' ';
    }
    return 0;
}