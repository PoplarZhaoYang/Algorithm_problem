#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int T, n, A[112345];
    int bit[112345];
    int ans[112345];

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i , int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    void fun() {
        scanf("%d", &T);
        for (int cas = 1; cas <= T; cas++) {
            memset(bit, 0, sizeof(bit));
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
            printf("Case #%d:", cas);
            for (int i = 1; i <= n; i++) {
                int x = sum(A[i]);
                int f = A[i] - 1 - x;
                add(A[i], 1);
                ans[A[i]] = i + f - min(A[i], i);
            }
            for (int i = 1; i <= n; i++) 
                printf(" %d", ans[i]);
            puts("");
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
