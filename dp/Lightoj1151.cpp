#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
const int maxn = 103;
const double eps = 1e-9;

double a[maxn][maxn], ans[maxn];
int jump[maxn << 1];


void gauss(void) {
    int i, j, t, k;
    for (i = 1; i <= 100; i++) {
        t = i;
        for (j = i + 1; j <= 100; j++) if (a[t][i] < a[j][i]) t = j;
        if (t != i) for (j = 1; j <= 101; j++) swap(a[i][j], a[t][j]);
        if (fabs(a[i][i]) < eps) continue;
        for (j = i + 1; j <= 100; j++) {
            if (fabs(a[j][i]) > eps) {
                double tt = a[j][i] / a[i][i];
                for (k = i; k <= 101; k++) a[j][k] -= a[i][k] * tt;
            }
        }
    }
    for (i = 100; i >= 1; i--) {
        for (j = 100; j > i; j--) {
            a[i][101] -= a[i][j] * ans[j];
        }
        if (fabs(a[i][i] > eps)) ans[i] = a[i][101] / a[i][i];
        if (fabs(a[i][i]) < eps) ans[i] = 0.0;
    }
}

void build_a(void) {
    memset(ans, 0.0, sizeof(ans));
    memset(a, 0.0, sizeof(a));

    for (int i = 1; i <= 100; i++) {
        a[i][i] = a[i][101] = 6;
        for (int j = 1; j <= 6; j++) {
            if (i + j > 100) a[i][i] -= 1;
            else a[i][jump[i + j]] += -1;
        }
    }
}

int main()
{
#ifdef LOCAL 
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T, N;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        for (int i = 1; i <= 100; i++) jump[i] = i;
        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            jump[x] = y;
        }
        build_a();
        gauss();
        printf("Case %d: %.15f\n", cas, ans[1]);
    }
    return 0;
}
