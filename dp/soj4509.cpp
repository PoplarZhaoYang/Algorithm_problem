/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/17 14:42:51 2016
**Problem**:soj 4509 斜率优化dp
**Analyse**:
给你n个点,每个点必须被线段覆盖,每个线段覆盖的划分是$(x_j - x_i)^2 + W$,其中$x_j,x_i$是线段端点,可以为同一点.
**Get**:
> - 容易把这个大问题,划分为一系列,可递推的子问题.很容易想到是dp状态,
定义$dp[i]$:以$i$点作为最后一条线段的结尾,所花费的最小值.
> - 容易有状态转移方程:$$dp[i] = min{dp[j] + (x_i - x_{j + 1}^2 \ | \ 0 <= j <= i - 1}$$
> - 然后发现复杂度$O(n^2)$,必须要优化转移到$O(1)$
> - 注意到这里是斜率优化dp,典型的形式:$$dp[i] = min(max){dp[j] + f(i, j)}$$
> - 化为斜率式子,用单调队列维护凹壳,每次在队列头取值即可.
**Code**:
***********************1599664856@qq.com**********************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 2e5 + 13;
int T, n, W;
ll X[maxn];
ll dp[maxn];
int Q[maxn];

ll slope(int j, int k) { // j <= k;
    if (X[j + 1] == X[k + 1]) {
        return int(1e18);
    }
    return (dp[j] - dp[k] + X[j + 1] * X[j + 1] - X[k + 1] * X[k + 1]) / (X[j + 1] - X[k + 1]);
    
}


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    sa(T);
    while (T--) {
        sa(n), sa(W);
        for (int i = 1; i <= n; i++) sal(X[i]);

        int head = 1, tail = 2;
        Q[head] = 0; 
        dp[0] = 0; 
        X[0] = X[1];

        for (int i = 1; i <= n; i++) {
            while (tail - head > 1 && slope(Q[head], Q[head + 1]) < 2 * X[i]) head++;
            dp[i] = dp[Q[head]] + (X[i] - X[Q[head] + 1]) * (X[i] - X[Q[head] + 1]) + W;
            while (tail - head > 1 && slope(Q[tail - 2], Q[tail - 1]) > slope(Q[tail - 1], i)) tail--;
            Q[tail++] = i;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
