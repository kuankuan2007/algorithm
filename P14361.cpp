#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, ans, maxn;
struct A
{
    int a, b, c;

    A() {}
    A(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
A a[100005];
vector<int> best_a, best_b, best_c;
void refresh()
{
    ans = 0;
    best_a.clear();
    best_b.clear();
    best_c.clear();
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        refresh();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        maxn = n / 2;
        for (int i = 1; i <= n; i++)
        {
            int m = max(a[i].a, max(a[i].b, a[i].c));
            ans += m;
            if (m == a[i].a)
            {
                best_a.push_back(m - max(a[i].b, a[i].c));
            }
            else if (m == a[i].b)
            {
                best_b.push_back(m - max(a[i].a, a[i].c));
            }
            else if (m == a[i].c)
            {
                best_c.push_back(m - max(a[i].a, a[i].b));
            }
        }
        vector<int> *overmuch = nullptr;
        if (best_a.size() > maxn)
        {
            overmuch = &best_a;
        }
        else if (best_b.size() > maxn)
        {
            overmuch = &best_b;
        }
        else if (best_c.size() > maxn)
        {
            overmuch = &best_c;
        }
        if (overmuch != nullptr)
        {
            sort(overmuch->begin(), overmuch->end());
            for (int i = 0; i < overmuch->size() - maxn; i++)
            {
                ans -= (*overmuch)[i];
            }
        }
        printf("%d\n", ans);
    }
}