#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define INF 1000000000

int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start = 0, end = 1, sum = arr[0];
    int ans = INF;

    while(start < n)
    {
        if(sum >= s)
        {
            if(end - start < ans)
            {
                ans = end - start;
            }
            sum -= arr[start++];
        }
        else
        {
            if(end == n)
                break;
            sum += arr[end++];
        }
    }

    if(ans == INF)
        cout << 0;
    else
        cout << ans;

    return 0;
}   