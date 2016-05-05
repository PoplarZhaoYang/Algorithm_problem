/************************************************
 *Author        :jibancanyang
 *Created Time  :2016年05月04日 星期三 15时55分49秒

 **题意**:消消乐,每次必须消除数量大于等于3个,而且得分是消除个数的平方,每次消除之后局面往左下角收拢.
 **分析**:
 - 首先很容易想到对每个当前局面枚举每种颜色来dfs消除,注意这里对每一个已经消除过度页面要vis记录
 要不然超时,比赛的时候记录了,但是初始化vis的地方写错了,导致TLE,交换了顺序就AC....看来代码逻辑还是
 不够清晰,不能完整表达正确的想法,而且出现了错误不能很快正确的debug.
 - 对当前局面消除了之后,用类似unique函数的实现方式,模拟处理之后的局面再进行搜索,所以这里是两层
 dfs嵌套.
 - 这里的一个核心剪枝是启发式剪枝,假设当前局面的最优结果来和答案比较.
 **Get**:
 代码能力很重要,平时要正确一次AC的能力.

 ***********************************************/
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
#define xx first
#define yy second
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;
int dirx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[] = {0, 1, 1, 1, 0, -1, -1, -1};
int co[7];
int G[9][9];
int n, m, k, ans, cnt;
bool vis[9][9];

void pt(void) {
    prln(ans);
    cout << "co: " << endl;
    rep (i, 1, k + 1) cout << i << ": " << co[i]  << " " ;
    cout << endl;
    cout << "G: " << endl;
    rep (i, 1, n + 1) {
        rep (j , 1, m + 1) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}


int dfs1(int x, int y, int c) {
    int ret = 1;
    vis[x][y] = true;
    G[x][y] = -1;
    rep (i, 0, 8) {
        int u = x + dirx[i], v = y + diry[i];
        if (u > 0 && u <= n && v > 0 && v <= m && !vis[u][v] && G[u][v] == c) {
            ret += dfs1(u, v, c);
        }
    }
    return ret;
}
    
void pre(void) {
    int ed = 1;
    int GG[9][9];
    rep (i, 1, n + 1) rep (j, 1, m + 1) GG[i][j] = -1;
    for (int i = 1; i <= m; i++) {
        int st = n;
        bool ok = false;
        for (int j = n; j > 0; j--) {
            if (G[j][i] != -1) ok = true, GG[st--][ed] = G[j][i];
        }
        if (ok) ed++;
    }
    memcpy(G, GG, sizeof(G));
}



void dfs(int p) {
    int temp = 0;
    rep (i, 1, k + 1) if (co[i] >= 3) temp += co[i] * co[i];
    ans = max(ans, p);
    if (temp + p <= ans) return;
    memset(vis, 0, sizeof(vis));

    rep (i, 1, k + 1) {
        if (co[i] >= 3) {
            rep (a, 1, n + 1) {
                rep (b, 1, m + 1) {
                    if (G[a][b] == i && !vis[a][b]) {
                        int Gtemp[9][9];
                        memcpy(Gtemp, G, sizeof(G));
                        bool sd[9][9];

                        int kk = dfs1(a, b, i);
                        memcpy(sd, vis, sizeof(vis));

                        co[i] -= kk;
                        if (kk >= 3)  pre(), dfs(p + kk * kk);
                        co[i] += kk;

                        memcpy(vis, sd, sizeof(vis));
                        memcpy(G, Gtemp, sizeof(G));
                    }
                }
            }
        }
    }

}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d%d", &n, &m, &k) ) {
       // if (T++) break;
        ans = 0;
        memset(co, 0, sizeof(co));
        rep (i, 1, n + 1)
            rep (j, 1, m + 1) 
            sa(G[i][j]), co[G[i][j]]++;
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}
