/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  5/11 17:09:58 2016
 *File Name*     : jy.cpp
**Problem**:Light oj 1248 概率dp
给你$n$个骰子,求其抛掷它,直到所有面都出现过的抛掷次数期望值.
**Analyse**:
- 定义$dp[i][j]$为抛掷$j$个骰子,已经出现过$i$个不同的数字的概率,有转移方程:
$$dp[i][j] = \frac{i}{j}\ * (1 + dp[i][j]) + \frac{j - i}{j} * (1 + dp[i + 1][j])$$
化简发现与$j$无关,就是一个一维dp...
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
int n;


int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    for (int cas = 1; cas <= T; cas++) {
        sa(n);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) dp[i] = double(n) / (n - i) + dp[i + 1];
        printf("Case %d: %.15f\n", cas, dp[0]);
    }
    
    return 0;
}
