/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 一  4/11 22:36:38 2016
 *File Name     : poj1661.cpp
 *题目类型:经典dp
 *感悟:一类具有重叠子问题的经典方法,其实不过是一颗二叉树的记忆化,只是转移过程比较繁杂而已罢了..然后这里很明显的高度具有顺序性所以,排序也是习惯性操作.
 *dp[i][0], dp[i][1]分别表示在第i块板子的左边和右边到达底部所需要的最小时间,转移即可.
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
int T, n, x, y, h;
int dp[maxn / 100][2];
struct node{
    int l, r, h;
}a[maxn / 100];

bool cmp(const node &a, const node &b) {
    return a.h < b.h;
}
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    cin >> T; 
    while (T--) {
        cin >> n >> x >> y >> h;
        for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r >> a[i].h;
        a[0].l = -INF, a[0].r = INF, a[0].h = 0;
        sort(a + 1, a + n + 1, cmp);
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j].l <= a[i].l && a[j].r >= a[i].l) {
                    dp[i][0] = min(dp[j][0] + a[i].l - (j == 0 ? a[i].l : a[j].l), dp[j][1] + ( j == 0 ? a[i].l : a[j].r) - a[i].l) + a[i].h - a[j].h;
                    if (a[i].h - a[j].h > h) dp[i][0] = INF; 
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (a[j].l <= a[i].r && a[j].r >= a[i].r) {
                    dp[i][1] = min(dp[j][0] + a[i].r - (j == 0 ? a[i].r : a[j].l), dp[j][1] + ( j == 0 ? a[i].r : a[j].r) - a[i].r) + a[i].h - a[j].h;
                    if (a[i].h - a[j].h > h) dp[i][1] = INF; 
                    break;
                }
            }
        }
        for (int i = n; i >= 0; i--) {
            if (a[i].h <= y && a[i].l <= x && a[i].r >= x) {
                if (i == 0) cout << y << endl;
                else cout << min(dp[i][0] + x - a[i].l, dp[i][1] + a[i].r - x) + y - a[i].h << endl;
                break;
            }
        }
    }
    
    return 0;
}
