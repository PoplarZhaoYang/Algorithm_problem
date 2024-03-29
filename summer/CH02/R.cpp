/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/ 6 12:44:52 2016
**Problem**:
**Analyse**:
定义：$dp[i][j][k]$表示石头剩下$i$个，布剩下$j$个，剪刀剩下$k$个的概率.
对于当前局面可以减少一个石头，减少一个布，减少一个剪刀，和平三种情况，平了我们还会继续来一轮。
所以干脆就只考虑三种情况，他们各自发生的概率是他们的加权比例.
减少一个石头:$i*k$种情况，减少一个剪刀$i*j$种情况，减少一个布$j*k$种情况。
减少石头的概率$$ \frac{i* k}{i *k+ k*j + j*k}$$
**Get**:
概率是当前局面累加到未知局面上。
期望是当前局面累加已知局面的期望天数的加权和 + 1。
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
double dp[102][103][104];


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int r, s, p;
    sa(r), sa(s), sa(p);
    dp[r][s][p] = 1;
    for (int i = r; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            for (int k = p; k >= 0; k--) {
                if (i * j + j * k + i * k) ;
                else continue;
                if (i) dp[i - 1][j][k] += dp[i][j][k] * i * k / (i * j + j * k + i * k ); 
                if (j) dp[i][j - 1][k] += dp[i][j][k] * i * j / (i * j + j * k + i * k );
                if (k) dp[i][j][k - 1] += dp[i][j][k] * k * j / (i * j + j * k + i * k ); 
            }
        }
    }
    double a = 0, b = 0, c = 0;
    for (int i = 1; i <= r; i++) a += dp[i][0][0];
    for (int i = 1; i <= s; i++) b += dp[0][i][0];
    for (int i = 1; i <= p; i++) c += dp[0][0][i];
    printf("%.14f %.14f %.14f\n", a, b, c);
    return 0;
}
