/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/31 22:34:22 2016
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
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 5e5 + 13;
int T, n, m;
struct e {
    int from, to, cost;
    e(){}
    e(int a, int b, int c): from(a), to(b), cost(c){}
};
e edge[maxn * 4 + 9];

bool cmp(const e& a, const e &b) {
    return a.cost < b.cost;
}

int par[maxn], rnk[maxn];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i, rnk[i] = 0;
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return; 
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y) { return find(x) == find(y); }

void solve(void) {
    init(n);
    int ans = INF;
    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; i++) {
        if (!same(edge[i].from, edge[i].to)) {
            unite(edge[i].from, edge[i].to);
        } else {
            ans = edge[i].cost;
            break;
        }
    }
    if (ans == INF) puts("No solution!");
    else pri(ans);
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    sa(T);
    while (T--) {
        sa(n), sa(m);
        for (int i = 0; i < m; i++) {
            int x, y, z;
            sa(x), sa(y), sa(z);
            edge[i] = e(x, y, z) ;
        }
        solve();
    }
    return 0;
}
