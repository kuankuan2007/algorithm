#include <cstdio>
using namespace std;
struct Carpet{
    int x;
    int y;
    int w;
    int h;
    bool in(int xx, int yy){
        return x <= xx && xx <= x + w && y <= yy && yy <= y + h;
    }
} carpets[10005];

int main(){
    int n,x,y;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld %lld %lld %lld", &carpets[i].x, &carpets[i].y, &carpets[i].w, &carpets[i].h);
    }
    scanf("%lld %lld", &x, &y);
    for (int i = n - 1; i >= 0; i--){
        if (carpets[i].in(x, y)){
            printf("%lld\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}