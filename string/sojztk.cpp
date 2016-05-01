/**********************jibancanyang************************** 
 * *Author        :jibancanyang 
 *Created Time  : 五  4/22 11:23:34 2016
 *File Name     : cf665e.cpp
 *Problem:01 trie树求抑或
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
int  k, n, m, T;
int maxb = 30;
struct node {
    node *l, *r;
    ll cnt;
    node(void): l(NULL), r(NULL), cnt(0) {}
} *root;

inline int setone(int x, int temp) {
    return x | (1 << temp); 
}

inline int setzero(int x, int temp) {
    return x & (~(1 << temp));
}

void add(int x, node *cur) {
    for (int i = maxb; i >= 0; i--) {
        bool temp = (x >> i) & 1;
        if (temp) {
            if (cur -> r == NULL) cur -> r = new node;
            cur = cur -> r;
        } else {
            if (cur -> l == NULL) cur -> l = new node;
            cur = cur -> l;
        }
    }
}

ll search(int x, node *cur, int t, int op) {
    ll ret = 0;
    if (op == -1 && (t ^ x) > k) {
        k = t ^ x;
        return 0;
    }
    if (op < 29 && (t ^ x) + (1 << (op + 1)) < k) return 0;
    //if (op > 0 && op < 28 && (t ^ x) + (1 << (op + 1)) < k) return 0;
    if (cur -> l != NULL) ret += search(x, cur -> l, setzero(t, op), op - 1);
    if (cur -> r != NULL) ret += search(x, cur -> r, setone(t, op), op - 1);
    return ret;
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    sa(T);
    while (T--) {
       root = new node;
        sa(n), sa(m);
        int x;
        rep (i, 0, n) sa(x), add(x, root);
        k = 0;
        rep (i, 0, m) sa(x), search(x, root, x, maxb);
        printf("%d\n", k);
    }
    return 0;
}
