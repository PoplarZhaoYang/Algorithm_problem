/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/ 5 11:41:11 2016
**Problem**:
**Analyse**:
因为$500x + 2y**这个公式的巨大偏向性，我们会优先满足时间。
这样遍历整个任务，给任务安排机器。我们维护一个集合，集合里装的是所有还没有用的
比能完成当前任务时间的机器，然后每次在里面选优先级能满足当前任务的最小的任务并从集合中删去就可。

**Get**:
想想法的时候不要先代码实现，先尽量抽象，会有更多思路.
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
