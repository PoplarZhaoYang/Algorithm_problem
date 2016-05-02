/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 2 21:05:07 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
**Code**:
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
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
int pre[maxn];
int  n, ans, maxs;

bool judge(int x, int step) {
    int t = maxs - step;
    while (t--) {
        x = x + x;
    }
    return x < n;
}

void dfs(int cur, int cnt, int step)
{
    if (ans == maxs) return;
    if (step > maxs) return;
    if (cur == n) {
        ans = step;
        return;
    }
    if (judge(cur, step)) return;
    rep (i, 0, cnt) {
         pre[cnt] = cur + pre[i], dfs (cur + pre[i], cnt + 1, step + 1);
         pre[cnt] = cur - pre[i], dfs(cur - pre[i], cnt + 1, step + 1);
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    while (T--) {
        sa(n);
        pre[0] = 1;
        ans = -1;
        for (int i = 1; i <= 20; i++)
        {
            maxs = i;
            dfs(1, 1, 0);
            if (ans == maxs) break;
        }
        pri(ans);
    }
    return 0;
}
