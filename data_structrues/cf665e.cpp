/**********************jibancanyang************************** 
 * *Author        :jibancanyang 
 *Created Time  : 五  4/22 11:23:34 2016
 *File Name     : cf665e.cpp
 *Problem:01 trie树求抑或
 *Get:
**题意**:给定一个数列,求其中抑或值大于等于$k$的子序列的数量.
**分析**:
- 首先知道抑或有类似于前缀和的区间性质,可以$O(n ^ 2)$求任意区间抑或值.
- 预处理前缀抑或,然后对以每个数结尾的抑或都去查其前面的子序列,显然这里复杂度是平方.
- 然后我们就想到用trie树来维护一颗01字典树的经典用法,每次去查询当前点之前的前缀即可,而且可以有两个
剪枝
- -最优化剪枝,如果之后的抑或值全为1都不能大于等于k就减去
- -如果当前前缀已经满足,就直接加前缀值,就不用查后面.
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
int xors[maxn], k, n;
int maxb = 28;
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
        (cur -> cnt)++;
    }
}

ll search(int x, node *cur, int t, int op) {
    if ((t ^ x) + (1 << (op + 1)) < k) return 0;
    ll ret = 0;
    if (cur != root && (t ^ x) >= k) {
        ret += cur -> cnt;
        return ret;
    }
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
    cin >> n >> k;
    xors[0] = 0;
    root = new node;
    rep (i, 1, n + 1) sa(xors[i]),  xors[i] = xors[i] ^ xors[i - 1];
    
    ll ans = 0;
    rep (i, 1, n + 1) {
        // pl(i);
       add(xors[i - 1], root);
       ans += search(xors[i], root, xors[i], maxb);
    }
    cout << ans << endl;
    return 0;
}

