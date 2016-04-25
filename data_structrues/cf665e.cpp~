/**********************jibancanyang************************** *Author        :jibancanyang *Created Time  : 五  4/22 11:23:34 2016
 *File Name     : cf665e.cpp
 *Problem:
 *Get:
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e6 + 12;
int xors[maxn], k, n, a[maxn];

struct node {
    node *l, *r;
    ll cnt;
    node(void): l(NULL), r(NULL), cnt(0) {}
} *root;

void add(int x, node *cur) {
    if (cur != root && !x) return;
    if (!(x & 1)) {
        if (cur -> l == NULL) cur -> l = new node;
        cur = cur -> l;
        (cur -> cnt)++;
        add(x >> 1, cur);
    } else {
        if (cur -> r == NULL) cur -> r = new node;
        cur = cur -> r;
        (cur -> cnt)++;
        add(x >> 1, cur);
    }
}

ll search(int x, node *cur, int t) {
    cout << t << endl;
    if (cur != root && (t ^ x) >= k) return cur -> cnt;
    ll ret = 0;
    if (cur -> l != NULL) ret += search(x, cur -> l, t << 1);
    if (cur -> r != NULL) ret += search(x, cur -> r, (t << 1) | 1);
    return ret;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    cin >> n >> k;
    xors[0] = 0;
    root = new node;
    
    rep (i, 1, n + 1) cin >> xors[i], a[i] = xors[i], xors[i] = xors[i] ^ xors[i - 1];
    
    ll ans = 0;
    rep (i, 1, n + 1) {
        add(xors[i - 1], root);
        ans += search(xors[i], root, 0);
    }
    cout << ans << endl;
    return 0;
}


