#include <cstdio>
#include <algorithm>
int n;
int a[10];
using namespace std;
void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("% 5d", a[i]);
    }
    printf("\n");
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i - 1] = i;
    }
    do
    {
        print();
    } while (next_permutation(a, a + n));
    return 0;
}