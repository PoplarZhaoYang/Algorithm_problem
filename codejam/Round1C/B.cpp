/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/ 8 17:47:45 2016
 *File Name*     : B.cpp
**Problem**:
**Analyse**:
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
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
int T, B, M;
int G[55][55];
bool vis[55];
int ans;
bool ok;
bool out;

void got(int x) 
{
    if (ok) return;
    if (vis[x] || ans > M) {
        ok = true;
        return;
    }
    if (x == B) {
        ans++;
        return;
    }
    vis[x] = true;
    for (int i = 1; i <= B; i++) {
        if (G[x][i]) {
            got(i);
        }
    }
    vis[x] = false;
}

void judge(void) {
    ok = false;
    ans = 0;
    got(1);
    if (ans == M) out = true;
}

void dfs(int x, int y) 
{
    if (out) return;
    if (x == B) {
        judge();
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (x == y && i == 1) continue; 
        G[x][y] = i;
        if (y == B) dfs(x + 1, 1);
        else dfs(x, y + 1);
        if (out) return;
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    sa(T);
    int cas = 1;
    while (T--) {
        out = false;
        sa(B), sa(M);
        memset(vis, false, sizeof(vis));
        dfs(1, 1);
        printf("Case #%d: ", cas++);
        if (out) {
            puts("POSSIBLE");
            for (int i = 1; i <= B; i++) {
                for (int j = 1; j <= B; j++) {
                    if (j != 1) printf(" ");
                    printf("%d", G[i][j]);
                }
                puts("");
            }
        } else puts("IMPOSSIBLE");
    }
    
    return 0;
}
