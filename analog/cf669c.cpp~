/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 一  4/25 00:27:04 2016
 *File Name     : cf669c.cpp
 *Problem:模拟
 *Get:想好思路，并符号化，再动手写。。。
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e2 + 12;

int op[maxn * maxn][2], cnt = 0, ans[maxn][maxn], n, m, q ;

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m >> q;
    while (q--) {
        int x, y, z, v;
        cin >> x;
        if (x == 3) {
            cin >> y >> z >> v;
            for (int i = cnt - 1; i >= 0; i--) {
                if (op[i][0] == 1) {
                    if (op[i][1] == y) {  
                        z++;
                        if (z == m + 1) z = 1;
                    }
                } else {
                    if (op[i][1] == z) {
                        y++;
                        if (y == n + 1) y = 1;
                    }
                }
            }
            ans[y][z] = v;
        } else {
            op[cnt][0] = x;
            cin  >> op[cnt][1];
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            cout << ans[i][j] ;
        }
        cout << endl;
    }
    return 0;
}
