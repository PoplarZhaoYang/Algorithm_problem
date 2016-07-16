/**
**题意**：给你一些交换规则，然后求任意使用这些交换规则后，排列的字典序最大。
**分析**：
很容易想到贪心的满足前面的为最大的贪心。
然后对于这些交换规则建图，任意一个联通分量里的元素是可以互换的。
我们把这个联通分量的所有值加入一个set，然后从联通分量重靠前的数开始在set末尾取即可。
求联通分量用并查集即可。
**心得**：
并查集可以直接给连通分量标号。
二元互换关系很容易写成无向图中的边建图。
**/
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1e6 + 7;
int A[maxn], par[maxn], rnk[maxn];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) par[x] = y;
    else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}
set<int> st[maxn];

int main(void) {
   // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        unite(x - 1, y - 1);
    }
    for (int i = 0; i < n; i++) {
        st[find(i)].insert(A[i]);
    }
    for (int i = 0; i < n; i++) {
        int p = find(i);
        printf("%d ", *--st[p].end());
        st[p].erase(--st[p].end());
    }
    puts("");
    return 0;
}

