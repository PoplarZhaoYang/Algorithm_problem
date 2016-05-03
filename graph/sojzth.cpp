/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/ 3 13:31:09 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
char ta[8][6];
char pre[44];
int n, cnt, len[8], ans;
char v[] ={'A', 'C', 'G', 'T'};
int cur[8];

void dfs(int x) 
{
    if (ans) return;

    if (x == 0) {
        rep (i, 0, n) {
            if (cur[i] != len[i]) return;
        }
        ans = true;
        return;
    }

    int maxs = 0, mins = 0;
    rep (i, 0, n) {
        mins += len[i] - cur[i];
        maxs = max(len[i] - cur[i], maxs);
    }
    if (maxs > x) return;
    if (mins <= x) {
        ans = true;
        return;
    }
    rep (i, 0, 4) {
        bool ok = false;
        int temp[8];
        memcpy(temp, cur, sizeof(cur));

        rep (j, 0, n) if (ta[j][cur[j]] == v[i]) cur[j]++, ok = true;
        pre[cnt++] = v[i];

        if (ok) dfs(x - 1);

        memcpy(cur, temp, sizeof(cur));
        cnt--;
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
        sa(n); ans = false;
        rep (i, 0, n) {
            scanf("%s", ta[i]);
            len[i] = strlen(ta[i]);
        }
        for (int i = 1; i <= 40; i++) {
            memset(cur, 0, sizeof(cur));
            cnt = 0;
            dfs(i);
            if (ans) {
                pri(i);
                break;
            }
        }
    }
    return 0;
}
