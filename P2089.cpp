#include <cstdio>
#include <algorithm>
using namespace std;
int state[10];
int total;
int res[100005][10];

void record()
{

    for (int i = 0; i < 10; i++)
    {
        res[total][9 - i] = state[i];
    }
    total++;
}
void find(int now, int rest)
{
    if (!now)
    {
        if (rest && rest <= 3)
        {
            state[now] = rest;
            record();
        }
        return;
    }
    for (int i = 1; i <= min(rest - now, 3); i++)
    {
        state[now] = i;
        find(now - 1, rest - i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    find(9, n);
    printf("%d\n", total);
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}