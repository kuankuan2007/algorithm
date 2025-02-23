#include <cstdio>
#include <algorithm>
using namespace std;
struct Coin
{
    int m;
    int v;
    bool operator<(const Coin &b) const
    {
        return (1.0 * this->v / this->m) < (1.0 * b.v / b.m);
    }
} a[105];
int n, t;
double ans;
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].m, &a[i].v);
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--)
    {

        if (a[i].m < t)
        {
            ans += a[i].v;
            t -= a[i].m;
        }
        else
        {
            ans += a[i].v * 1.0 * t / a[i].m;
            break;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}