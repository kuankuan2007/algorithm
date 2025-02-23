#include <cstdio>
using namespace std;
bool flags[100005];
int main(){
    int l,now=0,count=0;
    scanf("%d",&l);
    for (int i=2;i<l;i++){
        if (!flags[i]){
            for (int j=2;j*i<l;j++){
                flags[i*j]=true;
            }
            if (now+i>l){
                break;
            }
            count++;
            now+=i;
            printf("%d\n",i);
        }
    }
    printf("%d\n",count);
}