/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/15 15:00:03 2016
**Problem**:soj 4511   dp差值 
**Analyse**:
- 差值dp,最大限度的减少信息容易,而有最低的维度.
- 这里要想象有两个任务堆,左边一个,右边一个,然后往上面添加任务.
- 这个题与前面的积木堆得不同是,任务的执行顺序的限制,这需要在dp转移的时候结合实际来考虑.
- 定义$dp[i][j]$:前$i$个物品形成左堆和右堆得差值为$j$的序列的最小时间 .
- 转的核心就是本机器里的任务要执行完了再叠加,内存给的比较小,用滚动数组实现.
**Get**:
差值dp的经典特点是两堆,然后维护该差值下的最值即可.
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
const int maxn = 6e3 + 13;
int dp[2][maxn * 2];
int a[2009], b[2016];

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T; sa(T);
    while (T--) {
        int n, sum = 0; sa(n);
        for (int i = 0; i < n; i++) sa(a[i]), sa(b[i]), sum = max(sum, max(a[i], b[i])); 
        for (int i = -sum; i <= sum; i++) dp[0][i + maxn] = INF;
        dp[0][0 + maxn] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = -sum; j <= sum; j++) dp[(i + 1) % 2][j + maxn] = INF;
            for (int j = -sum; j <= sum; j++) {
                if (dp[i % 2][j + maxn] != INF) {
                    if (j <= 0) {
                         dp[(i + 1) % 2][j + a[i] + maxn] = min(dp[(i + 1) % 2][j + a[i] + maxn] ,dp[i % 2][j + maxn] + ((j + a[i]) < 0 ? 0 : (j + a[i])));
                         dp[(i + 1) % 2][-b[i] + maxn] = min(dp[(i + 1) % 2][-b[i] + maxn], dp[i % 2][j + maxn] + b[i]);
                    } else {
                         dp[(i + 1) % 2][a[i] + maxn] = min(dp[(i + 1) % 2][a[i] + maxn], dp[i % 2][j + maxn] + a[i]);
                         dp[(i + 1) % 2][j - b[i] + maxn] = min(dp[(i + 1) % 2][j - b[i] + maxn], dp[i % 2][j + maxn] + ((b[i] - j) < 0 ? 0 : (b[i] - j)));
                    }
                }
            }
        }
        int ans = INF;
        for (int i = -sum; i <= sum; i++)   ans = min(ans, dp[n % 2][i + maxn] );
        pri(ans);
    }

    return 0;
}

