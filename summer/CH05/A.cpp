/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/13 11:05:57 2016
**Problem**:
**Analyse**:
求无向图的割顶。求出所有割顶之后，对每个割顶看它有多少个连通分量被割开
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
typedef vector<int> vi;
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
const int maxn = 1e5 + 13;
vi G[1009];
int low[1009], pre[1009], dfs_clock;
bool iscut[1009];
bool vis[1009];

int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = true;
            }
        } else if (pre[v] < pre[u] && v != fa) lowu = min(lowu, pre[v]);
    }
    if (fa < 0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}

void run(int cur) {
    vis[cur] = true;
    for (int i = 0; i < (int)G[cur].size(); i++) {
        int to = G[cur][i];
        if (!vis[to]) {
            run(to);
        }
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int cas = 1;
    while (true) {
        for (int i = 1; i <= 1000; i++) G[i].clear();
        int x, y;
        sa(x);
        if (!x) break;
        for (int i = 0; ; i++) {
            if (i) sa(x);
            if (i && !x) break;
            sa(y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memset(pre, 0, sizeof(pre));
        memset(iscut, false, sizeof(iscut));
        dfs_clock = 0;
        dfs(1, -1);
        bool ok = true;
        printf("Network #%d\n", cas++);
        for (int i = 1; i <= 1000; i++) {
            if (iscut[i]) {
                ok = false;
                int sub = 0;
                memset(vis, false, sizeof(vis));
                vis[i] = true;
                for (int j = 0; j < (int)G[i].size(); j++) {
                    int to = G[i][j];
                    if (!vis[to]) {
                        sub++;
                        run(to);
                    }
                }
                printf("  SPF node %d leaves %d subnets\n", i, sub);
            }
        }
        if (ok) printf("  No SPF nodes\n");
        puts("");
    }
    return 0;
}
