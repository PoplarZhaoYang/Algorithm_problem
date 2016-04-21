/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 三  4/20 23:23:24 2016
 *File Name     : cf665c.cpp
 *Problem:贪心
 *Get:贪心大凭借自觉产生,但要使用要尽可能证明其正确性.这里只要出现两个连续的了想必必须改变其中一个,它改变了只会影响它
 *左右两边的字符,所以改成和左右两边不相同就行了.
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
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    string a;
    while (cin >> a) {
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1]) {
                if (i + 1 < a.size()) {
                    for (int j = 0; j < 26; j++) {
                        a[i] = 'a' + j;
                        if (a[i] != a[i - 1] && a[i] != a[i + 1]) break;
                    }
                } else {
                    for (int j = 0; j < 26; j++) {
                        a[i] = 'a' + j;
                        if (a[i] != a[i - 1]) break;
                    }
                }
            }
        }
        cout << a << endl;
    }

    
    return 0;
}
