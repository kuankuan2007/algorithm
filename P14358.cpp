#include <cstdio>
using namespace std;
int m, n, ind, r, x, ans_c, ans_r;

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d", &r);
    for (int i = 0; i < n * m - 1; i++)
    {
        scanf("%d", &x);
        if (x > r)
        {
            ind++;
        }
    }
    ans_c = ind / n + 1;
    ans_r = ans_c % 2 ? ind % n + 1 : n - ind % n;
    printf("%d %d\n", ans_c, ans_r);
    return 0;
}