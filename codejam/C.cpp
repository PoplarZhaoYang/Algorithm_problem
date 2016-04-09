/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 六  4/ 9 16:05:11 2016
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

ll a[] = {2, 3, 5, 7, 11}; 

long long  goit(ll x, ll base) {
    ll ans = 0, t = 1;
    while (x) {
       ans += (x & 1) * t;
       t *= base;
       x >>= 1;
    }
    return ans;
}

void prt(ll key) {
    while (key) {
        string ret;
        while (key) {
            if (key & 1) {
                ret += '1';
            } else ret += '0';
            key >>= 1;
        }
        for (int i = ret.size() -1; i >= 0; i--) {
            cout << ret[i];
        }
        cout <<  " ";
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int t;
    t = 1; 
    int cnt = 1;
    while (t--) {
        int j = 50;
        cout << "Case #" << cnt++ << ": " ;
        cout << endl; 
        int key = (1 << 15) + 1;

        while (j) {
            int v[11];
            memset(v, 0, sizeof(v));
            for (int i = 2; i <= 10; i++) {
                bool ok = false;
                ll b = goit(key, i);
                for (int j = 1; j < 5; j++) {
                   if (b % a[j] == 0) {
                       v[i] = a[j];
                       ok = true;
                       break;
                   }
                }
                if (!ok) break;
            }
            bool go = true;
            for (int i = 2; i < 11; i++) {
                if(!v[i]) go = false;
            }
            if (go) {
                prt(key);
                for (int i = 2; i < 11; i++) {
                    cout << v[i] << " ";
                }
                cout << endl;
                j--;
            }
                key += 2;
        }

    }
    return 0;
}
