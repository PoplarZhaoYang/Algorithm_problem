#include <cstdio>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    vector<int> G[18];
    int dp[(1 << 18)][18], n;
    long long pows[1 << 18];
    long long mod = 1ll << 32;

    void pre() {
        pows[0] = 1;
        for (int i = 1; i < 1 << 18; ++i) pows[i] = pows[i - 1] * 233, pows[i] %= mod;
    }

    void fun() {
        int T;
        scanf("%d", &T);
        pre();
        while (T--) {
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                G[i].clear();
                getchar();
                for (int j = 0; j < n; ++j) {
                    char c;
                    c = getchar();
                    if (c == '1') G[i].push_back(j);
                }
            }

            for (int s = 1; s < 1 << n; ++s) {
                int mins = 120, from, k, a;
                for (int j = 0; j < n; ++j) {
                    if (s >> j & 1) {
                        int nxt = s ^ (1 << j), cnt = 0;

                        bool sst[19];
                        memset(sst, 0, sizeof(sst));
                        for (auto c : G[j]) {
                            if (nxt >> c & 1) {
                                if (!sst[dp[nxt][c]]) cnt++;
                                sst[dp[nxt][c]] = true;
                            }
                        }

                        int nxtcnt = 0;
                        bool st[19];
                        memset(st, 0, sizeof(st));
                        for (int i = 0; i < n; ++i) {
                            if (nxt >> i & 1) {
                                if (!st[dp[nxt][i]]) nxtcnt++;
                                st[dp[nxt][i]] = true;
                            }
                        }

                        int add = -1;
                        for (int i = 1; i <= nxtcnt; ++i) 
                            if ( st[i] == 0) 
                                add = i;
                        if (add == -1) add = cnt + 1; 

                        cnt = max(cnt, nxtcnt);
                        if (cnt <= mins) {
                            mins = cnt; 
                            from = nxt;
                            k = j;
                            a = add;
                        }
                    }
                }
                for (int i = 0; i < n; ++i) dp[s][i] = dp[from][i];
                dp[s][k] = a;
            }

            long long ans = 0;
            for (int s = 1; s < 1 << n; ++s) {
                int id = 0;
                for (int i = 0; i < n; ++i) id = max(id, dp[s][i]);
                ans = (ans + id * pows[s] % mod) % mod;
            }
            printf("%lld\n", ans);
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
