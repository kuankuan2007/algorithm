#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int a[1005];
long long b[1005];
int n, c;
int ans;
void dfs(int now, int sum)
{
    ans = max(ans, sum);
    for (int i = now; i >= 1; i--)
    {
        if (sum + a[i] > c)
            continue;
        if (sum + b[i] < ans)
            break;
        dfs(i - 1, sum + a[i]);
    }
    return;
}

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] + a[i];
    }
    dfs(n, 0);
    printf("%d\n", ans);
    return 0;
}