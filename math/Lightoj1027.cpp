/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  5/ 6 23:58:46 2016
 *File Name*     : Lightoj 1027.cpp
**Problem**: 概率期望
**Analyse**:
非常经典的带有递归实现,的方程期望式子.
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

int gcd(int a, int b) {
    if (!b) return a;
    else return gcd(b, a % b);
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    sa(T);
    for (int cas = 1; cas <= T; cas++) {
        int n, f = 0, z = 0, fp = 0, zp = 0;
        sa(n);
        for (int i = 0; i < n; i++) {
            int x;
            sa(x);
            if (x >= 0) z++, zp += x;
            else f++, fp += -x;
        }
        printf("Case %d: ", cas);
        if (z == 0) puts("inf");
        else {
            int fz = fp + zp;
            int g = gcd(fz, z);
            printf("%d/%d\n", fz / g, z / g);
        }
    }

    
    return 0;
}
