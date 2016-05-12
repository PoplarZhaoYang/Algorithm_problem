/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/12 13:16:29 2016
 *File Name*     : jy.cpp
**Problem**:Codeforces Round #352 (Div. 2) D 二分贪心两头 + 细节
**Analyse**:
- 好的思维就是把左右端点分开来考虑.
- 显然对左端点和右端点,都来二分答案贪心判断的求解,找到k步操作它们各自能到达的位置.
- 有一个细节就是k很大的时候,左右端点会交叉,这时候我们就要判断在相交点是否可以差值为0了....
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
const int maxn = 5e5 + 13;
int A[maxn], kk, n, ans;
ll sum;

ll judger(int mid) 
{
    ll ret = 0;
    for (int i = 0; i < n; i++) 
        if (A[i] > mid) ret += A[i] - mid;
    return ret;
}

ll judgel(int mid)
{
    ll t = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < mid) t += mid - A[i];
    }
    return t;
}



int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while (~scanf("%d%d", &n, &kk)) {
        ll k = kk;
        sum = 0;
        for (int i = 0; i < n; i++) sa(A[i]), sum += A[i]; 
        int left = 1e9, right = 0;
        int l = 0, r = int(1e9);
        while (true) {
            int mid = (l + r + 1) / 2;
            if (mid == int(1e9)) break;
            ll x = judgel(mid), y = judgel(mid + 1);
            if (x <= k && y > k) {
                left = mid;
                break;
            } else if (x > k) r = mid - 1;
            else l = mid + 1;
        }
        l = 0, r = int(1e9);
        while (true) {
            int mid = (l + r + 1) / 2;
            if (mid == 0) break;
            //pl(mid);
            ll x = judger(mid), y = judger(mid - 1);
            if ((x <= k && y > k)) {
                right = mid;
                break;
            } else if (x > k) l = mid + 1;
            else r = mid - 1;
        }
        pri(max((int)bool(sum % n), right - left));
    }
    
    return 0;
}
