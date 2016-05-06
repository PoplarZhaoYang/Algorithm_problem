/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/ 5 23:59:56 2016
 *File Name*     : jy.cpp
**Problem**: cf670d2    
**Analyse**:
经典的二分加贪心模型,我太高估了暴力的复杂度了....
先考虑最坏情况,就是只缺一个物品,而且这个物品缺1e9个,这里面明显需要一个$logk$的算法,
二分答案,然后贪心地去判断,最后要消耗小于k,贪心就满足,注意这里会爆ll,要提前跳出判断函数.
复杂度$nlogk$.

**二分闭区间的模板化写法**:
```
int l = 0, r = INF;
while (l < r) {
    int mid = (l + r + 1) / 2;
    if (ok) l = mid;
    else r = mid - 1;
}
```
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
ll A[maxn], B[maxn], n, k;

bool ok(ll t) {
    ll ret = 0;
    rep (i, 0, n) {
        if (B[i] <= A[i] * t) {
            ret += A[i] * t - B[i];
            if (k < ret) return false;
        }
    }
    return k >= ret;
}

int main(void)
{
#ifdef LOCAL
   freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while (cin >> n >> k) {
    ll suma = 0, ans = 0 ;
    rep (i, 0, n) cin >> A[i], suma += A[i];
    rep (i, 0, n) cin >> B[i];
    ll mins = INF;
    rep (i, 0, n) {
        mins = min(mins, B[i] / A[i]);
    }
    ans += mins;
    rep (i, 0, n) {
        B[i] -= mins * A[i];
    }
    ll r = k, l = 0;
    while (l < r) {
        ll mid = (r + l + 1) / 2;
        if (ok(mid)) {
            l = mid;
        } else r = mid - 1;
    }
    
    cout << ans + l << endl;
    }
    return 0;
}
