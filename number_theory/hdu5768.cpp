#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    long long n, l, r, P[20], A[20];
    long long m[20], mod[20], cnt; 

    long long extgcd(long long a, long long b, long long &x, long long &y) {
        long long d = a;
        if (b) d = extgcd(b, a % b, y, x), y -= a / b * x;
        else x = 1, y = 0;
        return d;
    }

    long long mult(long long a, long long k, long long m) {
        long long ret = 0;
        while (k) {
            if (k & 1) ret = (ret + a) % m;
            a = (a + a) % m;
            k >>= 1;
        }
        return ret;
    }


    long long crt(long long r) {
         long long M = 1, ans = 0;
         for (int i = 0; i < cnt; ++i)
             M *= m[i];
         for (int i = 0; i < cnt; ++i) {
             long long N = M / m[i];
             long long x, y;
             extgcd(N, m[i], x, y);
             x = (x % m[i] + m[i]) % m[i];
             ans = (ans + mult(mult(mod[i] , x, M), N, M)) % M;
         }
         return (r - ans + M) / M;
    }

    long long run(long long x) {
        long long ret = x / 7;
        m[0] = 7, mod[0] = 0;
        for (int i = 1; i < (1 << n); ++i) {
            cnt = 1;
            for (int j = 0; j != n; ++j) {
                if ((i >> j) & 1) m[cnt] = P[j], mod[cnt++] = A[j];
            }
            long long c = crt(x);
            cnt & 1 ? ret +=  c : ret -=  c;
        }
        return ret;
    }

    void fun() {
        int T;
        scanf("%d", &T);
        for (int cas = 1; cas <= T; ++cas) {
            scanf("%lld%lld%lld", &n, &l, &r);
            for (int i = 0; i != n; ++i) 
                scanf("%lld%lld", &P[i], &A[i]);
            printf("Case #%d: %lld\n", cas, run(r) - run(l - 1));
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
