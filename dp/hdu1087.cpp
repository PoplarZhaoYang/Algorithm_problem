/************************************************
 *Author        :jibancanyang
 *Created Time  :日  4/ 3 21:23:36 2016
 *File Name     :hdu1087.cpp
 *题目类型:	LIS变形
 *很简单的题,但是开始没有把转移方程想好就写,导致了浪费时间...
 *定义:dp[i]为以i结尾的最好路径的最大值,然后由它前面的数转移过来就好了.
*************************************************/

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
#define pr(x) cout << #x << ": " << x << " "
#define prln(x) cout << #x << ": " << x << endl
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
int a[maxn / 100];
ll dp[maxn / 100];
int n;


int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	//	cin.sync_with_stdio(false);
	while (sa(n), n) {
		rep (i, 0, n) {
			sa(a[i]), dp[i] = 0;
		}
		dp[0] = a[0];
		rep (i, 1, n) {
			for (int j = i - 1; j >= 0; j--) {
				dp[i] = max(dp[i], a[i] > a[j] ? dp[j] + a[i] : a[i]);
			}
		}
		ll ans = 0;
		rep (i, 0, n) {
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
    return 0;
}
