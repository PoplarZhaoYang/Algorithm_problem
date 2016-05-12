/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/12 23:37:26 2016
 *File Name*     : .cpp
**Problem**:Lightoj 1104 概率dp
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
double dp[maxn];


int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    for (int cas = 1; cas <= T; cas++) {
        dp[0] = 1;
        int n; sa(n);
        
        for (int i = 1; i <= n + 1; i++) {
            dp[i] = dp[i - 1] * (n + 1.0 - i) / n;
            //pr(i), pl(dp[i]);
            if (dp[i] <= 0.5) {
                printf("Case %d: %d\n", cas, i - 1);
                break;
            }
        }
    }
    
    return 0;
}
