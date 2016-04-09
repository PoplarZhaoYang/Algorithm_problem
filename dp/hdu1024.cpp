/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 六  4/ 9 20:10:21 2016
 *File Name     : hdu1024.cpp
 *题目类型:最大m段和
 *感悟:看到这种分段的划分相关的,就会想到定义dp[i][j],表示以i为结尾的具有j性质的情况的个数.这种事典型的把大问题分解为
 *n个可递推问题的方法.这里发现这样定义出来,是竖着转移的,内存可能会爆,就改变了i,j的顺序(改变顺序无关紧要,只要注意矩阵的更新顺序就可以了.然后用滚动数组实现.在转移的时候少考虑了一种情况wa了无数发...以后不能这样wa了,要争取1A.
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e6 + 12;
ll dp[2][maxn];
int n, m;
ll a[maxn];

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    while (cin >> m >> n) {
        rep (i, 1, n + 1) cin >> a[i];
        ll ans = -ll(1e18);
        memset(dp, 0, sizeof(dp));

        rep (i, 1, m + 1) {
            int cur  = i % 2, last = (i + 1) % 2;
            ll maxs = -ll(1e18) ;
            dp[cur][i] = dp[last][i - 1] + a[i];
            

            //cout << dp[cur][i] << " ";
            for (int j = i + 1; j <= n; j++) {
                maxs = max(maxs, dp[last][j - 1]);
                maxs = max(maxs, dp[last][j - 2]);
                dp[cur][j] = max(dp[cur][j - 1] + a[j], maxs + a[j]);
               //<F5> cout << dp[cur][j] << " ";
                if (i == m) ans = max(dp[cur][j], ans);
            }
            
            //cout << endl;
            if (i == m) ans = max(dp[cur][m], ans);
        }
        cout << (m == 0 ? 0 : ans) << endl;
    }
    return 0;
}
