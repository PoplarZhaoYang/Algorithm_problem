/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 四  4/28 11:17:46 2016
 *File Name     : hdu3746.cpp
 *Problem:KMP的next数组
 
**题意**:往字符串两端添加字符,让它的循环节个数大于等于2.
**分析**:
首先明白nexts[i]表示的是p[i]之前的字符串中,最大的相同前缀后缀长度.
**注意**:这里的前缀后缀长度必须小于$i$的,要不然无法继续匹配,
> 例如:对于$aaa$它的相同前缀后缀的最大值必须小于3,尽管只直观上可以等于3,但是等于3,在kmp的时候无法前进了.

这里恰到好处的利用了一个字符串求其循环节的方法:就是把原串整个往右边移动,如果和原串完全匹配,那么移动
串左边的部分就是循环节.
然后kmp的基于动态规划,$O(n)$求得的next数组,就非常适合上面的方法,来求最小循环节(循环节越小,在需要补得时候就补得越少)大小.
可以发现长度为plen的字符串,它的最小循环节长度为$plen - nexts[plen]$,然后就可以根据这个值来进行补了.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;

char p[maxn];
int nexts[maxn], plen;

void getnexts(void) {
    int k = -1, j = 0;
    nexts[0] = -1;
    while (j <= plen) {
        if (k == -1 || p[k] == p[j]) {
            k++, j++;
            if (p[j] != p[k]) nexts[j] = k;
            else nexts[j] = nexts[k];
        } else k = nexts[k];
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    sa(T);
    while (T--) {
        scanf("%s", p);
        plen = strlen(p);
        getnexts();
        int x = plen - nexts[plen];
        if (x == plen) printf("%d\n", plen);
        else if (x == 1 || plen % x == 0) puts("0");
        else printf("%d\n", x - (plen % x));
    }
    
    return 0;
}
