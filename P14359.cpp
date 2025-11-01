#include <cstdio>
#include <unordered_map>
using namespace std;
int a[500005];
int b[500005];
int n, k, t, p, ans;
unordered_map<int, int> mp;
void init_map()
{
    mp.clear();
    mp[0] = 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        t = t ^ a[i];
        b[i] = t;
    }
    init_map();

    for (int i = 0; i < n; i++)
    {
        p = p ^ a[i];
        int target = p ^ k;
        if (mp.find(target) != mp.end())
        {
            ans++;
            init_map();
            p = 0;
        }
        else
        {
            mp[p] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}