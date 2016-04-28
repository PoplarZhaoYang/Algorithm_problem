/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : Thu 28 Apr 2016 01:21:08 PM CST
 *File Name     : hdu1711cpp
 *Problem :水kmp
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e6 + 12;

int s[maxn], p[maxn ];
int plen, slen, nexts[maxn];

void getnexts(void)
{
    nexts[0] = -1;
    int k = -1, j = 0;
    while (j < plen - 1) {
        if (k == -1 || p[k] == p[j]) {
            k++; j++;
            if (p[k] != p[j]) nexts[j] = k;
            else nexts[j] = nexts[k];
        } else k = nexts[k];
    }
}

int kmp(void)
{
    int i = 0, j = 0;
    while (i < slen && j < plen) {
        if (j == -1 || s[i] == p[j]) i++, j++;
        else j = nexts[j];
    }
    if (j == plen) return i - j + 1;
    else return -1;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int T;
    sa(T);
    while (T--) {
        sa(slen), sa(plen);
        for (int i = 0; i < slen; i++) sa(s[i]);
        rep (i, 0, plen) sa(p[i]);
        getnexts();
        printf("%d\n", kmp());
    }
    return 0;
}
