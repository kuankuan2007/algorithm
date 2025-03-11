#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int dp[2][20005];
int a[100];
int n, v;

int main()
{
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int now = 0, last = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            int noChoice = dp[last][j], hasChoice = 0;
            if (j >= a[i])
            {
                hasChoice = dp[last][j - a[i]] + a[i];
            }
            dp[now][j] = max(noChoice, hasChoice);
        }
        swap(now, last);
    }
    printf("%d\n", v-dp[last][v]);
    return 0;
}