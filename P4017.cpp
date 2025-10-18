#include <cstdio>
#include <queue>
using namespace std;

#define MOD 80112002
struct E
{
    int to;
    int nextFrom;
};
E map[500005];

struct Node
{
    int inDegree;
    int outDegree;
    int headFrom;
    int num;
};

Node nodes[5005];
queue<int> q;

int n, m, ans, from;

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &from, &map[i].to);
        map[i].nextFrom = nodes[from].headFrom;
        nodes[from].headFrom = i;
        nodes[map[i].to].inDegree++;
        nodes[from].outDegree++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!nodes[i].inDegree)
        {
            q.push(i);
            nodes[i].num = 1;
        }
    }
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (nodes[current].outDegree == 0)
        {
            ans = (ans + nodes[current].num) % MOD;
            continue;
        }
        for (int i = nodes[current].headFrom; i; i = map[i].nextFrom)
        {
            nodes[map[i].to].inDegree--;
            nodes[map[i].to].num = (nodes[map[i].to].num + nodes[current].num) % MOD;
            if (!nodes[map[i].to].inDegree)
            {
                q.push(map[i].to);
            }
        }
    }
    printf("%d\n", ans);
}