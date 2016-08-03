#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    static const int maxn = int(1e6) +7;
    char str[maxn], aim[maxn * 2];
    int ti, len, P[maxn * 2], cntl[maxn], suml[maxn], cntr[maxn], sumr[maxn];
    long long ans;

    void pre() {
        len = strlen(str);
        ti = 0;
        aim[ti++] = '^';
        for (int i = 0; i < len; ++i) aim[ti++] = '#', aim[ti++] = str[i];
        aim[ti++] = '#', aim[ti++] = '$';
    }

    void aft() {
        memset(suml, 0, sizeof(suml));
        memset(sumr, 0, sizeof(suml));
        memset(cntl, 0, sizeof(suml));
        memset(cntl, 0, sizeof(suml));
        for (int i = 1; i < ti - 1; i++) {
            int c = (i + 1) / 2, l = (c - 1 - P[i]) / 2, r = l + P[i] - 1; 
            cntl[c]++, cntl[r + 1]--;


        }


    }

    void manacher() {
        pre();
        int C = 0, R = 0;
        for (int i = 1; i < ti - 1; ++i) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min((R - i), P[i_mirror]) : 0;
            while (aim[i + 1 + P[i]] == aim[i - 1 - P[i]]) ++P[i];
            if (i + P[i] > R) C = i, R = i + P[i];
        }
        aft();
    }

    void fun() {
        while (~scanf("%s", str)) manacher(), printf("%lld\n", ans);
    }

}ac;

int main()
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    return 0;
}
