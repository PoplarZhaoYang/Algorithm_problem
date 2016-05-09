/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 9 08:52:24 2016
 *File Name*     : hdu4513.cpp
**Problem**:
定义回文且单增为完美队形,求完美队形的最大长度.
**Analyse**:
- 用manancher处理处,P数组.
- 用dp求出以i结尾的单调递增序列长度.
- 换算取最小值
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
//Manacher算法实现模板

//开两倍多
int str[maxn], aim[maxn * 2];
int len, ti, P[maxn * 2]; //ti表示转换后的串的长度, P[i]表示以i为中心的回文子串的长度.
int hw[maxn], dp[maxn];

// 将str转换成aim
// 比如，str = "abba", aim = "^#a#b#b#a#$"
// ^和$符号用来表示开始和结束，并且避免边界检查。
void pre()
{
    ti = 0;
    if (len == 0) {aim[0] = -1, aim[1] = -2; return;} //空串
    aim[ti++] = -1;
    for (int i = 0; i < len; i++) aim[ti++] = 0, aim[ti++] = str[i];
    aim[ti++] = 0, aim[ti++] = -2;
}

void  manacher()
{
    pre();
    int C = 0, R = 0;
    for (int i = 1; i < ti - 1; i++) {
        int i_mirror = 2 * C - i; 
        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
        while (aim[i + 1 + P[i]] == aim[i - 1 - P[i]]) P[i]++;
        if (i + P[i] > R) C = i, R = i + P[i];
    }
}


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    while (T--) {
        sa(len);
        for (int i = 0; i < len; i++) sa(str[i]);
        manacher();
        dp[0] = 1;
        for (int i = 1; i < len; i++) 
            str[i] >= str[i - 1] ? dp[i] = dp[i - 1] + 1 : dp[i] = 1;
        int ans = 1;
        for (int i = 1; i < ti - 1; i++) {
            int ok = 0;
            if (i % 2) ok = 1;
            ans = max(ans, min(dp[(i - 2) / 2] * 2 + ok, P[i]));
        }
        pri(ans);
    }
    
    return 0;
}
