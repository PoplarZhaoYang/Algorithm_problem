/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/ 3 17:40:51 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
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
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 611;
int n, m, k, sx, sy, ex, ey;
char G[maxn][maxn];
int dirx[] = {-1, 0, 1, 0}, diry[] = {0, 1, 0, -1};
bool vis[maxn][maxn];
int getid(int r, int c) { return r * m + c; }

struct node {
    int u, v, d;
    node(){}
    node(int A, int B, int C):u(A), v(B), d(C) {}
};

vector<pii> V[maxn * maxn];

void bfs(int x, int y)
{
    queue<node> que;
    que.push(node(x, y, 0));
    //memset(vis, 0, sizeof(vis));
    rep (i, 0, n + 2) rep (j, 0, m + 2) vis[i][j] = false;
    vis[x][y] = true;

    while (!que.empty()) {
        node cur = que.front(); que.pop();
        rep (i, 0, 4) {
            int u = cur.u + dirx[i], v = cur.v + diry[i];
            if (u >= 0 && u < n && v >= 0 && v < m && !vis[u][v] && G[u][v] != 'W' && cur.d + 1  < k) {
                if (G[cur.u][cur.v] == 'E' || G[x][y] == 'E') if (cur.d + 1 == k) continue;
                vis[u][v] = true;
                if (G[u][v] != '.') {V[getid(x, y)].push_back(pii(getid(u, v), cur.d + 1));}
                que.push(node(u, v, cur.d + 1));
            }
        }

    }
}

int d[maxn * maxn];

int dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.push(pii(0, s));
    rep (i, 0, n * m + 10) d[i] = INF;
    d[s] = 0;
    while (!que.empty()) {
        pii cur = que.top(); que.pop();
        if (cur.xx > d[cur.yy]) continue;
        rep (i, 0, (int)V[cur.yy].size()) {
            pii nexts = V[cur.yy][i];
            if (d[nexts.xx] > d[cur.yy] + nexts.yy) {
                d[nexts.xx] = d[cur.yy] + nexts.yy;
                que.push(pii(d[nexts.xx], nexts.xx));
            }
        }
    }
    return d[getid(ex, ey)];
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    while (T--) {
        sa(n), sa(m), sa(k);
        rep (i, 0, n) scanf("%s", G[i]);
        rep (i, 0, n) {
            rep (j, 0, m) {
                if (G[i][j] != '.' && G[i][j] != 'W') bfs(i, j);
                if (G[i][j] == 'S') sx = i, sy = j;
                if (G[i][j] == 'E') ex = i, ey = j;
            }
        }
        if (V[getid(ex, ey)].size()) {
            int ans = dijkstra(getid(sx, sy));
            if (ans == INF) puts("Poor RunningPhoton!");
            else pri(ans);
        } else puts("Poor RunningPhoton!");
    
    }
    return 0;
}
