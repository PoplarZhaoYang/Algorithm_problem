/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 六  5/14 21:08:38 2016
 *File Name*     : jy.cpp
**Problem**:soj4515 多重划分经典dp
给你一个多重背包,问你其中的物品能否组成$k(k < 100,000)$
**Analyse**:
> - 最直观的思路就是多重背包来做,然后写了个单调队列优化的多重背包,复杂复杂度$O(vn)$,由于常数大,仍然TLE\
> - 注意到这里我们只需要知道是否拼凑够$k$,这个信息很常规的多重背包的信息要求是不对称的,所以该
转变一下状态的定义方式.
> - 定义$dp[i][j]$:前$i$个数,拼凑成$j$的背包还剩多少个第$i$个物品.这样可以$O(1)$转移,复杂度$O(vn)$
常数非常小.
**Get**:
常规的多重背包之所以有大的复杂度,就是因为每个物品的个数为$m_i$,二进制优化就是来$log^{\sum m_i}$的处理,而单调队列优化是数据结构维护实现直接求最大值.
但是对于本题,我们只需要知道是否抽够$i$,可以把这个用了多少个数,保存为dp的内容.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;

int dp[maxn];
int a[111], b[111];

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    while (T--) {
        int n, k;
        sa(n), sa(k);
        memset(dp, -1, sizeof(dp));
        dp[0] = 0; 
        int cost, num;
        for (int i = 0; i < n; i++) 
            sa(a[i]);
        for (int j = 0; j < n; j++) 
            sa(b[j]);
        for (int i = 0; i < n; i++) {
            cost = a[i], num = b[i];
            if (dp[k] >= 0) break;
            for (int j = 0; j <= k; j++) {
                if (dp[j] >= 0) dp[j] = num;
                else if (cost > j || dp[j - cost] <= 0) dp[j] = -1;
                else dp[j] = dp[j - cost] - 1;
            }
        }
        printf("%s\n", dp[k] >= 0 ? "yes" : "no");
    }
    return 0;
}
