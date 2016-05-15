/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/15 15:00:03 2016
**Problem**:soj 4512   dp构造 
**Analyse**:
- 我们只需要假想有两堆,我们来一块积木积木地添加.
- 定义$dp[i][j][k]$:前$i$个物品,一堆高为$j$,另一堆高为$k$,是否存在.这样是可行的,但是显然维度过高.
- 来想着降低维度,我们只需要知道两堆的相对差值,和这个差值下,其中一堆的高度.
那么来简化
- 定义$dp[i][j]$:前$i$个物品形成两堆差值为$j$的积木的最大高度和.
- 转移很好想,内存给的比较小,用滚动数组实现.
**Get**:
先给出通俗的状态定义,然后通过保留有用信息来降低维度,或者记录信息来降低转移复杂度.
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
const int maxn = 5e5 + 13;
int dp[2][maxn];
int h[55];

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T; sa(T);
    while (T--) {
        int n, sum = 0; sa(n);
        for (int i = 1; i <= n; i++) sa(h[i]), sum += h[i]; 
        for (int i = 0; i <= sum; i++) dp[0][i] = -INF;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
                if (j - h[i] >= 0) dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j - h[i]] +h[i]);
                if (j + h[i] <= sum) dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j + h[i]] + h[i]);
                if (h[i] - j >= 0) dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][h[i] - j] +h[i]);
            }
        }
        if (dp[n % 2][0] == 0) puts("GG");
        else  pri(dp[n % 2][0] / 2);
    }
    
    return 0;
}
