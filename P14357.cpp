#include <iostream>
#include <string>
using namespace std;

string s;
int l[10];
int ans;
int main()
{
    cin >> s;
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            l[c - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        while (l[i]--)
        {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}