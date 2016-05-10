/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/10 17:31:05 2016
 *File Name*     : jy.cpp
**Problem**: Lightoj1038 概率dp + 因数分解
给你一个数$n(n <= 10^5)$,$n$的因数集合为$K(包括自身)$,每次从$K$中选择一个数$d$来除以$n$,让$n$变成
$n/d$,然后把$n/d$当作新的$n$来递归的操作,直到变成$1$,问你变成$1$的期望操作步数是多少?
**Analyse**:
> - 令$dp[i]$表示把$i$变成$1$的期望步数,$Z$表示$i$的因数个数,有方程:
$$dp[i] = \frac{1}{z} \sum_{j = 1...n\  且\ n \% i == 0}(dp[j] + 1) + \frac{1}{z} * (1 + dp[i])$$
方程化简为递推式子,然后dp即可.
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
double dp[maxn];
int buf[maxn], z;

double getsum(int x) 
{
    z = 0; 
    int i;
    for ( i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            buf[z++] = i;
            if (x / i != i) buf[z++] = x / i;
            
        }
    }
    double ret = 1.0 / (z + 1);
    int n = z;
    
    z += 2;
    for (int i = 0; i < n; i++) {
        //if (x == ) pr(buf[i]);
        ret += (dp[buf[i]] + 1) / (z - 1);
    }
    return ret;
}

void pre(void)
{
    dp[1] = 0;
    for (int i = 2; i < maxn; i++) {
        double sum = getsum(i);
        dp[i] = sum + 1.0 / (z - 1);
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    pre();
    int T; sa(T);
    for (int cas = 1; cas <= T; cas++) {
        int n; sa(n);
        printf("Case %d: %.15f\n", cas, dp[n]);
    }
    
    return 0;
}
