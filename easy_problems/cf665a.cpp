/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 三  4/20 22:59:56 2016
 *File Name     : jy.cpp
 *Problem:
 *Get:认真读题
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



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    char f;
    int x, y;
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    cin >> x >> f >> y;
    x = x * 60 + y;
    int l = x - tb + 1, r = x + ta - 1;
    
    int ans = 0;
    for (int i = 300; i <= 23 * 60 + 59; i += b) {
        if (i >= l && i <= r) ans++;
    }
    cout << ans << endl;
    return 0;
}
