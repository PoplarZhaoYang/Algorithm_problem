/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/ 5 09:56:23 2016
**Problem**:
**Analyse**:
对于每个点，二分它在哪个区域内。
二分的时候需要利用到判断点在线的那一侧。
这里要用到叉积（相对于点积）。
$$(x_1, y_1) X (x_2, y_2) = x_1 * y_2 - x_2 * y_1$$
$$AXB= -BXA=|A|*|B|*sin\theta= S_{菱形}$$
叉积正负满足右手旋转定理。

已知线段AB,和点C判断同异侧用ABXAC的正负来判断即可。

**Get**:
向量不具有位置性，当抽象出来作用极大。
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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e3 + 13;
int n, m, a, b, c, d;
struct vec{
    int x, y;
    vec(){}
    vec(int X, int Y):x(X), y(Y){}
};

vec side[maxn], dot[maxn];
int ans[maxn];

int xj(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

int judge(int mid, int x, int y) {
    vec l = side[mid];
    vec r = side[mid + 1];
    int ansl = xj(vec(l.y - l.x, d - b), vec(x - l.x, y - b)), ansr = xj(vec(r.y - r.x, d - b), vec(x - r.x, y - b));
    if (ansl < 0 && ansr < 0) return -1;
    if (ansl > 0 && ansr < 0) return 0; 
    if (ansr > 0 && ansl > 0) return 1;
    return 0;
}

bool cmp(vec &a, vec &b) {
    return min(a.x, a.y) < min(b.x, b.y);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (true) {
        memset(ans, 0, sizeof(ans));
        sa(n);
        if (!n) break;
        sa(m), sa(a), sa(b), sa(c), sa(d);
        side[0] = vec(a, a);
        for (int i = 1; i <= n; i++) {
            int x, y;
            sa(x), sa(y);
            side[i].x = x;
            side[i].y = y;
        }
        side[++n] = vec(c, c);
        sort(side, side + n + 1, cmp);
        while (m--) {
            int x, y; sa(x), sa(y);
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                int cur = judge(mid, x, y);
                if (cur > 0) {
                    l = mid + 1;
                } else if (cur < 0) {
                    r = mid - 1;
                } else {
                    l = mid;
                    break;
                }
            }
            ans[l]++;
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
           if (ans[i]) mp[ans[i]]++;
        }
        puts("Box");
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            printf("%d: %d\n", it -> first, it -> second);
        }
    }
    return 0;
}
