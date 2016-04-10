/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 日  4/10 15:45:00 2016
 *File Name     : hdu1074.cpp
 *题目类型:状态压缩dp
 *感悟:看数据范围易猜测为2的指数次方复杂度,这里显然是状态压缩dp,状态就是哪些课已经选了,
 *哪些课还没选,dp[s]表示该状态下的最小扣分,lasttime表示该状态下的最小未被占用时间
 *状态之间的转移就是去枚举每一个元素被改变.
 *这里由于要输出路径,还用了pre[s],表示该状态是由哪一个状态转移过来.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1 << 15;
int n, dp[maxn], lasttime[maxn], s[15], d[15], pre[maxn];
string name[15];

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        rep (i, 0, n) cin >> name[i] >> s[i] >> d[i];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = lasttime[0] = 0;
        int m = 1 << n;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( (i >> j) & 1) {
                    int k = i - (1 << j);
                    int temp = lasttime[k] + d[j];
                    int gap = s[j] >= temp ? 0 : temp - s[j];
                    if (dp[i] >= gap + dp[k]) {
                        dp[i] = gap + dp[k];
                        pre[i] = k;
                        lasttime[i] = temp; 
                    }
                }
            }
        }
        cout << dp[m - 1] << endl;
        int cur = m - 1;
        stack<int> st;
        while (cur) {
            int last = pre[cur];
            int key;
            for (int i = 0; i < n; i++) {
                int l = (cur >> i) & 1, r = (last >> i) & 1;
                if (l ^ r) key = i;
            }
            st.push(key); 
            cur = last;
        }
        while (!st.empty()) {
            cout << name[st.top()] << endl;
            st.pop();
        }
    }
     
    return 0;
}
