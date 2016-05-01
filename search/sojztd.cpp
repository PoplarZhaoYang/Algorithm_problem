/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 日  5/ 1 23:50:12 2016
 *File Name     : jy.cpp
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
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
int ans[6][6], n;
int node[26][4];
int eq[26][26];
bool vis[26];
bool got;
int mins;
//bool dp[1 << 27];

bool ok(int x, int y, int key) {
    if (y > 1) {
        if (node[key][3] != node[ans[x][y - 1]][1]) return false;
    }
    if (x > 1) {
        if (node[key][0] != node[ans[x - 1][y]][2]) return false;
    }
    return true;
}

void dfs(int x, int y) {
    if (x == n + 1) got = true;
    if (got) return;
    rep (i, 0, n * n) {
        bool flag = false;
        rep (j, 0, i) if (!vis[j] && eq[j][i])  {
            flag = true;
        }
        if (flag) continue;
        if (!vis[i] && ok(x, y, i)) {
            ans[x][y] = i;
            vis[i] = true;
            if (y == n) dfs(x + 1, 1);
            else dfs(x, y + 1);
            vis[i] = false;
            if (got) return;
        }
    }

}


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    sa(T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        memset(eq, 0, sizeof(eq));
        got = false;
        sa(n);
        rep (i, 0, n * n) sa(node[i][0]), sa(node[i][1]), sa(node[i][2]), sa(node[i][3]);
        for (int i = 0; i < n * n; i++) {
            for (int j = i + 1; j < n * n; j++) {
                bool have = true;
                for (int k = 0; k < 4; k++) {
                    if (node[i][k] != node[j][k]) have = false;
                }
                if (have) eq[i][j] = eq[j][i] = true; 
            }
        }
        dfs(1, 1);
        if (got) puts("Possible");
        else puts("Impossible");
    }
    
    return 0;
}
