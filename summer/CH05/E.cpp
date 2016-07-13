/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/13 09:56:34 2016
**Problem**:
**Analyse**:
就是二分+贪心判断，强行加eps不要。。
**Get**:
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
const int maxn = 1e4 + 13;
int n, f;
int pie[maxn];
double pi = acos(-1), eps = 1e-7;

bool judge(double mid) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int te = double(pie[i]) * pie[i] * pi / mid;
        sum += te;
    }
    return sum >= f;
}


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; sa(T);
    while (T--) {
        sa(n), sa(f);
        f++;
        for (int i = 0; i < n; i++) sa(pie[i]);
        double l = 0, r = 1e10;
        for (int i = 0; i < 250; i++) {
            double mid = (l + r) / 2;
            if (judge(mid)) {
                l = mid + eps;
            } else r = mid - eps;
        }
        printf("%.4f\n", l);
    }
    
    return 0;
}
