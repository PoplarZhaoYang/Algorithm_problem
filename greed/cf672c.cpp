/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/12 00:59:00 2016
 *File Name*     : jy.cpp
 **Problem**: 几何 + 贪心
 **Analyse**:
 这个题就是贪心的思路,但是思维容易有缺陷,少考虑一个人不走或者误写为两个人都不走的情况.
 思路一定要完备了再动手写代码,而且思路要写在纸上!
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
typedef long double ull;
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
ull A[maxn], B[maxn], T[maxn];

ull getd(ull ax, ull ay, ull bx, ull by) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ull ax, bx, ay, by, tx, ty;
    while (cin >> ax >> ay >> bx >> by >> tx >> ty) {
        int n;
        cin >> n;
        ull ans = 0;
        cout.precision(15);
        for (int i = 0; i < n; i++) {
            ull x, y;
            cin >> x >> y;
            T[i] = getd(tx, ty, x, y);
            ans += T[i] * 2;
            A[i] = getd(ax, ay, x, y);
            B[i] = getd(bx, by, x, y);
        }
        ull ag = 0, bg = 0;
        int la = -1, lb = -2;
        for (int i = 0; i < n; i++) {
            if (T[i] - A[i] > ag) {
                la = i;
                ag = T[i] - A[i];
            }
            if (T[i] - B[i] > bg) {
                lb = i;
                bg = T[i] - B[i];
            }
        }
        if (ag == 0 && bg == 0) {
            ag = -1e20;
            for (int i = 0; i < n; i++) {
                ag = max(ag, max(T[i] - A[i], T[i] - B[i]));
            }
            cout << ans - ag << endl;
        } else 
            if (la != lb) {
                cout << ans - ag - bg << endl;
            } else {
                ull ok = 0;

                ull bgg = 0;
                for (int i = 0; i < n; i++) {
                    if (i != la && T[i] - B[i] > bgg) {
                    bgg = T[i] - B[i];
                }
            }
            ok = ag + bgg;

            bgg = 0;
            for (int i = 0; i < n; i++) {
                if (i != la && T[i] - A[i] > bgg) {
                    bgg = T[i] - A[i];
                }
            }
            ok = max(ok, bg + bgg);
            cout << ans - ok << endl;
        }
    }
    return 0;
}
