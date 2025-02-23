#include <cstdio>
using namespace std;
int main(){
    int now=0,value=1,n,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        ans+=value;
        now++;
        if (value==now){
            value++;
            now=0;
        }
    }
    printf("%d\n", ans);
}