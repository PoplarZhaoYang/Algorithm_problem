/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 三  4/27 09:43:05 2016
 *File Name     : jy.cpp
 *Problem:
 *Get:
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 1e4 + 12;


char s[maxn * 2], T[maxn * 2];
int ti, P[maxn * 2];

// 将S转换成T 
// 比如，S = "abba", T = "^#a#b#b#a#$"
// ^和$符号用来表示开始和结束，并且避免边界检查。
void preProcess()
{
    int n = strlen(s);
    ti = 0;
    if (n == 0) {T[0] = '^', T[1] = '$'; return;}
    T[ti++] = '^';
    for (int i = 0; i < n; i++)
        T[ti++] = '#', T[ti++] = s[i];
    T[ti++] = '#', T[ti++] = '$';
}

int  manacher()
{
    preProcess();
    int n = ti;
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i; // 等于i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // 尝试扩展中心为i的回文
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
        P[i]++;

    // 如果中心为i的回文超越了R，根据已扩展的回文来调整中心
    if (i + P[i] > R) {
        C = i;
        R = i + P[i];
        }
    }

    // 找出P中的最大值
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    //最长回文子串的起点
    int stp = (centerIndex - 1 - maxLen) / 2;
    //返回最长回文子串,其长度为maxLen
    return maxLen;
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while (~scanf("%s", s)){
        printf("%d\n", manacher());
    }
    return 0;
}
