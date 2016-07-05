/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/ 4 15:09:42 2016
**Problem**:
**Analyse**:
判断连通用并查集。这里就是左右两边的绝境被黑色连通了，那么就不行了。
用两个特殊数字分别表示左右绝境，并查集即可。
注意黑色会和周围8个而不是4个连通。
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
const int maxn = 500 + 13;
int l = 250000 + 2, r = 250000 + 3;
int par[maxn * maxn], rnk[maxn * maxn];
int G[maxn][maxn];
int dirx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[] = {0, 1, 1, 1, 0, -1, -1, -1};

void init(int n) {
    par[l] = l;
    par[r] = r;
    rnk[l] = rnk[r] = 0;
    for (int i = 0; i < n; i++) {
        
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



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int tt; sa(tt);
    while (tt--) {
        int n, m;
        sa(n), sa(m);
        init(n * m);
        for (int i = 0; i < n; i++) {
            char str[555];
            scanf("%s", str);
            for (int j = 0; j < m; j++) {
                if (str[j] == '0') G[i][j] = 0;
                else G[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (G[i][j] == 1) {
                    for (int k = 0; k < 8; k++) {
                        int x = i + dirx[k], y = j + diry[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && G[x][y] == 1) {
                            unite(x * m + y, i * m + j);
                        }
                    }
                    if (j == 0) {
                        unite(i * m + j, l);
                    } else if (j == m - 1) {
                        unite(i * m + j, r);
                    }
                }
            }
        }

        int q; sa(q);
        bool ok = false;int ans = 0;
        for (int i = 0; i < q; i++) {
            if (!ok && same(l, r)) {
                ok = true;
                ans = i;
            }
            int x1, y1;
            sa(x1), sa(y1);
            G[x1][y1] = 1;
            if (!ok) for (int k = 0; k < 8; k++) {
                int x = x1 + dirx[k], y = y1 + diry[k];
                if (x >= 0 && x < n && y >= 0 && y < m && G[x][y] == 1) {
                    unite(x * m + y, x1 * m + y1);
                }
                if (y1 == 0) {
                    unite(x1 * m + y1, l);
                } else if (y1 == m - 1) {
                    unite(x1 * m + y1, r);
                }
            }
        }
        if (!ok && same(l, r)) {
            ok = true;
            ans = q;
        }
        if (ok) pri(ans);
        else pri(-1);
    }
    return 0;
}
