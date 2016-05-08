/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/ 8 18:45:36 2016
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
int j, p, s, k;
int cnt;

struct node {
    int x, y, z;
}V[231];

bool vis[231], outv[231];
int logs[3][4][4];
int out;

void dfs(int x, int ans) 
{
    //if (ans + cnt - x < out) return;
    for (int i = 0; i < 3; i++) {
        for (int a = 1; a <= 10; a++) {
            for (int b = 1; b <= 10;  b++) {
                if (logs[i][a][b] > k) return;
            }
        }
    }
    if (ans > out) {
        out = ans;
        memcpy(outv, vis, sizeof(vis));
    }
    if (x == cnt) return;
    dfs(x + 1, ans);

    vis[x] = 1; 
    logs[0][V[x].x][V[x].y]++; logs[1][V[x].y][V[x].z]++; logs[2][V[x].x][V[x].z]++;
    dfs(x + 1, ans + 1);
    logs[0][V[x].x][V[x].y]--; logs[1][V[x].y][V[x].z]--; logs[2][V[x].x][V[x].z]--;
    vis[x] = 0;
}



int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    freopen("/Users/zhaoyang/cd.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    sa(T);
    for (int cas = 1;  cas <= T; cas++) {
        memset(logs, 0, sizeof(logs));
        cnt = 0;
        out = 0;
        sa(j), sa(p), sa(s), sa(k);
        for (int a = 1; a <= j; a++) {
            for (int b = 1; b <= p; b++) {
                for (int c = 1; c <= s; c++) {
                    V[cnt].x =  a;
                    V[cnt].y = b;
                    V[cnt].z = c;
                    cnt++;
                }
            }
        }
        dfs(0, 0);
        printf("Case #%d: %d\n", cas, out);
        for (int i = 0; i < cnt; i++) {
            if (outv[i]) {
                printf("%d %d %d\n", V[i].x, V[i].y, V[i].z);
            }
        }
    }
    
    return 0;
}
