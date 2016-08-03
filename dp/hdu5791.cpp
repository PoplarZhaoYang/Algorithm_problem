#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int n, m;
    int A[1009], B[1008];
    long long dp[1009][1009];
    int mod = int(1e9) + 7;

    void fun() {
        while (~scanf("%d%d", &n, &m)) {
            for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
            for (int j = 1; j <= m; ++j) scanf("%d", &B[j]);
            A[0] = B[0] = 0;
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                    if (A[i] == B[j]) dp[i][j] +=  dp[i - 1][j - 1] + 1;
                    dp[i][j] = (dp[i][j] % mod + mod) % mod;
                }
            }
            printf("%lld\n", dp[n][m]);
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
