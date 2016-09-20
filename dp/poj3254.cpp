#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

int mod = int(1e8);

struct jibancanyang
{
    int n, m;
    bool G[12][12];
    int  ok[12];
    int dp[2][1 << 12];
    int Set[1 << 12], cnt;

    void pre(int s, int cur = 0) {
        if (cur == m) {
            Set[cnt++] = s;
            return;
        }
        pre(s, cur + 1);
        if (!cur || !((s >> (cur - 1)) & 1)) pre(s | 1 << cur, cur + 1); 
    }

    void bug() {
        m = 3;
        pre(0);
        for (int i = 0; i < cnt; ++i) pr(Set[i]);
    }


    void fun() {
        while (~scanf("%d%d", &n, &m)) {
            cnt = 0;
            pre(0);
            for (int i = 0; i < n; ++i) {
                int s = 0;
                for (int j = 0; j < m; ++j) {
                    int x; 
                    scanf("%d", &x);
                    if (x) s |= 1 << j;
                    G[i][j] = x;
                }
                ok[i] = s;
       //         pr(i), pl(s);
            }
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < n; ++i) {
                int cur = i % 2, nxt = (i + 1) % 2;
                for (int t = 0; t < cnt; ++t) {
                    int s = Set[t];
                    dp[cur][s] = 0;
                    if ((s | ok[i]) == ok[i]) {
                        if (i == 0) dp[cur][s] = 1;
                        else for (int j = 0; j < cnt; ++j) {
                            int sLast = Set[j];
                            if ( (s & sLast) == 0) {
                                (dp[cur][s] += dp[nxt][sLast]) %= mod;
                            }
                        }
        //                pr(i), pr(s), pl(dp[cur][s]);
                    }

                }
            }
            int ans = 0;
            for (int i = 0; i < cnt; ++i) {
                ans += dp[(n - 1) % 2][Set[i]];
                ans %= mod;
            }
            printf("%d\n", ans);
        }
    }
}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.fun();
    return 0;
}
