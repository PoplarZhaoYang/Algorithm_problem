/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  7/15 00:53:16 2016
**Problem**: Codeforces Round #362 (Div. 2) C. Lorenzo Von Matterhorn （map离散化）
**Analyse**:
题意不赘述，根据题意可以构造出一个以$1$为根节点的二叉树。
然后我们用$dp[0][i]$表示以$i$为父亲节点，发出的连向它的左二子的边的长度。$dp[1][i]$表示以$i$为父亲节点，连到右儿子的长度。
这样对于$2 u v w$操作，我们都从当前节点$(u,w)$开始，不断地向上找它们的父亲节点，然后更新父亲节点连到当前节点的边长度:$dp[u%2][u/2]$和$dp[v%2][v/2]$。当它们向上到达同一个节点$f$的时候，$f$就是它们的最小公共
祖先$LCA$,更新到这里停止.
对于查寻操作同理。
然后由于节点数据范围很大，所以要用map来存这个dp数组，实现离散化。
这个题主要就是要知道树上两节点的最短路是它们各自到$LCA$距离的和即可。
**Get**:
博主map存图挂了大数据，因为没有把节点标号存为long long，需要读者在评论区安慰@_@。
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



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int q;
    ll ans, u, v, w;
    sa(q);
    map<int, map<ll, ll> > mp;
    while (q--) {
        int op; sa(op);
        if (op == 1) {
            sal(u), sal(v), sal(w);
            while (u != v) {
                if (v > u) {
                    int t = v % 2;
                    v /= 2;
                    mp[t][v] += w;
                } else {
                    int t = u % 2;
                    u /= 2;
                    mp[t][u] += w;
                }
            }
        } else {
            ans = 0;
            sal(u), sal(v);
            while (u != v) {
                if (v > u) {
                    int t = v % 2;
                    v /= 2;
                    ans +=  mp[t][v];
                } else {
                    int t = u % 2;
                    u /= 2;
                    ans += mp[t][u];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
