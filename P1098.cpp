#include <cstdio>
#include <string>

using namespace std;
int p1, p2, p3;
string getAddValue(int c, bool isNumber)
{
    if (p1 == 2 && !isNumber)
        c = c + 'A' - 'a';
    else if (p1 == 3)
        c = '*';

    string res = "";
    res.resize(p2, c);
    return res;
}
char src[105];
int main()
{
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", src);
    string s = src;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-' && i > 0 && i < s.length() - 1)
        {
            char last = s[i - 1], next = s[i + 1];
            if (last < next && (last >= 'a' && next <= 'z' || last >= '0' && next <= '9'))
            {
                bool isNumber = last >= '0' && next <= '9';
                if (p3 == 1)
                {
                    for (int j = last + 1; j < next; j++)
                    {
                        ans += getAddValue(j, isNumber);
                    }
                }
                else
                {
                    for (int j = next - 1; j > last; j--)
                    {
                        ans += getAddValue(j, isNumber);
                    }
                }

                continue;
            }
        }
        ans += s[i];
    }
    printf("%s\n", ans.c_str());
    return 0;
}