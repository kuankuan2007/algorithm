#include <cstdio>
#include <algorithm>
using namespace std;
int l, n, p[5005], minans;
int main()
{
    scanf("%d%d", &l, &n);
    if (l == 0 || n == 0)
    {
        printf("0 0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    sort(p, p + n);

    for (int i = 0; i < n; i++)
    {
        minans = max(minans, min(p[i], l - p[i] + 1));
    }
    printf("%d %d\n", minans, max(p[n - 1], l - p[0] + 1));
    return 0;
}