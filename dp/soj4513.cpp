/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/15 16:30:02 2016
**Problem**:
**Analyse**:
**Get**:
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
const int maxn = 1e5 + 13;
int dp[2][150009];
int Q[150009][2];


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T; sa(T);
    while (T--) {
        int n, m; sa(n), sa(m);
        ll d; sal(d);
        for (int i = 1; i <= n; i++) dp[0][i] = 0;
        int lastt = -INF;
        for (int i = 1; i <= m; i++) {
            int cur = i % 2, last = (i + 1) % 2, a, b, t; sa(a), sa(b), sa(t);
            ll size = (t - lastt) * d;
            int head = 1, tail = 1;

            for (int j = 1; j <= n; j++) {
                while (tail == head || Q[tail - 1][1] + 1 <= min(j + size, (ll)n)) {
                    int temp = Q[tail - 1][1] + 1;
                    if (tail == head) temp = j;
                    while (tail != head && dp[last][temp] > Q[tail - 1][0]) tail--;
                    Q[tail][0] = dp[last][temp], Q[tail][1] = temp, tail++;
                }
                if (j - size > Q[head][1]) head++;
                dp[cur][j] = Q[head][0] + b - abs(a - j);
            }
            lastt = t;
        }
        for (int i = 2; i <= n; i++) dp[m % 2][1] = max(dp[m % 2][1], dp[m % 2][i]);
        pri(dp[m % 2][1]);
    }
    return 0;
}
