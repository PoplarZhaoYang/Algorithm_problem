#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


struct jibancanyang
{
    int chess[1 << 21];
    bool have[30];

    void pre() {
        for (int i = 1; i < 1 << 20; i++) {
            memset(have, 0, sizeof(have));
            for (int j = 0; j < 20; j++) {
                if (i & (1 << j)) {
                    int k;
                    for (k = j - 1; k >= 0; k--) {
                        if (!(i & (1 << k))) break;
                    }
                    if (k >= 0) {
                        int temp = i ^ (1 << j) | (1 << k);
                        have[chess[temp]] = true;
                    } 
                }
            }
            int cnt = 0;
            while (have[cnt]) cnt++;
            chess[i] = cnt;
        }
    }

    void run() {
        pre();
        int T, n; 
        scanf("%d", &T);
        while (T--) {
            scanf("%d", &n);
            int ans = 0;
            while (n--) {
                int x, s = 0, bit;
                scanf("%d", &x);
                while (x--) {
                    scanf("%d", &bit);
                    s ^= 1 << (20 - bit);
                }
                ans ^= chess[s]; 
            }
            puts(ans ? "YES" : "NO");
        }
    }

}ac;

int main()
{
    freopen("in.txt", "r", stdin);
    ac.run();
    return 0;
}

