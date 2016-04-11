/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 一  4/11 11:34:07 2016
 *File Name     : hdu1114.cpp
 *题目类型:恰好装满的完全背包
 *感悟:已经不适合做这种水题了.....
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
int dp[maxn], p[555], w[555], n, v;


int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> v;
        v = v - n;
        cin >> n;
        dp[0] = 0;
        rep(i, 1, v + 2) dp[i] = INF;
        rep (i, 0, n) {
            int x, y;
            cin >> x >> y;
            for (int j = y; j <= v; j++) {
                dp[j] = min(dp[j], dp[j - y] + x);
            }
        }
        if (dp[v] == INF) cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[v] << "." << endl;

    }
    return 0;
}
