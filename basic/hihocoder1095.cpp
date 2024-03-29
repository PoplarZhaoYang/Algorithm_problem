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
int A[maxn], n, k;

bool judge(int mid) {
    ll hi = 0, ho = 0, v = 0;
    for (int i = 0; i < n; i++) {
        v += mid;
        if (A[i] >= v) {
            hi++;
            v = 0;
        } else {
            ho++;
            v -= A[i];
        }
    }
    return ho > hi;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sa(n), sa(k);
    for (int i = 0; i < n; i++) {
        sa(A[i]);
    }
    int l = 1, r = k + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    pri(l);
    return 0;
}
