/*
 - 第一个问，最小生成树。
 - 第二个问，求出最小生成树后建图。
 枚举每一条边，然后期望是边的期望和，边的期望就是两边节点数的乘，乘以花费。
   */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
using namespace std;
const int maxn = 1000005;
int n,m;
int fa[maxn];
double ans2;
vector<pair<int,int> >E[maxn];
int fi(int u){
    return u != fa[u] ? fa[u] = fi( fa[u] ) : u;
}
void uni(int x,int y){
    int p=fa[x],q=fa[y];
    if(p==q)return;
    fa[p]=q;
}
struct node{
    int x,y,z;
}p[maxn];
bool cmp(node a,node b){
    return a.z<b.z;
}
void init(){
    ans2=0;
    for(int i=0;i<maxn;i++)fa[i]=i;
    memset(p,0,sizeof(p));
    for(int i=0;i<maxn;i++)E[i].clear();
}
int dfs(int x,int f){
    int sz = 0;
    for(int i=0; i<(int)E[x].size(); i++){
        int v = E[x][i].first;
        if(v==f)continue;
        int tmp = dfs(v,x);
        sz+=tmp;
        ans2 = ans2 + 1.0 * tmp * (n-tmp) * E[x][i].second;
    }
    return sz+1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        }
        sort(p+1,p+1+m,cmp);
        long long ans = 0;
        for(int i=1;i<=m;i++){
            int p1=fi(p[i].x),q1=fi(p[i].y);
            if(p1==q1)continue;
            uni(p1,q1);
            ans+=p[i].z;
            E[p[i].x].push_back(make_pair(p[i].y,p[i].z));
            E[p[i].y].push_back(make_pair(p[i].x,p[i].z));
        }
        dfs(1,0);
        ans2 = ans2 * 1.0 * 2.0 * 1.0  / (1.0* n)  / (n - 1.0);
        printf("%I64d %.2lf\n",ans,ans2);
    }
}
