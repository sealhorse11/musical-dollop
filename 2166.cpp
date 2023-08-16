#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

struct xy
{
    long long int x;
    long long int y;
};

xy pos[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += pos[i].x * pos[(i + 1) % n].y;
        ans -= pos[(i + 1) % n].x * pos[i].y;
    }

    ans /= 2;
    ans = abs(ans);
    cout << fixed;
    cout.precision(1);
    cout << ans;

    return 0;
}