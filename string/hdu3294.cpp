/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/29 09:56:27 2016
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 2e5 + 12;
char key, st[maxn], aim[maxn * 2];
int slen, ti, P[maxn * 2];

void pre()
{
    slen = (int)strlen(st);
    ti = 0;
    if (slen == 0) {aim[0] = '^', aim[1] = '$'; return;}
    aim[ti++] = '^';
    for (int i = 0; i < (int)slen; i++) aim[ti++] = '#', aim[ti++] = st[i];
    aim[ti++] = '#', aim[ti++] = '$';
}

pii manacher(void)
{
    pre();
    int C = 0, R = 0;
    for (int i =  1; i < ti - 1; i++) {
        int i_mirror = 2 * C - i;
        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
        while (aim[i + 1 + P[i]] == aim[i - 1 - P[i]]) P[i]++;
        if (i + P[i] > R) C = i, R = i + P[i];
    }
    int maxlen = 0, cen = 0;
    for (int i = 1; i < ti - 1; i++)
        if (P[i] > maxlen) maxlen = P[i], cen = i;
    return pii((cen - 1 - maxlen) / 2, (cen - 1 - maxlen) / 2 + maxlen - 1);
}



int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while (~scanf("%c%s", &key, st)) {
        getchar();
        pii point = manacher();
        if (point.xx == point.yy) puts("No solution!");
        else {
             printf("%d %d\n", point.xx, point.yy);
             rep (i, point.xx, point.yy + 1) {
                 printf("%c", 'a' + (st[i] - 'a'  - (key - 'a') + 26) % 26);
             }
             puts("");
        }
    }
    
    return 0;
}
