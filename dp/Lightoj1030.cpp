/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 9 20:38:59 2016
 *File Name*     : .cpp
**Problem**:Lightoj 1030 概率dp
**Analyse**:
dp[i]为i开始走到结尾的价值,
那么dp[i]是从后面的6个转移过来的.
这样我们就倒着递推就好了(后面的要先算好).
注意后面不足六个的时候的处理情况.
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
int T, n;
double dp[111];
int a[111];



int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> T;
    int cas = 1;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dp[n] = (double)a[n];
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = a[i];
            int m = min(n, i + 6);
            for (int j = i + 1; j <= m; j++) {
                dp[i] += dp[j] / (m - i) ;
            }
        }
        cout << "Case " <<  cas++ << ": " ;
        printf("%.14f\n", dp[1]);
    }
    
    return 0;
}
