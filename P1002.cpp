#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point
{
    int x, y;
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
Point c, b;
int horseJump[9][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {0, 0}};
bool inBox(Point now)
{
    return now.x >= 0 && now.x <= b.x && now.y >= 0 && now.y <= b.y;
}

bool isHorse(Point now)
{
    for (int i = 0; i < 9; i++)
    {
        if (now.x == c.x + horseJump[i][0] && now.y == c.y + horseJump[i][1])
            return true;
    }
    return false;
}
bool canVisit(Point now)
{
    return inBox(now) && !isHorse(now);
}

long long dp[25][25];
long long getValue(Point now)
{
    if (inBox(now))
    {
        return dp[now.x][now.y];
    }
    return 0;
}
int main()
{
    scanf("%d%d", &b.y, &b.x);
    scanf("%d%d", &c.y, &c.x);
    dp[0][0] = 1;
    for (int y = 0; y <= b.y; y++)
    {
        for (int x = 0; x <= b.x; x++)
        {
            if (x == 0 && y == 0)
            {
                continue;
            }
            if (!canVisit(Point(x, y)))
            {
                dp[x][y] = 0;
            }
            else
            {
                dp[x][y] = getValue(Point(x - 1, y)) + getValue(Point(x, y - 1));
            }
        }
    }
    printf("%lld", dp[b.x][b.y]);
    return 0;
}