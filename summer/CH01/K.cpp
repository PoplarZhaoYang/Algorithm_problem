/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/ 4 13:59:02 2016
**Problem**:
**Analyse**:
很明显这个题是固定的，所以需要预先打表。
**Get**:
找规律递推就可以了。
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
ll dp[maxn * 10];



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    dp[3] = 0;
    for (int i = 4; i <= 1000000 ; i++) {
        dp[i] = dp[i - 1];
        ll k = i - 3;
        ll t = (k + 1) / 2;
        dp[i] += k * t + t - t * t;
    }
    while (sa(n), n > 2) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
