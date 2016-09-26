#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
typedef long long ll;

struct jibancanyang
{
    int n, m, A[10];
    long long ans;
    ll gcd(ll a, ll b) {
        if (!b) return a;
        return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    void dfs(int cur, long long p, int cnt) {
        if (p >= n) return;
        if (cur == m) {
            if (cnt & 1) ans += (n - 1) / p;
            else ans -= (n - 1) / p;
        } else {
            dfs(cur + 1, p, cnt);
            dfs(cur + 1, lcm(p, A[cur]), cnt + 1);
        }
    }

    void fun() {
        while (~scanf("%d%d", &n, &m)) {
            for (int i = 0; i < m; ++i) {
                scanf("%d", &A[i]);
                if (!A[i]) --m, --i;
            }
            ans = 0;
            dfs(0, 1, 0);
            printf("%lld\n", ans + n - 1);
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
