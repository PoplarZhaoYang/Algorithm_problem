/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  5/13 11:48:36 2016
 *File Name*     : jy.cpp
**Problem**: soj4510 dp优化 
**Analyse**:
当然很容易想到$dp[350][40][40][40][40]$的dp,但是转移复杂度,过高,然后发现这五个参数知道其中$4$个,
可以求出另外$1$个,当然我们选择去掉$350$那一个.
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
#define short unsigned short int
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
short  dp[41][41][41][41];
short  T, n, m, a[5], A[355];


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    scanf("%hd", &T);
    while (T--) {
        scanf("%hd", &n);
        scanf("%hd", &m);
        memset(a, 0, sizeof(a));
        A[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%hd", &A[i]); 
        for (int i = 0; i < m; i++) {
            int x; sa(x);
            a[x]++;
        }
        for (int i = 0; i <= a[4]; i++)
            for (int j = 0; j <= a[3]; j++) 
                for (int k = 0; k <= a[2]; k++) 
                    for (int l = 0; l <= a[1]; l++)
                        dp[i][j][k][l] = 0;
        dp[0][0][0][0] = 0;
        for (int i = 0; i <= a[4]; i++)
            for (int j = 0; j <= a[3]; j++) 
                for (int k = 0; k <= a[2]; k++) 
                    for (int l = 0; l <= a[1]; l++) {
                        short temp = 0;
                        if (i > 0) temp = max(temp, dp[i - 1][j][k][l]);
                        if (j > 0) temp = max(temp, dp[i][j - 1][k][l]);
                        if (k > 0) temp = max(temp, dp[i][j][k - 1][l]);
                        if (l > 0) temp = max(temp, dp[i][j][k][l - 1]);
                        dp[i][j][k][l] = temp + A[i * 4 + j * 3 + k * 2 + l + 1];
                    }
        printf("%u\n", dp[a[4]][a[3]][a[2]][a[1]]);
    }
    return 0;
}
