/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/15 23:43:25 2016
 *File Name     : hdu3555 .cpp
 *Problem:典型数位dp
 *Get:典型模型,坑点就是最后枚举数字的时候,前面一旦出现过了49,后面的每一位数字都要和它比它小以为的不含49的数
 *组成一个含49的,这算是大体无后效性,但是有一种特殊情况的补救.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
int T;
ll n, dp[21][3];



int main(void)
{
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    dp[0][0] = 1;
    dp[1][0] = 10, dp[1][1] = 1, dp[1][2] = 0;
    for (int i = 2; i <= 20; i++) {
        dp[i][0] = 10 * dp[i - 1][0] - dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][2] * 10;
    }
    cin >> T;
    while (T--) {
        cin >> n;
        n++;
        string x = to_string(n);
        int m = x.size();
        ll ans = 0;
        bool flag = false;
        for (int j = m; j >= 1; j--) {
            int t = x[m - j] - '0';
            ans += dp[j - 1][2] * t ;
            if (flag) ans += t * dp[j - 1][0];
            else if (t > 4) ans += dp[j - 1][1];//注意这里有个else,是为了不要和上一条语句重复加了.
            if (t == 9 && j != m && x[m - j - 1] == '4') flag = true;
            
        }
        cout << ans << endl;
    }
    return 0;
}
 *Get:
