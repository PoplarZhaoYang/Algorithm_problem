/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/12 14:49:04 2016
**Problem**:
**Analyse**:
**Get**:
**Code**:
***********************1599664856@qq.com**********************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e4 + 13;

int upit,par[maxn],col[maxn],xy[maxn];
int que[maxn];
bool vi[maxn];


const int dis[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

map<pair<int,int>, int> G;

struct node {
    int x, y, c;
    int sons[4];
    node(){}
    node(int X,int Y):x(X), y(Y), c(-1) {
        for (int i=0; i<4; ++i) sons[i]=-1;
    }
} nodes[maxn];


void pre(int n) {
    for(int i=0;i<n;++i) {
        int x, y; sa(x), sa(y);
        if(G.find(make_pair(x,y)) == G.end()) {
            G[make_pair(x,y)] = upit;
            xy[i] = upit;
            nodes[upit++] = node(x,y);
        }
        else xy[i] = G[make_pair(x,y)];
    }
}

int find(int n) {
    if(par[n]!=n) par[n] = find(par[n]);
    return par[n];
}
inline void unite(int a,int b)
{
    a = find(a), b = find(b);
    if(a==b) 
        return ;
    par[b]=a;
    col[a] += col[b];
}



void removeit(int h)
{
    int her = 0, ta = 0;
    que[ta++]=h;
    while(her < ta) {
        h = que[her++];
        for(int i=0;i<4;++i) {
            int p = nodes[h].sons[i];
            if(p != -1) {
                if(nodes[p].c==nodes[h].c&&!vi[p])  que[ta++]=p,vi[p]=1;
                else if(nodes[p].c==!nodes[h].c) ++col[find(p)];
            }
        }
        nodes[h].c=-1;
    }
}


void solve(int n) {
    for(int i = 0; i < n; i++) {
        int p=xy[i];
        int c=nodes[p].c=i&1;
        vi[p]=0;
        for(int j=0;j<4;++j) {
            int tx=nodes[p].x+dis[j][0],ty=nodes[p].y+dis[j][1];
            if(tx>0&&ty>0&&(nodes[p].sons[j]==-1||nodes[nodes[p].sons[j]].c==-1))
                ++col[p];
        }
        for(int j=0;j<4;++j) {
            int tmp=nodes[p].sons[j];
            if(tmp!=-1&&nodes[tmp].c!=-1)
            {
                --col[find(tmp)];
                if(nodes[tmp].c==c)
                    unite(tmp,p);
            }
        }
        for(int j=0;j<4;++j) {
            int tmp=nodes[p].sons[j];
            if(tmp!=-1&&nodes[tmp].c==!c&&col[find(tmp)]==0)
                removeit(tmp);
        }
        for(int j=0;j<4;++j) {
            int tmp=nodes[p].sons[j];
            if(tmp!=-1&&nodes[tmp].c==c&&col[find(tmp)]==0)
                removeit(tmp);
        }
        if(nodes[p].c!=-1&&col[find(p)]==0)   removeit(p);
    }
}

pii ansit(int upit) {
    int bl = 0, wh = 0; 
    for(int i=0;i<upit;++i)
        if(nodes[i].c==0)
            ++bl;
        else    if(nodes[i].c==1)
            ++wh;
    return pii(bl, wh);
}


int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T, n; sa(T);
    while (T--) {
        sa(n);
        memset(vi, 0, sizeof(vi));
        upit = 0;
        G.clear();
        pre(n);
        for(int i = 0;i < upit; ++i)    for(int j = 0; j < 4; ++j) {
            int tx=nodes[i].x+dis[j][0], ty=nodes[i].y + dis[j][1];
            map<pair<int,int>,int> ::iterator ite=G.find(make_pair(tx,ty));
            if(ite!=G.end())
                nodes[i].sons[j]=ite->yy;
        }
        for(int i = 0; i < n; i++) {
            par[i]=i,col[i]=0;
        }
        solve(n);
        pii t = ansit(upit);
        printf("%d %d\n", t.xx, t.yy);
    }
    return 0;
}


