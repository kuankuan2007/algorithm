#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

char s[1005];
int dp[2][1005];
int n;
int ans;

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    int now = 0, last = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s[n - j])
            {
                dp[now][j] = dp[last][j - 1] + 1;
            }
            else
            {
                dp[now][j] = max(dp[last][j], dp[now][j - 1]);
            }
        }
        swap(now, last);
        memset(dp[now], 0, sizeof(dp[now]));
    }
    printf("%d\n", n - dp[last][n]);
    return 0;
}