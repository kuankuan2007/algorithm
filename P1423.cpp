#include <cstdio>
using namespace std;
int main(){
    double s,now=2,sum=0;
    int count=0;
    scanf("%lf",&s);
    while (sum<s)
    {
        count++;
        sum+=now;
        now*=0.98;
    }
    printf("%d",count);
}