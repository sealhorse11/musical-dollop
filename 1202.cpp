#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

struct jewel
{
    long long int weight;
    long long int value;

    jewel(){};
    jewel(long long int a, long long int b) : weight(a), value(b){};

    bool operator<(jewel other)
    {
        if (this->value == other.value)
        {
            return this->weight < other.value;
        }
        return this->value > other.value;
    }
};

jewel store[MAXN];
long long int capacity[MAXN];
map<long long int, long long int> cap_info;
set<long long int> cap_values;

int main()
{
    long long int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> store[i].weight >> store[i].value;

    for (int i = 0; i < k; i++)
        cin >> capacity[i];

    sort(store, store + n);

    sort(capacity, capacity + k);

    long long int curr_cap = capacity[0], num = 1;

    cap_values.insert(capacity[0]);
    for (int i = 1; i < k; i++)
    {
        if (capacity[i] == curr_cap)
        {
            num++;
        }
        else
        {
            cap_info[curr_cap] = num;
            num = 1;
            curr_cap = capacity[i];
            cap_values.insert(capacity[i]);
        }

        if (i == k - 1)
        {
            cap_info[curr_cap] = num;
            cap_values.insert(capacity[k - 1]);
        }
    }

    long long int ans = 0;

    for (int i = 0; i < n; i++)
    {
        auto fit_bag = cap_values.lower_bound(store[i].weight);
        if (fit_bag != cap_values.end() && cap_info[(*fit_bag)] > 0)
        {
            cap_info[(*fit_bag)]--;
            if (cap_info[(*fit_bag)] == 0)
            {
                cap_values.erase((*fit_bag));
            }

            ans += store[i].value;
        }
    }

    cout << ans;
    return 0;
}