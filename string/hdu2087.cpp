/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : Thu 28 Apr 2016 01:21:08 PM CST
 *File Name     :hdu2087.cpp
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e3 + 12;
char str[maxn], p[maxn];
int nexts[maxn], n, m;

void getnexts(void)
{
    nexts[0] = -1;
    int k = -1, j = 0;
    while (j < m - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++k; ++j;
            if (p[j] != p[k]) nexts[j] = k;
            else nexts[j] = nexts[k];
        } else k = nexts[k];
    }
}

int kmp(void)
{
    int i = 0, j = 0, ans = 0;
    while (i < n) {
        if (j == -1 || str[i] == p[j]) i++, j++;
        else j = nexts[j];
        if (j == m) {
            ans++;
            j = 0;
        }
    }
    return ans;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    while (true) {
        scanf("%s", str), n = strlen(str);
        if (n == 1 && str[0] == '#') break;
        scanf("%s", p), m = strlen(p);
        getnexts();
        printf("%d\n", kmp());
    }
    return 0;
}
