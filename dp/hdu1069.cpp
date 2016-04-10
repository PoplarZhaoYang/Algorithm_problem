/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 日  4/10 10:30:34 2016
 *File Name     : hdu1069.cpp
 *题目类型: LIS 变形
 *感悟:这里实际上是定义了一种严格减小到偏序关系,但是我开始的排序思路,和cnt大小都弄错了,有些按照习惯的就是容易出错,看来每个细节都要去实际思考,而不是凭借习惯,这实际上是一种思维懒惰.
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;

int dp[200];
struct node {
    int x, y, z;
}a[200];

bool cmp(node &a, node &b) {
    if (a.x > b.x) return true;
    if (a.x == b.x) return  a.y > b.y;
    return false;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    
    int n, cnt = 1, T = 1;
    while (cin >> n, n) {
        cnt = 1;
        rep (i, 0, n) {
            int x, y, z;
            cin >> x >> y >> z;
            a[cnt].x = max(x, y), a[cnt].y = min(x, y), a[cnt++].z = z;
            a[cnt].x = max(y, z), a[cnt].y = min(y, z), a[cnt++].z = x;
            a[cnt].x = max(x, z), a[cnt].y = min(x, z), a[cnt++].z = y;
        }
        sort(a + 1, a + cnt , cmp);
        //for (int i = 1; i < cnt; i++) pr(i),pr(a[i].x), pr(a[i].y), pl(a[i].z);
        for (int i = 1; i < cnt; i++) dp[i] = a[i].z;
        for (int i = 2; i < cnt; i++) {
            for (int j = i - 1; j > 0; j--) {
                if (a[i].x < a[j].x && a[i].y < a[j].y) dp[i] = max(dp[i], dp[j] + a[i].z);
            }
            //pl(dp[i]);
        } 
        int ans = 0;
        for (int i = 1; i < cnt; i++) ans = max(ans, dp[i]);
        cout << "Case " << T++ << ": maximum height = ";
        cout << ans << endl;
    }
    return 0;
}
