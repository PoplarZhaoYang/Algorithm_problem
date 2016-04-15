/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/15 17:04:12 2016
 *File Name     : hdu5534.cpp
 *Problem:完全背包变形
 *Get:模拟比赛的时候把问题转化为了,容量为2(n - 1),选择物品数为n的,完全背包.就围绕着怎么解决这个固定选择定量物品数
 *怎么也想不出来.其实这样里需要一个巧妙的处理办法,反正每个节点最后都至少要有一度,我就让它们都先选择一度,然后对剩下的
 *(n - 2)度,把它划分为任意的分数,加在那些已经一度的节点上,这个性质就是全全背包,但是这里注意每个物品的价值了a[1 + i] - a[1].
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 2015 + 12;
int dp[maxn], a[maxn], n, T;


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        rep (i, 1, n) cin >> a[i];
        int ans = a[1] * n;
        fill(dp, dp + n + 10, -INF), dp[0] = 0;
        rep (i, 1, n - 1) {
            for (int j = i; j <= n - 2; j++) {
                dp[j] = max(dp[j], dp[j - i] + a[1 + i] - a[1]);
            }
        }
        cout << dp[n - 2] + ans << endl;
    }
    return 0;
}
