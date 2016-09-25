#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    static const int maxn = int(1e5) + 13;
    int n, m, primes[maxn], primeCnt, factors[maxn], factorCnt;
    bool isprime[maxn];

    void getPrime() {
        primeCnt = 0;
        memset(isprime, false, sizeof(isprime));
        for (int i = 2; i < maxn; ++i) {
            if (!isprime[i]) {
                primes[primeCnt++] = i;
                for (int j = i; j < maxn; j += i) {
                    isprime[j] = true;
                }
            }
        }
    }

    void getFactors(int x) {
        factorCnt = 0;
        for (int i = 0; (long long)primes[i] * primes[i] <= x; ++i) {
            if (x % primes[i] == 0) {
                factors[factorCnt++] = primes[i];
                while (x % primes[i] == 0) x /= primes[i];
            }
        }
        if (x > 1) factors[factorCnt++] = x;
    }

    long long rC() {
        long long ans = (long long)n * m;
        for (int K = 1; K <= n; ++K) {
            getFactors(K);
            for (int s = 1; s < 1 << factorCnt; ++s) {
                int cur = 1, cnt = 0;
                for (int i = 0; i < factorCnt; ++i) {
                    if (s >> i & 1) ++cnt, cur *= factors[i];
                }
                if (cnt & 1) ans -= m / cur;
                else ans += m / cur;
            }
        }
        return ans;
    }

    void fun() {
        int T; 
        scanf("%d", &T);
        getPrime();
        while (T--) {
            scanf("%d%d", &n, &m);
            printf("%lld\n", rC());
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
