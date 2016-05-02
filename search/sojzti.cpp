/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 2 12:15:35 2016
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
const int maxn = 40 + 13;
char G[maxn][maxn];
int n, m, sx, sy, ex, ey;
int dp[maxn][maxn][4][5], vis[maxn][maxn][4][5];
int dirx[] = {-1, 0, 1, 0}, diry[] = {0, 1, 0, -1};

struct node {
    int x, y, c, d;
    node(void): x(0), y(0), c(0), d(0) {}
    node(int a, int b, int C, int D): x(a), y(b), c(C), d(D) {}
};

class cmp
{
public:
    bool operator()(const node &a, const node &b) {
        return dp[a.x][a.y][a.d][a.c] > dp[b.x][b.y][b.d][b.c]; 
    }
};

priority_queue<node, vector<node>, cmp> que;

void getit(int x, int y, int d, int c, int mins)
{
    if (x < 0 || x >= n || y < 0 || y >= m || G[x][y] == '#') return;
    if (vis[x][y][d][c]) return;
    dp[x][y][d][c] = min(dp[x][y][d][c], mins);
    que.push(node(x, y, c, d));
    //pr(x), pr(y), pr(c), pr(d), pl(mins);
}

int bfs(void) 
{
    while (!que.empty()) que.pop();
    node cur;
    cur.x = sx, cur.y = sy, cur.c = 0, cur.d = 0;
    dp[cur.x][cur.y][cur.d][cur.c] = 0;
    vis[cur.x][cur.y][cur.d][cur.c] = true;
    que.push(cur);
    while (!que.empty()) {
        cur = que.top(); que.pop();
        vis[cur.x][cur.y][cur.d][cur.c] = 1;
        if (cur.x == ex && cur.y == ey && cur.c == 0) return dp[cur.x][cur.y][cur.d][cur.c]; 
        int mins = dp[cur.x][cur.y][cur.d][cur.c];
        getit(cur.x, cur.y, (cur.d + 1) % 4, cur.c, mins + 1);
        getit(cur.x, cur.y, (cur.d + 3) % 4, cur.c, mins + 1);
        getit(cur.x + dirx[cur.d], cur.y + diry[cur.d], cur.d, (cur.c + 1) % 5, mins + 1);
    }
    return -1;
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
        sa(n), sa(m);
        rep (i, 0, n) {
            scanf("%s", G[i]);
            rep (j, 0, m) {
                rep (k, 0, 4) rep (l, 0, 5) vis[i][j][k][l] = false, dp[i][j][k][l] = INF;
                if (G[i][j] == 'S') sx = i, sy = j;
                if (G[i][j] == 'T') ex = i, ey = j;
                
            }
        }
        pri(bfs());
    }
    
    return 0;
}
