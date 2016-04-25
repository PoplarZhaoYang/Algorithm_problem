/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 一  4/25 01:45:31 2016
 *File Name     : cf669d.cpp
 *Problem:观察规律
 *Get:
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e6 + 12;
int a[maxn];

int n, q;


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    sa(n), sa(q);
    int one = 0, two = 1;
    while (q--) {
        int op, t;
        sa(op);
        if (op == 1) {
            sa(t);
            one = ((one + t) % n + n) % n, two = ((two + t) % n + n) % n;
        } else {
            if (one % 2 == 0) one = (one + 1) % n; 
            else one = (one - 1 + n) % n;
            if (two % 2 == 0) two = (two + 1) % n;
            else two = (two - 1 + n) % n;
        }

    }
    a[one] = 1, a[two] = 2;
    for (int i = (one + 2) % n, t = 3; i != one; i = (i + 2) % n) {
       a[i] = t;
       t += 2;
    }
    for (int i = (two + 2) % n, t = 4; i != two; i = (i + 2) % n) {
        a[i] = t;
        t += 2;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i] );
    }
    puts("");
    return 0;
}
