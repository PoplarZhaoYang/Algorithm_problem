/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/19 10:29:09 2016
**Problem**:
**Analyse**:
这题就是通过一个简单的概率dp退出递推公式，然后观察数列，找出通项公式。
然后对于大指数的情况用费马小定理减小指数，之后快速幂。
最后取余除法用取余逆元来做。
$10^9 + 7$关于$3的逆元恰好是$\frac{10^9 + 8}{3}$
**Get**:
数论啊！
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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;
int n;
ll A[maxn];

ll fastmod(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1ll) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    ll y = 1;
    bool ok = true;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) ok = false;
        A[i] %= mod - 1;
        y = y * A[i] % (mod - 1);
    }
    y = (y - 1 + mod - 1) % (mod - 1);
    ll fm = fastmod(2, y);
    ll fz = (fm + (ok ? -1 : 1)) * (mod + 1) / 3 % mod;
    cout << fz << "/" << fm << endl;
    return 0;
}
