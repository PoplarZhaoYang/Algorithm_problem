#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

typedef bitset<112345> bit;

struct jibancanyang
{
    char s[112345], t[112345];
    bit dp[2][3], table[26];
    int n, m;

    void fun() {
        int T;
        scanf("%d", &T);
        while (T--) {
            scanf("%d%d", &n, &m);
            scanf("%s%s", s + 1, t + 1);
            for (int i = 0; i < 26; i++) table[i].reset();
            for (int i = 1; i <= n; i++) table[s[i] - 'a'][i] = true;
            bool cur = 0;
            for (int i = 0; i < 3; ++i) dp[cur][i].reset();
            dp[cur][1].set();
            for (int i = 1; i <= m; ++i) {
                int p = t[i - 1] - 'a', c = t[i] - 'a', a = t[i + 1] - 'a';
                if (i > 1) dp[!cur][0] = (dp[cur][2] << 1) & table[p];
                else dp[!cur][0].reset();

                dp[!cur][1] = (dp[cur][1] | dp[cur][0]) << 1 & table[c];

                if (i < m) dp[!cur][2] = (dp[cur][1] | dp[cur][0]) << 1 & table[a];
                else dp[!cur][2].reset();
                
                cur = !cur;
            }

            for (int i = 1; i <= n - m + 1; ++i) {
                bool ans = dp[cur][0][i + m - 1] | dp[cur][1][i + m - 1];
                putchar(ans ? '1' : '0');
            }
            
            for (int i = n - m + 2; i <= n; ++i) putchar('0');
            puts("");
        }
    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    bitset<30> t(12);
    pl(t);
    for (int i = 0; i < 30; i++) pr(t[i]);
    pl("adf");
    ac.fun();
    return 0;
}
