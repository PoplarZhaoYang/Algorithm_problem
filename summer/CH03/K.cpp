/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  7/ 8 12:31:42 2016
**Problem**:
**Analyse**:
线段树维护区间和模板题，加一个条件，因为每个数最多被开方7次
就变成1了,所以对于为1的数我们就不需要更新了。
这里就是区间和等于区间长度，表面该区间全部为1。
**Get**:
线段树单点更新的固定套路。
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

#define ls p << 1, s, (s + e) / 2 
#define rs p << 1 | 1, (s + e) / 2 + 1, e
ll sum[maxn << 2];
ll A[maxn];
int n;

void up(int p) {
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void build(int p, int s, int e) {
    if (s == e) {
        sum[p] = A[s];
        return;
    }
    build(ls);
    build(rs);
    up(p);
}

ll query(int p, int s, int e, int l, int r) {
    if (s == l && e == r) return sum[p];
    int mid = (s + e) / 2;
    if (r <= mid) return query(ls, l, r);
    if (l > mid) return query(rs, l, r);
    return query(ls, l, mid) + query(rs, mid + 1, r); 
}

void update(int p, int s, int e, int l, int r) {
    if (e - s + 1 == sum[p]) return;
    int mid = (s + e) / 2;
    if (s == e) {
        sum[p] = (int)sqrt(sum[p]);
        return;
    }
    if (l <= mid) update(ls, l, r);
    if (r > mid) update(rs, l, r);
    up(p);
}


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
#endif
    int m, cas = 1;
    while (~sa(n)) {
        for (int i = 1; i <= n; i++) sal(A[i]);
        build(1, 1, n);
        sa(m);
        printf("Case #%d:\n", cas++); 
        while (m--) {
            int op, l, r; sa(op), sa(l), sa(r);
            if (r < l) swap(l , r);
            if (op) printf("%lld\n", query(1, 1, n, l, r)); 
            else  update(1, 1, n, l, r);
        }
        printf("\n");
    }
    return 0;
}
