#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    long long ans, n, A[22];

    int get(long long x) {
        return x ? get(x - (x & -x)) + 1 : 0;
    }


    void dfs(int ith, long long x, int f) {
        ans += ((long long)1 << get(x)) * f;
        for (int i = ith + 1; i <= n; ++i) 
            dfs(i, x & A[i], -2 * f);
    }

    void fun() {
        int T;
        scanf("%d", &T);
        for (int cas = 1; cas <= T; ++cas) {
            scanf("%lld", &n);
            for (int i = 1; i <= n; ++i) scanf("%lld", &A[i]);
            ans = 0;
            for (int i = 1; i <= n; ++i) 
                dfs(i, A[i], 1);
            printf("Case #%d: %lld\n", cas, ans);
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

