/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/ 6 09:46:52 2016
**Problem**:
**Analyse**:
这是一道颇容易考虑漏的贪心题。
这里有两种策略都是较为优秀的：
1. 两个最小的过去，最小的回来，两个最大的过去，次小的回来。
2. 最小的带最大的过去，最小的回来，最小的带次大的过去，最小的回来。
这种两种策略之后，局面都变成了一个类似最初的样子,陷入一个递归。
我们每次局面开始都去判断这两种策略哪个更好就可以了。
**Get**:
贪心很容易分析错，要完全正确得大概证明一下。
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
int A[1111];


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while (T--) {
        int n; sa(n);
        if (!n) {
            pri(0);
            continue;
        }
        for (int i = 0; i < n; i++) sa(A[i]);
        sort(A, A + n);
        int a = A[0], b =A[1];
        if (n == 1) pri(a);
        else if (n == 2)  pri(max(a, b));
        else {
            int k = n - 2, ans = 0;
            while (k > 1) {
                if (A[k] + a > 2 * b)
                ans += a + 2 * b + A[k + 1];
                else ans += A[k] + A[k + 1] + 2 * a; 
                k -= 2;
            }
            if (k) {
                ans += a + b + A[k + 1];
            } else ans += max(a, b);
            pri(ans);
        }
    }
    
    return 0;
}
