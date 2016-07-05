/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/ 4 21:30:53 2016
**Problem**:
**Analyse**:
首先回去考虑正面算，但是发现情况太复杂，重合也太多。
从反面来考虑。
组合递推公式：$$C_n^m = C_{n-1}^m + C_{n-1}^{m-1}}$$
在没有限制的时候的全集$U=C_n^k$，然后令:A表示不选第一行，.....,D表示不选第一列。
求的结果就是:$$U - A \cup B \cup C \cup D$$
其中并集并不能直接求得，我们可以利用集合的容斥原理把它分解为各种交集的代数和。
用二进制枚举$15$中交集情况。（为什么不是16？这里0000为0不起作用)。

**Get**:
经典的集合容斥。概率和计数都容易出现的逆向思维。
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
const int mod = int(1e6) + 7, INF = 0x3f3f3f3f;
const int maxn = 400 + 13;
int C[maxn][maxn];

void getC(void) {
    for (int i = 0; i <= 20 * 20; i++) C[i][0] = 1, C[i][i] = 1;
    for (int i = 1; i <= 20 * 20; i++) {
        for (int j = i - 1; j >= 1; j--) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    getC();
    sa(T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m, k;
        sa(n), sa(m), sa(k);
        int ans = 0;
        for (int i = 1; i < 16; i++) {
            int r = n, c = m, cnt = 0;
            if (i & 1) {
                cnt++;
                r--;
            }
            if (i & 2) {
                cnt++;
                c--;
            }
            if (i & 4) {
                cnt++;
                r--;
            }
            if (i & 8) {
                cnt++;
                c--;
            }
            if (cnt % 2) ans = (C[r * c][k] + ans) % mod;
            else ans = (ans - C[r * c][k] + mod) % mod;
        }
        printf("Case %d: %d\n", cas, ((C[n * m][k] - ans) + mod) % mod);
    }
    return 0;
}
