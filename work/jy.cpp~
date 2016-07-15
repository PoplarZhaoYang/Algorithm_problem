/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  7/15 02:10:55 2016
**Problem**:
**Analyse**: Codeforces Round #362 (Div. 2) D. Puzzles(概率dp)
**Get**:
这题就是一个简单的概率dp，只要理解了是当前节点的所有子节点的随机排列作为范围顺序。
容易知道，对于一个随机排列，一个数在另一个数前面的概率是$1/2$，那么这个题就很期望了。
先一次dfs预处理出所有的节点的子树包含的节点个数。
然后dfs来处理dp。
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
vi G[maxn];

int nodes[maxn];
int par[maxn];

int dfsnodes(int cur) {
    int ret = 0;
    for (int i = 0; i < (int)G[cur].size(); i++) {
        ret += dfsnodes(G[cur][i]) + 1;
    }
    return nodes[cur] = ret;
}

double dp[maxn];

void dfs(int cur) {
    if (cur != 1) 
        dp[cur] = dp[par[cur]] + 1 + (nodes[par[cur]] - nodes[cur] - 1) / 2.0;
    
    for (int i = 0; i < (int)G[cur].size(); i++) {
        dfs(G[cur][i]); 
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    for (int i = 2; i <= n; i++) {
        int x; sa(x);
        G[x].push_back(i);
        par[i] = x;
    }
    dfsnodes(1);
    dp[1] = 1.0;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        printf("%.10f ", dp[i]);
    }
    puts("");
    return 0;
}
