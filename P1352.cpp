#include<iostream>
#include<cstring>
using namespace std;
int num,p[12001],maxn=-1;
int ans[12001][2];
struct edge{
    int v,next;
}E[12001];
void init(){
    num=0;
    memset(p,-1,sizeof(p));
}
void insert(int u,int v){
    E[num].v=v;
    E[num].next=p[u];
    p[u]=num++;
}
void dp(int u,int fa){
    for(int i=p[u];i!=-1;i=E[i].next){
        int v=E[i].v;
        if(v!=fa){
            dp(v,u);
            ans[u][1]+=ans[v][0];
            ans[u][0]+=max(ans[v][0],ans[v][1]);
            maxn=max(ans[u][1],ans[u][0]);
        }
    }
}
int main(){
    int n,u,v;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>ans[i][1];
    }
    init();
    for(int i=0;i<n-1;i++){
        cin>> u >>v;
        insert(u,v);
        insert(v,u);
    }
    dp(1,-1);
    cout<<maxn;
}