/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/12 22:28:12 2016
 *File Name*     : Lightoj1079.cpp
**Problem**:概率背包(经典)
有少于100个银行,每个银行有少于100元的钱,和被抓住的概率,要求你背抓住的概率小于等于v,你最多能获得多少钱.
**Analyse**:
> - 首先知道这个问题的方面不被抓到的概率更好算.
> - 然后对于每个银行自有抢或者不抢两种选择,比较像01背包.
> - 定义$$dp[i][j]$$:前$i$个银行,抢到$j$元钱,不被抓住的概率,$weight,cost$为第$i$个银行的钱数和抓住概率有转移:
$$dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] * (1 - cost)$$
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
const int maxn = 1e4 + 13;
double dp[maxn];


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    for (int cas = 1; cas <= T; cas++) {
        double v;
        int n;
        scanf("%lf", &v); sa(n);
        fill(dp, dp + maxn, -INF);
        dp[0] = 1.0;
        for (int i = 0; i < n; i++) {
            int cost; double weight;
            scanf("%d%lf", &cost, &weight);
            for (int i = maxn; i >= cost; i--) {
                dp[i] = max(dp[i - cost] * (1 - weight), dp[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < maxn; i++) {
            if (1.0 - dp[i]  <= v) ans = i;
        }
        printf("Case %d: %d\n", cas, ans);
    }
    
    return 0;
}
