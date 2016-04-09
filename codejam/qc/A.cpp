/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 六  4/ 9 07:57:39 2016
 *File Name     : jy.cpp
 *题目类型:
 *感悟:
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;




int main(void)
{
#ifdef LOCAL
    freopen("no1.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    
    int t;
    cin >> t;
    int cnt = 0;
    while (t--) {
        ll n;
        cin >> n;
        set<ll> st;
        int m = n;
        while (st.size() != 10) {
            ll temp = n;
            while (temp) {
                st.insert(temp % 10);
                temp /= 10;
            }
            n += m;
            if (!n) break;
        }
        cout << "Case #" << ++cnt <<": ";
        if (st.size() == 10) cout << n - m  << endl;
        else cout << "INSOMNIA" << endl;
    }
    return 0;
}
