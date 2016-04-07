/************************************************
 *Author        :jibancanyang
 *Created Time  :二  4/ 5 09:33:33 2016
1jy.cpp
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 2e3 + 12;
int a[maxn];
int dp[maxn][maxn];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int n;
    while (~sa(n)) {
        rep (i, 1, n + 1) sa(a[i]), dp[i][i] = a[i] * n;
        for (int i = n - 1; i > 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                int t = n - j + i; 
                dp[i][j] = max(dp[i][j - 1] + t * a[j], dp[i + 1][j] + t * a[i]);
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
