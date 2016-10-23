#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int n, k, A[11][20];

    void fun() {
        cin >> n >> k;
        memset(A, -1, sizeof(A));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &A[i][0]);
            for (int j = 1; j <= A[i][0]; ++j)
                scanf("%d", &A[i][j]);
        }
        int ans = 0, c = 0;
        for (int i = 1; c < k; ++i) {
            for (int j = 1; j <= n && c < k; ++j) {
                if (A[j][i] == -1) A[j][i] = 50;
                if (A[j][i] >= ans || A[j][i] > 49) {
                    ans += A[j][i], ++c;
                }
            }
        }
        cout << ans << endl;
    }

}ac;

int main()
{
#ifndef LOCAL
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
#endif
    ac.fun();
    return 0;
}
