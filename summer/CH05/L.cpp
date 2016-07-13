/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/13 16:36:15 2016
**Problem**:
**Analyse**:
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
const int maxn = 10;
int n, m, cur;
ll d[2][1 << maxn];

void update(int a, int b) {
    if (b & (1 << m)) d[cur][b ^ (1 << m)] += d[1 - cur][a];
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m)) {
        if (n < m) swap(n, m);
        memset(d, 0, sizeof(d));
        d[0][(1 << m) - 1] = 1;
        cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cur ^= 1;
                memset(d[cur], 0, sizeof(d[cur]));
                for (int k = 0; k < (1 << m); k++) {
                    update(k, k << 1);
                    if (i && !(k & (1 << (m - 1)))) update(k, (k << 1) ^ 1 ^ (1 << m));
                    if (j && !(k & 1)) update(k, (k << 1) ^ 3); 
                }
                
            }
        }
        printf("%lld\n", d[cur][(1 << m) - 1]);
    }
    return 0;
}
