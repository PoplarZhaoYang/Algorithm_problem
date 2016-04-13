/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 二  4/12 23:15:53 2016
 *File Name     : hdu2089.cpp
 *题目类型:简单dp
 *感悟:dp[i]为小于等于i的满足条件数的个数,可以o(n)的更新,但是这个题的标准做法是数位dp.
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
int dp[maxn * 10];
bool ok[maxn * 10];
bool judge(int x) {
    if(ok[x / 10]) {
        if ( !(x / 10 % 10 == 6 && x % 10 == 2) && x % 10 != 4) {
            return ok[x] = true;
        } else return ok[x] = false;
    }
    return ok[x] = false;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    dp[0] = 1, ok[0] = 1;
    for (int i = 1; i <= maxn * 10; i++) {
        judge(i);
        dp[i] = dp[i - 1] + ok[i];
    }
    int n, m;
    while (cin >> n >> m, n *n + m *m) {
        cout << dp[m] - (n == 0 ? 0 : dp[n - 1]) << endl;
    }
    return 0;
}
