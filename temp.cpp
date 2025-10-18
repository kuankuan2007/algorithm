#include <cstdio>
#include <unordered_set>
using namespace std;

int n, x, y;
int ax[1005], ay[1005], lenx, leny;

bool canReach(int *a, int length, int target, int start)
{
    unordered_set<int> s;
    s.insert(start);
    for (int i = 0; i < length; i++)
    {
        std::unordered_set<int> sn;
        for (int j : s)
        {
            sn.insert(j + a[i]);
            sn.insert(j - a[i]);
        }
        if (sn.find(target) != sn.end())
            return true;
        s.swap(sn);
    }
    return s.find(target) != s.end();
}
int main()
{
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            scanf("%d", &ax[lenx++]);
        else
            scanf("%d", &ay[leny++]);
    }
    bool res = canReach(ax + 1, lenx - 1, x, ax[0]) && canReach(ay, leny, y, 0);
    printf("%s\n", res ? "YES" : "NO");
}