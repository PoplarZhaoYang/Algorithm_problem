/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 六  7/16 16:35:54 2016
**Problem**:
**Analyse**:
调和级数的收敛速度，约为$logn$的速度，这才有了素数筛法的复杂度。
这题也利用了这个性质。
定义$dp[i]$，表示成绩小于等于$i$的数的个数，然后用代码中的方法去构造出这个dp。
这个不同于一般的转移，感觉非常技巧。
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
const int maxn = 3e6 + 13;
typedef long long ll;
ll n, A[maxn], cnt[maxn], dp[maxn];


int main()
{
#ifdef LOCAL 
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sal(n);
    for (int i = 0; i < n; i++)
        sal(A[i]), cnt[A[i]]++;
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; i * j < maxn; j++) {
            dp[i * j] += cnt[i] * (cnt[j] - (i == j)); 
        }
        dp[i] += dp[i - 1];
    }
    int m, x;
    sa(m);
    while (m--) {
        sa(x);
        printf("%lld\n", n* (n - 1) - dp[x - 1]);
    }
    return 0;
}
