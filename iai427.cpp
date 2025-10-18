#include <cstdio>
using namespace std;
long long dp[1005][10005];
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - (j < i ? 0 : dp[i - 1][j - i]) + 1000000007) % 1000000007;
        }
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}