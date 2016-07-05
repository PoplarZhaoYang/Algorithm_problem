/***
 概率方程的dp
 ****/
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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  "
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        int n, z = 0, f = 0, pz = 0, pf = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > 0) pz++, z += x;
            else pf++, f += -x;
        }
        int fz = z + f, fm = n - pf;
        int g = gcd(fz, fm);
       // pr(fz), pl(fm);
        cout << "Case " << cas << ": ";
        //cout <<　"Case " << cas << ": ";
        if (pz == 0) cout << "inf" << endl;
        else cout << fz / g << "/" << fm / g << endl;
    }
    return 0;
}
