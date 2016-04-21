/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 三  4/20 23:23:24 2016
 *File Name     : cf665b.cpp
 *Problem:
 *Get:简单模拟
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

int pos[111], n, m, k;

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> pos[i];
    int ans = 0;
    while (n--) {
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            for (int i = 1; i <= k; i++) {
                ans++;
                if (pos[i] == x) {
                    for (int j = i; j > 1; j--) {
                        pos[j] = pos[j - 1];
                    }
                    pos[1] = x;
                    break;
                }
            }
        }
    }
    cout << ans << endl;

    
    return 0;
}
