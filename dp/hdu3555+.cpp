/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/15 23:43:25 2016
 *File Name     : hdu3555 .cpp
 *Problem:典型数位dp
 *Get:上次切这个题用的是水过去的方法,这次用模板化的dfs写了下,其方法本质就是一位一位的增加数字.
 *并且设置了一个limit的状态记录,来记录前面的数是否是边界,如果是边界那么当前位只能最大是bit[i],而不能
 *0 ~ 9的随便取了.然后注意的是这里是统计的到0的情况.
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
ll n, dp[25][2];
int bits[25];
#define limit asdf
ll dfs(int len, bool four, bool limit) {
    if (len == 0) return 1;
    if (!limit && dp[len][four] != -1) return dp[len][four];
    int m = limit ? bits[len] : 9;
    ll ret = 0;
    for (int i = 0; i <= m; i++) {
        if (four && i == 9) continue; //避免生成49
        ret += dfs(len - 1, i == 4, limit && i == m);
    }
    //pr(len), pr(four), pr(limit), pl(ret); 
    if (!limit) dp[len][four] = ret;
    return ret;
}

ll solve(ll n) {
    ll key = n, t = 1;
    while (key) {
        bits[t++] = key % 10;
        key /= 10;
    }
    return dfs(t - 1, false, true);
}


int main(void)
{
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    cin >> T;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        cin >> n;
        cout << n - solve(n)  + 1 << endl;//+1是因为00000
    }
    return 0;
}
