#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define pl(x) cout << #x << " " << x << endl
#define pr(x) cout << #x << " " << x << " "; 
vector<int> G[111];

struct jibancanyang
{
    int n, m, s, ans;
    int V[111], p;
    bool O[111][111];
    int vis[111], cnt;


    void pre(int x) {
        V[p++] = x;
        for (int i = 0; i < (int)G[x].size(); ++i) {
            if(G[x][i] > x) V[p++] = G[x][i];
        }
    }

    void dfs(int cur, int have) {
        if (have  == s) {
            ans++;
            return;
        }
        if (cur == p) return;
        if (cur != 0) dfs(cur + 1, have);

        bool ok = true;
        for (int i = 0; i < cnt; ++i) {
            if (O[vis[i]][V[cur]] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            vis[cnt++] = V[cur];
            dfs(cur + 1, have + 1);
            cnt--;
        }
    }

    void fun() {
        int T;
        scanf("%d", &T);
        while (T--) {
            memset(O, false, sizeof(O));
            for (int i = 1; i<= n; ++i) G[i].clear();
            ans = 0;
            scanf("%d%d%d", &n, &m, &s);
            for (int i = 1; i <= m; ++i) {
                int x, y;
                scanf("%d%d", &x, &y);
                O[x][y] = O[y][x] = true;
                G[x].push_back(y);
                G[y].push_back(x);
            }
            for (int i = 1; i <= n; ++i) {
                p = cnt = 0;
                pre(i);
                if (p < s) continue;
                else {
                    dfs(0, 0);
                }
            }
            printf("%d\n", ans);
        }
    }

}ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    ac.fun();
    return 0;
}
