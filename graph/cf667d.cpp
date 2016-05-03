/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/ 3 01:30:31 2016
 *File Name*     : cf667d.cpp
**Problem**:给你一个边长为1的有向图,从一个点到另一个点你只能走最短路,找出四个点的链,让这条链最长.
**Analyse**:首先我们bfs遍历出从每一个点出发到另一个点的最短路,复杂度$O(|v|^2)$,然后用这些最短
路建图,枚举这四个点中的中间两个点,然后我们发现由于是有向图,对于其中第二个节点我们需要的是到达它的节点
所以我们要再建立一个反图.
这里写出来超时,有一个最优化剪枝,就是记录每个点出发的最长距离,和到达每个点的最长距离,在求解的时候
来最优化减去就好了.
**Get**:这个题实际上是组合题,通过最短路来建图,然后求有向图中最长四个节点的路径的长度.枚举的思想很重要
反图也是一个好的技巧,记得一个建立反图来求是不是一定是最短路经过节点的题也是比较经典.
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
#include <ctime>
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxv = 3e3 + 13;
const int maxe = 5e3 + 13;
int n, m;
vector<int> v[maxv];

int d[maxv];
struct node {
    int key, dist;
    node(){}
    node(int A, int B): key(A), dist(B){}
};

void bfs(int s) 
{
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    queue<node> que;
    que.push(node(s, 0));
    while (!que.empty()) {
        node cur = que.front(); que.pop();
        if (cur.dist > d[cur.key]) continue;
        rep (i, 0, (int)v[cur.key].size()) {
            int to = v[cur.key][i];
            if (d[to] > d[cur.key] + 1) {
                d[to] = d[cur.key] + 1;
                que.push(node(to, d[to]));
            }
        }
    }
}
vector<node> G[maxv], fG[maxv];
int dis[maxv][maxv], fdis[maxv][maxv];
int dm[maxv], fdm[maxv];

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    sa(n), sa(m);
    rep (i, 0, m) {
        int x, y; sa(x), sa(y);
        v[x].push_back(y);
    }
    rep (i, 1, n + 1) {
        bfs(i);
        rep (j, 1, n + 1) {
            if (d[j] != INF && d[j]) {
                G[i].push_back(node(j, d[j]));
                fG[j].push_back(node(i, d[j]));
                dm[i] = max(dm[i], d[j]);
                fdm[j] = max(fdm[j], d[j]);
                dis[i][j] = d[j];
                fdis[j][i] = d[j];
            }
        }
    }
    int ans = 0;
    int out[4];
    rep (i, 1, n + 1) {
        rep (j, 1, n + 1) {
            if (i == j) continue;
            if (dis[i][j] == 0) continue;
            if (dis[i][j] + dm[j] + fdm[i] <= ans) continue;
            int temp = dis[i][j];
            int maxj = 0, logj = -1, maxi = 0, logi = -1;
            rep (k, 0, (int)G[j].size()) {
                if (G[j][k].key != i && G[j][k].key != j && G[j][k].dist > maxj) {
                    maxj = G[j][k].dist;
                    logj = G[j][k].key;
                }
            }
            rep (k, 0, (int)fG[i].size()) {
                if (fG[i][k].key != i && fG[i][k].key != j && logj != -1 && fG[i][k].key != logj && fG[i][k].dist > maxi) {
                    maxi = fG[i][k].dist;
                    logi= fG[i][k].key;
                }
            }
            if (logi != -1 && logj != -1) {
                temp += maxi + maxj;
                if (temp > ans) {
                    out[0] = logi, out[1] = i, out[2] = j, out[3] = logj;
                    ans = temp;
                }
            }
        }
    }
    rep (i, 0, 4) printf("%d ", out[i]);
    return 0;
}
