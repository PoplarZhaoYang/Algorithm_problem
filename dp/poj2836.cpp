#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int dp[1 << 15], n;
    int matrixs[15 * 15][2], points[15][2], cnt;

    void preProcess() {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = abs(points[i][0] - points[j][0]), b = abs(points[i][1] - points[j][1]);
                if (a == 0) a = 1;
                if (b == 0) b = 1;
                matrixs[cnt][0] = a * b;
                matrixs[cnt][1] = 0;
                for (int k = 0; k < n; ++k) {
                    if (min(points[i][0], points[j][0]) <= points[k][0] && points[k][0] <= max(points[i][0], points[j][0])
                        && min(points[i][1], points[j][1]) <= points[k][1] && points[k][1] <= max(points[i][1], points[j][1]))
                            matrixs[cnt][1] |= 1 << k;
                }
                cnt++;
            }
        }
    }
    int dynamicProgramming() {
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int s = 0; s < 1 << n; ++s) {
            for (int i = 0; i < cnt; ++i) {
                dp[s | matrixs[i][1]] = min(dp[s | matrixs[i][1]], dp[s] + matrixs[i][0]);
            }
        }
        return dp[(1 << n) - 1];
    }


    void fun() {
        while (scanf("%d", &n), n) {
            cnt = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d%d", &points[i][0], &points[i][1]);
            }
            preProcess();
            printf("%d\n", dynamicProgramming());
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
