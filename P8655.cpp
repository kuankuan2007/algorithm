#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n;
struct Node
{
    int a, b, next;
};
Node a[100005];
int head[100005];
int vis[100005];
bool vis2[100005];
int ans[100005], ansTop = 0;
stack<int> mark;
int repeatLast;
int dfs(int now, int last)
{
    // printf("d:%d\n", now);
    if (vis[now])
    {
        repeatLast = last;
        return now;
    }
    vis[now] = last;

    Node *p = &a[head[now]];
    while (true)
    {
        // printf("p:%d %d now:%d last:%d\n", p->a, p->b, now, last);

        if (p->b != last)
        {

            int res = dfs(p->b, now);
            if (res)
                return res;
        }
        if (p->next == -1)
        {
            break;
        }
        p = &a[p->next];
    }
    return 0;
}
void lookBackMark(int now)
{
    while (now != -1 && now != 0)
    {
        // printf("m:%d\n", now);

        vis2[now] = true;
        mark.push(now);
        now = vis[now];
    }
}
void lookBackFind(int now)
{
    while (now != -1)
    {
        // printf("f:%d\n", now);
        if (vis2[now])
        {
            while (!mark.empty() && mark.top() != now)
            {
                mark.pop();
            }
            while (!mark.empty())
            {
                ans[ansTop++] = mark.top();
                mark.pop();
            }
            return;
        }
        ans[ansTop++] = now;
        now = vis[now];
    }
    return;
}
int main()
{
    scanf("%d", &n);
    int now = 0;
    for (int i = 0; i <= n; i++)
    {
        head[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[now].a = x;
        a[now].b = y;
        a[now].next = head[x];
        head[x] = now;
        now++;
        a[now].a = y;
        a[now].b = x;
        a[now].next = head[y];
        head[y] = now;
        now++;
    }
    int res = dfs(1, -1);
    // printf("r:%d %d %d\n", res, vis[res], repeatLast);
    for (int i = 1; i <= n; i++)
    {
        // printf("v:%d %d\n", i, vis[i]);
    }
    lookBackMark(repeatLast);

    lookBackFind(res);

    sort(ans, ans + ansTop);

    for (int i = 0; i < ansTop; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}