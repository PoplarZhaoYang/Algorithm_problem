#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    long long a, b, n;
    int factors[100];

    void getFactors(int x) {
        factors[0] = 0;
        for (long long i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                factors[++factors[0]] = i;
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) factors[++factors[0]] = x;
    }

    long long rc(long long x) {
        if (x <= 1) return x;
        long long t = 0;
        for (int s = 1; s < 1 << factors[0]; ++s) {
            long long cur = 1, cnt = 0;
            for (int i = 0; i < factors[0]; ++i) {
                if (s >> i & 1) cur *= factors[i + 1], ++cnt;
            }
            if (cnt & 1) t += x / cur;
            else t -= x / cur;
        }
        return x - t;
    }

    void fun() {
        int T; 
        scanf("%d", &T);
        for (int cas = 1; cas <= T; ++cas) {
            scanf("%lld%lld%lld", &a, &b, &n);
            getFactors(n);
            printf("Case #%d: %lld\n", cas, rc(b) - rc(a - 1));
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
