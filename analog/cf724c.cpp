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

using namespace std;
const int maxn = int(1e2) + 8, key = 20;

pair<char, int> A[maxn];

int df(int a, int b) {
    return 31 - __builtin_clz(b - a + 1);
}

struct st {
    int n;
    pair<char, int> table[key][maxn];
    st() {}
    st(int x, pair<char, int>* a) {
        n = x;
        for (int i = 1; i <= n; ++i) table[0][i] = a[i];
        for (int i = 1; i < key; ++i)
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }
    pair<int, int> gm(int a, int b) {
        int k = df(a, b);
        return min(table[k][a], table[k][b - (1 << k) + 1]);
    }
};
int n, mx;
int vis[maxn];
char str[maxn], outs[maxn];
int ct = 0;

void fun() {
    cin >> mx;
    scanf("%s", str + 1);
    n = strlen(str + 1);
    for (int i = 1; i <= n; ++i) A[i] = make_pair(str[i], -i);
    st sts(n, A);
    int l = 1, r = mx;
    char mc = 'a';
    memset(vis, 0, sizeof(vis));
    while (true) {
        char c;
        int cur;
        tie(c, cur) = sts.gm(l, r);
        cur = -cur;
        vis[cur] = true;
        mc = max(mc, c);
        outs[ct++] = c;
        if (cur + mx - 1 >= n) break;
        l = cur + 1;
        r = min(l + mx - 1, n);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i] && str[i] < mc) outs[ct++] = str[i];
    sort(outs, outs +  ct);
    printf("%s\n", outs);
}


int main()
{
#ifdef LOCAL
    freopen("inn.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    fun();
    return 0;
}

