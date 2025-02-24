#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n;
double dp[2][10005];
bool choice[10005][10005];
int ans[10005];
int length;
class MBigNumber
{
public:
    char value[100];
    int length=0;
    MBigNumber()
    {
        memset(value, '0', sizeof(value));
    }
    MBigNumber(long long x)
    {
        
        memset(value, '0', sizeof(value));
        while (x)
        {
            
            value[length++] = x % 10 + '0';
            x /= 10;
        }
        
    }
    MBigNumber operator+(const MBigNumber &b)
    {
        MBigNumber res;
        int carry = 0;
        for (int i = 0; i < length || i < b.length || carry; i++)
        {
            int sum = carry;
            if (i < length)
                sum += value[i] - '0';
            if (i < b.length)
                sum += b.value[i] - '0';
            carry = sum / 10;
            res.value[i] = sum % 10 + '0';
            res.length = i + 1;
        }
        return res;
    }
    MBigNumber operator*(const MBigNumber &b)
    {
        
        MBigNumber res;
        for (int i = 0; i < length; i++)
        {
            MBigNumber temp;
            int carry = 0;
            for (int j = 0; j < b.length; j++)
            {
                int sum = (value[i] - '0') * (b.value[j] - '0') + carry;
                carry = sum / 10;
                temp.value[j + i] = sum % 10 + '0';
                temp.length = j + i + 1;
            }
            if (carry)
            {
                while (carry)
                {
                    temp.value[temp.length++] = carry % 10 + '0';
                    carry /= 10;
                }
            }
            
            res = res + temp;
        }
        return res;
    }
    string toString()
    {
        return toString(*this);
    }
    static string toString(const MBigNumber &b)
    {
        string res;
        for (int i = b.length - 1; i >= 0; i--)
            res += b.value[i];
        return res;
    }
} total=1;
int main()
{
    scanf("%d", &n);
    int now = 0, last = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double noChoice = dp[last][j], hasChoice = 0;

            if (j >= i)
            {
                hasChoice =  dp[last][j - i] + log2(i);
            }
            if (hasChoice > noChoice)
            {
                dp[now][j] = hasChoice;
                choice[i][j] = true;
            }
            else
            {
                dp[now][j] = noChoice;
                choice[i][j] = false;
            }
        }
        swap(now, last);
    }
    int nowj=n;
    for (int i=n;i>0;i--){
        if (choice[i][nowj]){
            ans[length++]=i;
            total= total * i;
            nowj-=i;
        }
    }
    for (int i=length-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    printf("\n%s\n",total.toString().c_str());
}