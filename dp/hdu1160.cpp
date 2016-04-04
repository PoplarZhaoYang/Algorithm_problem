/************************************************
 *Author        :jibancanyang
 *Created Time  :一  4/ 4 01:43:38 2016
 *题目类型:
 *************************************************/

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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e3 + 12;

int dp[maxn], logs[maxn];
struct node {
    int xx, yy;
    int num;
}a[maxn];

bool cmp(const node &a, const node &b) {
    return a.xx < b.xx;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int cnt = 0;
    while (cin >> a[cnt].xx >> a[cnt].yy) a[cnt].num = cnt + 1, ++cnt;
    sort(a, a + cnt, cmp);
    rep (i, 0, cnt + 1) dp[i] = 1, logs[i] = -1;
    
    rep (i, 0, cnt) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j].yy > a[i].yy && a[i].xx > a[j].xx) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    logs[a[i].num] = a[j].num;
                }
            }
        }
    }
    int ans = 0, key = 0;
    rep (i, 0, cnt) {
        if (dp[i] > ans) {
            ans = dp[i];
            key = a[i].num;
        }
    }
    stack<int> st;
    st.push(key);
    while (logs[key] != -1) {
        key = logs[key];
        st.push(key);
    }
    cout << ans << endl;
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
