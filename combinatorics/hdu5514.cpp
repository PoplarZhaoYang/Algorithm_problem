/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 三  4/13 21:41:23 2016
 *File Name     : hdu5514.cpp
 *Problem:容斥原理 + dfs + 抵消减枝
 *Get:这道题从数论到组合数学,从dfs到剪枝是一道综合题.首先要知道完全剩余系的引理和引理扩展.k * gcd(a[i], m),就是k所能表示
 *出的所有整数,显然这里不同的数之间会有重合,就要通过dfs枚举所有子集合的方法来容斥,但是这样复杂度是2^n,显然要超时.这里有一个核心的
 *剪枝就是当当前lcm % gcds[pos] == 0时,表面这个元素选或者不选对lcm都没有影响,而选或者不选这两种情况之后的元素又都是有相同的情况
 *只是元素个数相差当前数的这一个,那么他们就会恰好抵消,可以想象这样会减掉很大一部分枝叶.
//get了一个新姿势
int find(m) {
    return lower_bound(v.begin(), v.end(), m) - v.begin();
}
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
ll a[maxn], gcds[maxn];
ll an, n, m;
ll ans = 0;
ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}


void dfs(int pos, ll lcm, int num) {
    if (lcm > m) return;
    if (pos == an) {
        if (num == 0) return;   //排除一个都不选的情况
        if (num & 1) {
            ans += m / lcm * (m / lcm - 1) * lcm / 2; 
        } else {
            ans -= m / lcm * (m / lcm - 1) * lcm / 2;
        }
    } else { 
        if (lcm % gcds[pos] == 0) return; //核心剪枝
        dfs(pos + 1, lcm, num);
        lcm = lcm * gcds[pos] / gcd(lcm, gcds[pos]);
        dfs(pos + 1, lcm, num + 1);
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int T, cnt = 1;;
    cin >> T;
    while (T--) {
        bool ok = false;
        ans = 0;
        cin >> n >> m;
        rep (i, 0, n) cin >> a[i], gcds[i] = gcd(a[i], m), gcds[i] == 1 ? ok = true : n = n * n / n;
        cout << "Case #" << cnt++ << ": ";
        if (ok) {
            cout << (m - 1) * m / 2  << endl;
        }
        else {
            sort(gcds, gcds + n);
            an = unique(gcds, gcds + n) - gcds;
            dfs(0, 1, 0);
            cout << ans << endl;
        }
    }
    return 0;
}
