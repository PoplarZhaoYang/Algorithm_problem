#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
typedef long long ll;
const int maxn = int(1e5) + 13;
struct jibancanyang
{
    int b, d, k;
    ll elur[maxn], factors[maxn][8];

    void getElur() {
        memset(elur, 0, sizeof(elur));
        memset(factors, 0, sizeof(factors));
        elur[1] = 1;
        for (int i = 2; i < maxn; ++i) {
            if (!elur[i]) {
                for (int j = i; j < maxn; j += i) {
                    if (!elur[j]) elur[j] = j;
                    factors[j][++factors[j][0]] = i;
                    elur[j] = elur[j] * (i - 1) / i;
                }
            }
           // elur[i] += elur[i - 1];
        }
    }

    int doit(int limit, int x) {
        ll ret = 0;
        for (int s = 1; s < 1 << factors[x][0]; ++s) {
            int cur = 1, cnt = 0;
            for (int  i = 0; i < factors[x][0]; ++i) {
                if (s >> i & 1) ++cnt, cur *= factors[x][i + 1];
            }
            if (cnt & 1) ret += limit / cur;
            else ret -= limit / cur;
        }
        return (int)ret;
    }

    void fun() {
        int T, a, c, k;
        scanf("%d", &T);
        for (int cas = 1; cas <= T; ++cas) {
            scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
            if (k == 0) {
                printf("Case %d: 0\n", cas);
                continue;
            }
            b /= k, d /= k;
            ll ans = 0;
            if (b > d) swap(b, d);
            for (int i = d; i >= 1; --i) {
                if (b >= i) ans += elur[i];
                else {
                    ans += b - doit(b, i);
                }
            }
            printf("Case %d: %lld\n", cas, ans);
        }
    }
}ac;


int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.getElur();
    ac.fun();
    return 0;
}
