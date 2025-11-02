#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k, u, v, w;

struct Node
{
    int id;
    bool is_village;
    int edge_id()
    {
        if (is_village)
        {
            return id + 10005;
        }
        return id;
    }
};

struct Edge
{
    Node u, v;
    int w;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

Edge edges[1000005];
int parent[10035];
Edge edges2[200005];
int village[13][10005], village_w[13];
long long ans = 9223372036854775807;
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if (px == py)
        return false;
    parent[px] = py;
    return true;
}

int main()
{
    // 这么大的复杂度是怎么tm能ac的
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        edges[i] = {{u - 1, false}, {v - 1, false}, w};
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    sort(edges, edges + m);

    long long mst_weight = 0;
    int edge2_count = 0;

    for (int i = 0; i < m && edge2_count < n - 1; i++)
    {
        if (unite(edges[i].u.edge_id(), edges[i].v.edge_id()))
        {
            mst_weight += edges[i].w;
            edges2[edge2_count++] = edges[i];
        }
    }
    // printf("mst_weight:%d , edge2_count: %d\n", mst_weight, edge2_count);

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &village_w[i]);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w);
            edges2[edge2_count++] = {{i, true}, {j, false}, w};
        }
    }
    sort(edges2, edges2 + edge2_count);
    for (int villages = 0; villages <= ((1 << k) - 1); villages++)
    {
        long long now_ans = 0;
        int enabled_villages = 0, edge3_count = 0;
        for (int i = 0; i < k; i++)
        {
            if ((villages >> i) & 1)
            {
                enabled_villages += 1;
                now_ans += village_w[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < k; i++)
        {
            parent[10005 + i] = 10005 + i;
        }
        // printf("villages: %d\n", villages);
        for (int j = 0; j < edge2_count && edge3_count < n + enabled_villages - 1; j++)
        {
            if (edges2[j].u.is_village && !((villages >> edges2[j].u.id) & 1))
            {
                // printf("  edge(skip): %d-%d %d\n", edges2[j].u.edge_id(), edges2[j].v.edge_id(), edges2[j].w);
                continue;
            }
            // printf("-parent:%d-%d \\ %d-%d\n", edges2[j].u.edge_id(), find(edges2[j].u.edge_id()), edges2[j].v.edge_id(), find(edges2[j].v.edge_id()));
            if (unite(edges2[j].u.edge_id(), edges2[j].v.edge_id()))
            {
                // printf("edge: %d-%d %d\n", edges2[j].u.edge_id(), edges2[j].v.edge_id(), edges2[j].w);
                now_ans += edges2[j].w;
                edge3_count++;
            }
            else
            {
                // printf("  edge(repeat): %d-%d %d  ", edges2[j].u.edge_id(), edges2[j].v.edge_id(), edges2[j].w);
            }
        }
        // printf("now_ans: %lld, edge3_count: %d\n", now_ans, edge3_count);
        ans = min(ans, now_ans);
    }
    printf("%lld", ans);
    return 0;
}