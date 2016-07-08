/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/ 6 11:18:04 2016
**Problem**:
**Analyse**:
最小满足某种条件的最小区间，典型双指针应用.

**Get**:
双指针的模板写法，最外层循环不是右边界小于n，而是true因为之后还可能有更优的出现，里面先更新右边界，然后取值，然后更新左边界。

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
const int maxn = 1e6 + 13;
int A[maxn];


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~sa(n)) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            sa(A[i]);
            st.insert(A[i]);
        }
        int l = 0, r = 0, k = st.size();
        map<int ,int> mp;
        int ans = n;
        int cnt = 0;
        while (true) {
            while (cnt < k && r < n) {
                if (mp[A[r++]]++ == 0) cnt++;
            }
            if (cnt >= k) ans = min(ans, r - l);
            else break;
            if (--mp[A[l++]] == 0) cnt--; 
        }
        pri(ans);
    }

    return 0;
}
