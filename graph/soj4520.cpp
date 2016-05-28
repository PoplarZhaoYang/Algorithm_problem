/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  5/27 21:42:31 2016
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 500 + 13;
int degree[maxn], ind[maxn];
int par[maxn], rnk[maxn];
bool vis[maxn];

void init(int n) {
    for (int i = 0; i <= n; i++) par[i] = i, rnk[i] = 0;
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (rnk[x] > rnk[y]) {
        par[y] = x;
    } else {
        par[x] = y;
        if (rnk[x] == rnk[y]) rnk[y]++;
    }
}

bool same(int a, int b) {return find(a) == find(b);}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T, n, m; sa(T);
    while (T--) {
        sa(n), sa(m);
        memset(degree, 0, sizeof(degree));
        memset(ind, 0, sizeof(ind));
        memset(vis, 0, sizeof(vis));
        init(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            sa(x), sa(y);
            degree[x]++, degree[y]++;
            vis[x] = vis[y] = true;
            unite(x, y);
            ind[x]--, ind[y]++;
        }
        set<int> st;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                st.insert(find(i));
            }
        }
        //bool key = (st.size() == 1);
        bool key = true;
        int odd_deg = 0, a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                if (degree[i] % 2) odd_deg++;
                if (ind[i] == -1) a++;
                else if (ind[i] == 1) b++;
                else if (ind[i] != 0) c++;
                else ;
            } else {
                key = false;
                break;
            }
        }
        bool g = (a == 0 && b == 0) || (a == 1 && b == 1);
        if (n == 1 && m == 0) puts("Yes Yes");
        else printf("%s %s\n", ((odd_deg == 2 || odd_deg == 0) && key ) ? "Yes" : "No", (g && c == 0 && key ) ? "Yes" : "No");
    }
    return 0;
}
