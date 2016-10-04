#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
typedef long long ll;

struct jibancanyang
{
    ll n, ans;
    int prime[100], pCnt;

    void getPrime() {
        bool isprime[100]; 
        pCnt = 0;
        memset(isprime, 0, sizeof(isprime));
        for (int i = 2; i < 64; ++i) {
            if (!isprime[i]) {
                prime[pCnt++] = i;
                for (int j = i + i; j < 64; j += i) isprime[j] = true;
            }
        }
    }

    void dfs(int cur, ll x, int p) {
        if (x >= 63 || 1ll << x > n) return;
        //pr(cur), pl(x);
        if (cur == pCnt) {
            if (x != 1) ans += p * (int(pow(n, 1.0 / x) + 1e-9) - 1);
            return;
        }
        dfs(cur + 1, x * prime[cur], -p);
        dfs(cur + 1, x, p);
    }

    void fun() {
        getPrime();
        while (~scanf("%lld", &n)) {
            ans = 0;
            dfs(0, 1, -1);
            printf("%lld\n", ans + 1);
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
