/*经典的水dp吧,好像在什么地方做过类似..
 * 定义:dp[cur][t]为在t时间在i位置的最大价值为多少.然后可以选择左走右走或者原地不动,三种状态转移过来就好了
 *复杂度就是dp数组的大小.
 *究其根本发现还是类似斐波那契数列的重算问题用记忆化缩减.
 */
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 7;
int list[maxn][11], tmax;
long long dp[11][maxn];

long long dfs(int cur, int t) {
    if (cur < 0 || cur > 10 || t > tmax) return 0;
    if (dp[cur][t]) return dp[cur][t];
    return dp[cur][t] = list[t][cur] + max(dfs(cur - 1, t + 1), max(dfs(cur, t + 1), dfs(cur + 1, t + 1)));
}

int main(void)
{
    cin.sync_with_stdio(false);
    int n;
    while (cin >> n, n) {
        memset(list, 0, sizeof(list));
        memset(dp, 0, sizeof(dp));
        tmax = 0;
        while (n--) {
            int t, x;
            cin >> x >> t;
            list[t][x]++;
            tmax = max(tmax, t);
        }
        cout << dfs(5, 0) << endl;
    }
    return 0;
}
