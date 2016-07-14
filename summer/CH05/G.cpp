/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/13 17:17:20 2016
**Problem**:
**Analyse**:
先二分中位数，然后用二分去判断这个中位数是不是可以成立，双重二分。
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
const int maxn = 1e5 + 13;
int A[maxn];
int n;
ll k;

bool judge(int mid) {
    ll low = 0;
    for (int i = 0; i < n; i++) {
        int t = (lower_bound(A + i, A + n, mid + A[i]) - (A + i));
        t--;
        //pr(i), pl(t);
        low += t;
    }
    return low < k;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (~sa(n)) {
        for (int i = 0; i < n; i++) sa(A[i]);
        sort(A, A + n);
        ll l = 0, r = int(2e9);
        k = ((ll(n) * (n - 1)) / 2 + 1) / 2;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
        //    pr(l), pr(r), pl(mid);
            if (judge(mid)) {
                l = mid;
            } else r  = mid - 1;
        }
        printf("%lld\n", l);
    }
    
    return 0;
}
