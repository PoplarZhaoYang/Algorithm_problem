/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/ 4 15:09:42 2016
**Problem**:
**Analyse**:
前提是一定有一个裁判。
我们来枚举裁判，并屏蔽他，然后看剩余的时候不矛盾。
判断不矛盾的时候，使用并查集维护相互之间的关系。
对于人x,x -> 石头用x表示，x -> 剪刀用x+n表示，x->布用x+2n表示。
这样对于没出出现的一个断言，我们都有三种情况，并且把同时发生的情况合并入一个并查集，表示它们会同时发生。
然后在每一个断言之前我们需要判断是否矛盾，就是加入当前断言之后的矛盾情况是否会发生。
如果不矛盾，当前屏蔽的人就可能是裁判。
如果可能是裁判的人大于1，则无法确定。
如果可能为裁判的没有，则不可能。
否则就是这个人是裁判，判断它是裁判的最早语句是矛盾语句的最早出现，因为目前
只有该人可能是裁判，一旦矛盾确实它就是裁判。
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
int par[maxn * 3], rnk[maxn * 3];
int a[2002][3];

void init(int n) {
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
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < m; i++) {
            char x;
            scanf("%d%c%d", &a[i][0], &x, &a[i][2]);
            if (x == '=') a[i][1] = 0;
            else if (x == '>') a[i][1] = 1;
            else {
                swap(a[i][0], a[i][2]);
                a[i][1] = 1;
            }
        }
        int ans = -1;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            init(n * 3);
            int j;
            for ( j = 0; j < m; j++) {
                if (a[j][0] == i || a[j][2] == i) continue;
                int x = a[j][0], y = a[j][2];
                if (a[j][1]) {
                    if (same(x, y) || same(x, y + 2 * n)) {
                        ans = max(ans, j);
                        break;
                    }
                    unite(x, y + n);
                    unite(x + n, y + 2 * n);
                    unite(x + 2 * n, y);
                } else {
                    if (same(x, y + n) || same(x, y + 2 * n)) {
                        ans = max(ans, j);
                        break;
                    }
                    unite(x, y);
                    unite(x + n, y + n);
                    unite(x + 2 * n, y + 2 * n);
                }
            }
            if (j == m) {
                v.push_back(i);
            }
        }
        if (v.size() == 1) {
            printf("Player %d can be determined to be the judge after %d lines\n", v[0], ans + 1);
        } else if (v.size() == 0) {
            puts("Impossible");
        } else {
            puts("Can not determine");
        }
    }
    return 0;
}
