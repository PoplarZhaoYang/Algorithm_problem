/************************************************
 *Author        :jibancanyang
 *Created Time  :一  4/ 4 01:43:38 2016
 *题目类型:
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;

int dp[maxn / 100], a[maxn / 100];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	cin.sync_with_stdio(false);
	int n;    
	while (cin >> n) {
		rep (i, 0, n) cin >> a[i], dp[i] = 1;
		rep (i, 1, n) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int ans = 0;
		rep (i, 0, n) ans = max(ans, dp[i]);
		cout << ans << endl;
	}
    return 0;
}
