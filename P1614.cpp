#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[3005], ans = 0x7fffffff;
int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (m == 0)
    {
        printf("%d", 0);
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    for (int i = 0; i + m <= n; i++)
    {
        ans = min(ans, a[i + m] - a[i]);
    }
    printf("%d\n", ans);
    return 0;
}