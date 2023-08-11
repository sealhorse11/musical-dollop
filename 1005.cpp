#include <bits/stdc++.h>

using namespace std;

struct Task
{
    int num;
    int expected_time;

    Task(int a, int b) : num(a), expected_time(b){};

    bool operator<(const Task t) const
    {
        return this->expected_time > t.expected_time;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case, n, k;
    cin >> test_case;

    for (int test_num = 0; test_num < test_case; test_num++)
    {
        cin >> n >> k; // number of building and rule

        int *delay = new int[n]{
            0,
        };

        int *required = new int[n]{
            0,
        };

        bool *visited = new bool[n]{
            false,
        };
        for (int i = 0; i < n; i++)
            cin >> delay[i];

        bool **graph = new bool *[n];
        for (int i = 0; i < n; i++)
        {
            graph[i] = new bool[n]{
                0,
            };
        }

        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;

            graph[a - 1][b - 1] = true;
        }

        int target;
        cin >> target;
        target--;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[j][i])
                    required[i]++;
            }
        }

        int curr_time = 0;
        priority_queue<Task> pq;

        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && required[i] == 0)
                {
                    visited[i] = true;
                    pq.push(Task(i, curr_time + delay[i]));
                }
            }

            Task next_task = pq.top();
            pq.pop();

            int idx = next_task.num;
            curr_time = next_task.expected_time;

            if (idx == target)
            {
                break;
            }

            for (int i = 0; i < n; i++)
            {
                if (graph[idx][i])
                {
                    required[i]--;
                }
            }
        }

        cout << curr_time << '\n';

        // should be deallocated
        delete[] delay;
        delete[] required;
        delete[] visited;
        for (int i = 0; i < n; i++)
            delete[] graph[i];
        delete[] graph;
    }

    return 0;
}