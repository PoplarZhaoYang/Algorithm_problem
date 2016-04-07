/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 四  4/ 7 15:03:15 2016
 *File Name     : poj3616.cpp
 *题目类型:dp
 *感悟:开始显得很杂乱,排序之后总是能看起来简单些.一种带权值得区间划分.转化为n个子问题,dp[i]为以第i个区间作为结尾能得到的最大权值和.这种转化多出了一个维度,但是却让问题之间的转换只有一维.所以总共只有二维.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;

int dp[maxn / 100];
struct node{
    int xx,  yy;
    int c;
}a[maxn];

bool cmp(const node& a, const node &b) {
    if (a.xx == b.xx) return a.yy < b.yy;
    return a.xx < b.xx;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int n, m, r;
    while (cin >> n >> m >> r) {
        n += r;
        memset(dp, 0, sizeof(dp));
        rep (i, 0, m) cin >> a[i].xx >> a[i].yy >> a[i].c, a[i].yy += r;
        sort(a, a + m, cmp);
        dp[0] = 0;
        
        int ans = 0;
        rep (i, 1, m + 1) {
            if (a[i - 1].yy > n) continue;
            for (int j = i - 1; j >= 0; j--) {
                if (j == 0 || a[i - 1].xx >= a[j - 1].yy) dp[i] = max(dp[i], dp[j] + a[i - 1].c);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
