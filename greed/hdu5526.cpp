/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 四  4/14 11:35:23 2016
 *File Name     : jy.cpp
 *Problem: 贪心
 *Get:如果前面的数总是能整除后面的数,那么就是直接贪心,但是这里20, 50和200, 500比较特殊,他们不一定一定可以整除,但是考虑到20整除2倍50,200
 *整除2倍500,所以他们最多少取一个,我们对所有数都考虑取最多个或者比最多个少取一个即可.
 *贪心一定要完全考虑了问题的完备性再动手.....要不然就是白费时间.
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
ll a[] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
ll b[10], c[10];
ll T, p, sum, money;
ll ans;

void dfs(int pos, ll cost, ll num) {
    if (cost < 0) return;
    if (cost == 0)  ans = min(ans, num);
    if (pos == -1) return;

    int n = min(cost / a[pos], b[pos]);

    for (int i = n; i >= n - 1 && i >= 0; i--) 
        dfs(pos - 1, cost - a[pos] * i, num + i);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    //cin.sync_with_stdio(false);
    cin >> T;
    while (T--) {
        sum = money = 0;
        ans = INF;
        cin >> p;
        rep (i, 0, 10) cin >> b[i], sum += a[i] * b[i], money += b[i];

        dfs(9, sum - p, 0);
        if (ans == INF) puts("-1");
        else cout << money - ans << endl;
    }
    return 0;
}
