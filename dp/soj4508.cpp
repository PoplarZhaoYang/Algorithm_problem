/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/15 20:18:06 2016
**Problem**:soj 4508 矩阵快速幂
**Analyse**:
矩阵构造,中间不能走的,分阶段就行了.
**Get**:
代码能力,在于想写简介.
**Code**:
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
#define pl(x) cout << #x << ": " << x << endl
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 3;


class matrix
{
public:
    ll v[3][3], n, m;
    matrix(){n = 3, m = 1; memset(v, 0, sizeof(v));} 
    matrix(int N, int M) {n = N, m = M; memset(v, 0, sizeof(v));}
    matrix operator*(const matrix &b) {
        matrix *a = this;
        matrix ret(a -> n, b.m);
        for (int i = 0; i < (int)a -> n; i++) {
            for (int j = 0; j < (int)b.m; j++) {
                ret.v[i][j] = 0;
                for (int k = 0; k < (int)b.n; k++) {
                   (ret.v[i][j] += (a -> v)[i][k] * b.v[k][j] % mod) %= mod; 
                }
            }
        }
        return ret;
    }

    matrix getit(ll x) {
        matrix ret(3, 3);
        for (int i = 0; i < 3; i++) ret.v[i][i] = 1;
        matrix mov(3, 3);
        mov.v[0][0] = 1, mov.v[0][1] = 1, mov.v[0][2] = 1, mov.v[1][0] = 1, mov.v[2][1] = 1;
        while (x) {
            if (x & 1) ret = ret * mov; 
            mov = mov * mov;
            x >>= 1;
        }
        return ret;
    }
    void debug(void) {
        cout << "Row: " << n << "Cloum: " << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << v[i][j] << " ";
            cout << endl;
        }
    }
};

ll limit[555];

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T; sa(T);
    while (T--) {
        ll n; sal(n);
        int m; sa(m);
        for (int i = 0; i < m; i++) sal(limit[i]);
        sort(limit, limit + m);
        matrix st; st.v[0][0] = 2, st.v[1][0] = 1, st.v[2][0] = 1;
        int cur = 2;
        int ans = -1;
        for (int i = 0; i < m; i++) {
            int l = limit[i];
            if (l < 0) continue;
            if (l == 1) st.v[1][0] = 0, st.v[0][0] = 1;
            else if (l == 0 || l == n) {
                ans = 0; break;
            } else if (l > n){
                break;
            } else {
                st = st.getit(l - cur) * st; 
                st.v[0][0] = 0;
                cur = l;
            }
        }
        if (ans == 0) puts("0");
        else if (n == 1 || n == 0) printf("%lld\n", st.v[2 - n][0]);
        else {
            st = st.getit(n - cur) * st;
            printf("%lld\n", st.v[0][0]);
        }
    }
    return 0;
}
