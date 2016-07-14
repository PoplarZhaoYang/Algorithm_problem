/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  7/14 15:04:28 2016
**Problem**:
**Analyse**:
神数学构造题。
$$f(x + 10^{18}) = f(x) + 1$$
$$[x, x + 10^{18} - 1] + 1= [x + 1, x + 10^{18}]$$
区间右移一位就加一，所以只需要知道$[0, 10^{18} - 1]$然后移动就可以了。
而有神公式：$$[0, 10^x] = 45 * x * 10 ^{x -1}$$
**Get**:

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
ll temp = (ll)1e17;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll a;
    cin >> a;
    ll k = 5 * (9 * (18 * (temp % a) % a) % a) % a;
    printf("%lld %lld\n", a - k, temp * 10 - 1 + a - k);
    return 0;
}
