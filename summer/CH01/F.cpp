/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/ 5 11:41:11 2016
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
const int maxn = 1e5 + 13;
struct node{
    int x, y;
}machine[maxn], mission[maxn];

bool cmp(node &a, node &b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++) sa(machine[i].x), sa(machine[i].y);
        for (int i = 0; i < m; i++) sa(mission[i].x), sa(mission[i].y);
        sort(machine, machine + n, cmp);
        sort(mission, mission + m, cmp);

        map<int, int> mp;
        map<int, int>::iterator it;
        int p = 0;
        int ans = 0; ll money = 0;
        for (int i = 0; i < m; i++) {
            while (p < n && machine[p].x >= mission[i].x) {
                mp[machine[p].y]++;
                p++;
            }
            it = mp.lower_bound(mission[i].y);
            if (it != mp.end()) {
                ans++;
                money += mission[i].x * 500 + mission[i].y * 2;
                if (it -> second == 1) mp.erase(it);
                else (it -> second)--;
            }
        }
    //    printf("%d %I64d\n", ans, money);
        cout << ans << " " << money << endl;
    }
    return 0;
}
