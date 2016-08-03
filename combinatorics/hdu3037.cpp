#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int n, m, mod;
    int fac[int(1e5) + 7]; //定义范围为mod的范围！

    void init() {
        fac[0] = 1;
        for (int i = 1; i <= mod; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
    }

    long long fastpow(long long a, long long b) {
        long long x = a % mod, ret = 1;
        while (b) {
            if (b & 1) ret = ret * x % mod;
            x = x * x % mod;
            b >>= 1;
        }
        return ret;
    }

    int C(int n, int m, int mod) {
        return m > n ? 0 : fac[n] * fastpow((long long)fac[m] * fac[n - m], mod - 2) % mod;
    }

    int lucas(long long n, long long m, int mod) {
        return m ? (long long)C(n % mod, m % mod, mod) * lucas(n / mod, m / mod, mod) % mod : 1;
    }

    void fun() {
        int T;
        scanf("%d", &T);
        
        while (T--) {
            cin >> n >> m >> mod;
            init();
            cout << lucas(n + m, m, mod) << endl;;
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
