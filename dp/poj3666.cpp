/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/ 8 22:12:57 2016
 *File Name     : poj3666.cpp
 *题目类型:离散化dp
 *感悟:就是普通的dp,只是由于最后的序列至少有一个原序列终端数,所以把结尾离散化了.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 2e3 + 12;
ll dp[maxn][maxn], a[maxn], b[maxn];
ll abss(ll x) {
    return x < 0 ? -x : x;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        rep (i, 0, n) cin >> a[i], b[i] = a[i];
        sort(b, b + n);
        rep (i, 0, n) dp[0][i] = abss(b[i] - a[0]);
        ll ans = ll(1e18); 
        for (int i = 1; i < n; i++) {
            ll last = ll(1e18);
            for (int j = 0; j < n; j++) {
                last = min(last, dp[i - 1][j]);
                dp[i][j] = last + abss(a[i] - b[j]);
                if (i == n - 1) ans = min(ans, dp[i][j]); 
            }
        }
        cout << (n == 1 ? 0 : ans) << endl;
    }
    return 0;
}
