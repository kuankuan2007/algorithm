#include <cstdio>
#include <algorithm>

using namespace std;
#define MOD 998244353
#define mod(a) ((a + MOD) % MOD)
int a[5005];
long long dp[5005][10005];
int p[5005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int max_value = a[n];
    // printf("%d\n", max_value);
    // printf("%d %d %d\n", a[35], a[36], a[37]);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 2 % MOD;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= max_value; j++)
        {
            if (j < a[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = mod(dp[i - 1][j] + dp[i - 1][j - a[i]]);
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= max_value; j++)
    //     {
    //         printf("%d\t", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    long long exclude = 0;
    for (int i = 1; i <= n; i++)
    {
        long long exclude_i = 0;
        for (int j = 0; j <= a[i]; j++)
        {
            exclude_i = mod(exclude_i + dp[i - 1][j]);
        }
        exclude_i = mod(exclude_i - i);
        // printf("%d ", exclude_i);
        exclude = mod(exclude + exclude_i);
    }
    // printf("\n");
    // long long T = mod(p[n] - 1 - n - n * (n - 1) / 2);
    // printf("T:%lld exclude:%lld p[n]:%d\n", T, exclude, p[n]);

    long long ans = mod(mod((long long)p[n] - 1 - n - n * (n - 1) / 2) - exclude);
    printf("%lld\n", ans);
    return 0;
}