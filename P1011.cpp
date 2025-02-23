#include <cstdio>

using namespace std;

int fibo[30];
int fib(int n)
{
    if (fibo[n])
        return fibo[n];
    if (n <= 2)
    {
        return fibo[n] = 1;
    }
    return fibo[n] = fib(n - 1) + fib(n - 2);
}

struct StationRest
{
    int a, b;
    StationRest(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    StationRest()
    {
        a = 0;
        b = 0;
    }
};

StationRest station(int n)
{
    if (n == 1 || n == 2)
        return StationRest(1, 0);

    return StationRest(fib(n - 2), fib(n - 1));
}

int a, n, m, x, b;

int main()
{
    scanf("%d%d%d%d", &a, &n, &m, &x);
    if (x == 1 || x == 2)
    {
        printf("%d\n", a);
        return 0;
    }
    auto end = station(n - 1);
    b = (m - (end.a + 1) * a) / (end.b - 1);
    auto res = station(x);
    printf("%d\n", a * res.a + b * res.b + a - b);
    return 0;
}