/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/ 4 15:09:42 2016
**Problem**:
**Analyse**:
把边从大到小排序，然后依次加边，直到1和n连通的最小边长即可。
另一种思路：
考虑dijkstra求最长路我们知道，这里求最大承重量也行。
定义$d[i]$为从$1$到$i$的承重量，然后松弛操作是$d[j] = min(d[i], cost(i, j))$
可以知道dijkstra的性质不受松弛操作的影响而影响，因为在路径长度中松弛操作通常会把值变大，而这里承重量是变小。
可以说dijkstra只是提供了一种更新顺序，总是用最优的值去更新。
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
const int maxn = 1000 + 13;
int par[maxn], rnk[maxn];

struct edge {
    int from, to, cost;
};


void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    if (x == par[x]) return x;
    return find(par[x]);
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

bool same(int a, int b) {
    return find(a) == find(b);
}

bool cmp(const edge &a ,const edge &b) { return a.cost > b.cost; }

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; sa(T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m;
        sa(n), sa(m);
        vector<edge> v;
        init(n);
        for (int i = 0; i < m; i++) {
            edge temp;
            sa(temp.from), sa(temp.to), sa(temp.cost);
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            unite(v[i].from, v[i].to);
            if (same(1, n)) {
                ans = v[i].cost;
                break;
            }
        }
        printf("Scenario #%d:\n", cas);
        printf("%d\n\n", ans);
    }
    return 0;
}
