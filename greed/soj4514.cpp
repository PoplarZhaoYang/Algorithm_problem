/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/19 16:02:32 2016
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
const int maxn = 1e5 + 13;
int vis[25], A[25];
bool ans;


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T, n; sa(T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        sa(n);
        ans = true;
        for (int i = 0; i < n; i++) scanf("%d", A + i);
        sort(A, A + n);
        for (int i = 0; i < n; i++) {
            int have = 1;
            int j;
            for (j = i; have < A[i] && j >= 0; ) {
                j--;
                if (!vis[j] && A[j] <= A[i] - 2 && have + A[j] <= A[i])
                    have += A[j], vis[j] = true;
            }
            if (j < 0) {
                ans = false;
                break;
            }
        }
        for (int i = 0; i < n - 1; i++) if (!vis[i]) ans = false;
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
