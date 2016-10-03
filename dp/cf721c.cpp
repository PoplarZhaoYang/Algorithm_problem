#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  "
#define pl(x) cout << #x << ": " << x << endl;
const int maxn = 5e3 + 13;
int  dp[maxn][maxn];
int last[maxn][maxn];
int n, m, mt;
vector<pair<int, int> > G[maxn];
int D[maxn];


int main()
{
#ifdef xiaoai
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d%d", &n, &m, &mt)) {
        while (m--) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
           // if (y == 1) continue;
           // D[y]++;
            G[x].push_back(make_pair(y, z));
           // pr(x), pr(y), pl(z);
        }
        int inf = 0x3f3f3f3f;
       // for (int i = 1; i <= n; ++i) for (int j = 0; j <= n; ++j) dp[i][j] = !j ? 0 : (1e9 +8);
        memset(dp, 0x3f, sizeof(dp));
        dp[1][1] = 0;
        for (int j = 1; j < n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (dp[i][j] == inf) continue;
                for (auto k = G[i].begin(); k != G[i].end(); ++k) {
                    if (dp[k -> first][j + 1] > dp[i][j] + (k -> second)) {
                        dp[k -> first][j + 1] = dp[i][j] + (k -> second);
                        last[k -> first][j + 1] = i;
                    }
                }
            }
        }

        int ans;
        for (int i = 1; i <= n; ++i) {
            if (dp[n][i] <= mt) ans = i;
        }
        printf("%d\n", ans);
        
        stack<int> r;
        int now = n, p = ans;
        r.push(n);
        while (now != 1) {
            now = last[now][p];
            p--;
            r.push(now);
        }
        while (!r.empty()) {
            printf("%d ", r.top());
            r.pop();
        }
        puts("");
    }
    return 0;
}

