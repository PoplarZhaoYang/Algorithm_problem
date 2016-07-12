/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/12 11:18:47 2016
**Problem**:
**Analyse**:
这里求一个数左边第一不和它互质的数，用了维护质因子的方法。
求$maxn$以内所有数的质因子，复杂度为$log^{maxn}log^{maxn}$
对区间按左端点排序，离线处理。
树状数组来维护区间的和的应用：
$[l,r]$区间满足条件的数加1,那么就是$add(l, 1)$, $add(r + 1, -1)$这样的组合操作。
这种对区间和的快速操作也出现在树状数组求逆序对中。
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
const int maxn = 2e5 + 13;

struct node {
    int l, r, num;
}query[maxn];

int A[maxn], bit[maxn], l[maxn], r[maxn], ans[maxn], vis[maxn];
int n, m;

void add(int i, int x) {
    while (i > 0) {
        bit[i] += x;
        i -= i & -i;
    }
}

int sum(int i) {
    int ret = 0;
    while (i <= n) {
        ret += bit[i];
        i += i & -i;
    }
    return ret;
}

vector<int> vec[maxn], edge[maxn];

bool cmp(node &a, node &b) {
    return a.l < b.l;
}

int prime[maxn / 10], cn = 0;
bool isprime[maxn];

void getprime(void) {
    for (int i = 2; i < maxn; i++) {
        if (!isprime[i]) {
            prime[cn++] = i;
            for (int j = i; j < maxn; j += i) isprime[j] = true;
        }
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    getprime();
    for (int i = 0; i < cn; i++) {
        for (int j = prime[i]; j < maxn; j += prime[i]) {
            vec[j].push_back(prime[i]);
        }
    }
    while (sa(n), sa(m), n || m) {
        for (int i = 1; i <= n; i++) sa(A[i]);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            int t = 0;
            for (int j = 0; j < (int)vec[A[i]].size(); j++) {
                t = max(vis[vec[A[i]][j]], t);
                vis[vec[A[i]][j]] = i;
            }
            l[i] = t;
        }
        memset(vis, 0x3f, sizeof(vis));
        for (int i = n; i >= 1; i--) {
            int t = n + 1;
            for (int j = 0; j < (int)vec[A[i]].size(); j++) {
                t = min(t, vis[vec[A[i]][j]]);
                vis[vec[A[i]][j]] = i;
            }
            r[i] = t;
        }

        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            if (l[i]) edge[l[i]].push_back(i);
            else {
                add(i, 1);
                if (r[i] <= n) add(r[i], -1);
            }
        }
        for (int i = 1; i <= m; i++) {
            sa(query[i].l), sa(query[i].r), query[i].num = i;
        }
        sort(query + 1, query + m + 1, cmp);
        int cnt = 1;
        query[m + 1].l = -1;
        for (int i = 1; i <= n; i++) {
            while (query[cnt].l == i) {
                ans[query[cnt].num] = sum(query[cnt].l) - sum(query[cnt].r + 1);
                cnt++;
            }
            add(i, -1);
            if (r[i] <= n) add(r[i], 1);
            for (int j = 0; j < (int)edge[i].size(); j++) {
                int x = edge[i][j];
                add(x, 1);
                if (r[x] <= n) add(r[x], -1);
            }
            edge[i].clear();
        }
        for (int i = 1; i <= m; i++) pri(ans[i]);
    }
    return 0;
}
