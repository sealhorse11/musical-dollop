#include <bits/stdc++.h>
#define MAX_VERTEX 10000

using namespace std;

struct edge
{
    int s;
    int e;
    int w;
    edge(int a, int b, int c) : s(a), e(b), w(c){};
    bool operator<(const edge other) const
    {
        return this->w < other.w;
    }
};

vector<edge> edges;

int main()
{
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(edge(a - 1, b - 1, c));
    }

    sort(edges.begin(), edges.end());

    int *union_set = new int[v];
    for (int i = 0; i < v; i++)
    {
        union_set[i] = i;
    }

    int mst_weight = 0, mst_edges = 0;

    int start, end, weight, start_root, end_root;
    for (int i = 0; i < e && mst_edges < v - 1; i++)
    {
        start = edges[i].s;
        end = edges[i].e;
        weight = edges[i].w;

        start_root = start, end_root = end;
        while (union_set[start_root] != start_root)
        {
            start_root = union_set[start_root];
        }
        while (union_set[end_root] != end_root)
        {
            end_root = union_set[end_root];
        }

        if (union_set[start_root] == union_set[end_root])
            continue;

        union_set[end_root] = start_root;

        mst_weight += weight;
        mst_edges++;
    }

    cout << mst_weight;
    return 0;
}