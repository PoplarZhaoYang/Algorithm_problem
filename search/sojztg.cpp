/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 2 13:32:02 2016
 *File Name*     : jy.cpp
**Problem**:
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 5e2 + 13;
int  C, T, N, M;
char table[16];
bool vis[5000 + 12];
char dp[5000 + 12];
int change[5000 + 12];

bool ok;


struct node {
    int m, l;
    char c;
    node(){}
    node(int A, int B, char C): m(A), l(B), c(C){
    }
};

int getit(char x) {
    if (x <= '9') return x - '0';
    return x - 'A'+ 10;
}

void bfs() 
{
    queue<node> que;
    for (int i = (table[0] == '0' ? 1 : 0); i < M; i++) {
        que.push(node(getit(table[i]) % N, 1, table[i])); 
        change[getit(table[i]) % N] = -1997;
        vis[getit(table[i]) % N] = true;
        dp[getit(table[i]) % N] = table[i];
    }
    while (!que.empty()) {
        node cur = que.front(); que.pop();
      //  cout << cur.c << " " << cur.m << " " << cur.l << endl;
        if (cur.l > 500) return;

        if (cur.m == 0) {
             string str;
           /*  rep (i, 0, N) pr(i), pr(dp[i]);
             puts("");
             rep (i, 0, N) pr(i), pr(change[i]);
             puts("");
             */
             while (true) {
                //printf("%c", dp[cur.m]);
                str += dp[cur.m];
                cur.m = change[cur.m];
                if (cur.m == -1997) break;
             }
            for (int i = str.size() - 1; i >= 0; i--) cout << str[i];

            puts("");
            ok = true;
            return;
        }

        rep (i, 0, M) {
            node nexts;
            nexts.m = (cur.m * C + getit(table[i])) % N;
            nexts.l = cur.l + 1;
            nexts.c = table[i];
            if (!vis[nexts.m]) 
                vis[nexts.m] = true, dp[nexts.m] = table[i], change[nexts.m] = cur.m, que.push(nexts);
        }
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    sa(T);
    while (T--) {
        sa(N), sa(C), sa(M);
        rep (i, 0, N) vis[i] = false;
        ok = false;
        rep (i, 0, M) cin >> table[i];
        sort(table, table + M);

        if (!N) puts("0");
        else {
            bfs();
            if (!ok) puts("BOMB!!!");
        }
    }
    
    return 0;
}
