#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

class kmp
{
private:
    static const int maxn = int(1e6) + 13;
    int n, slen, plen;
    char p[maxn], s[maxn];
    int next[maxn];
public:
    void input(void) { 
        std::cin >> n;
        while (n--) {
            std::cin >> p >> s;
            slen = strlen(s), plen = strlen(p);
            getnext();
            std::cout << getcnt() << std::endl;
        }
    }

    int getcnt(void) {
        int i = 0, j = 0, cnt = 0;
        while (i < slen) {
            if (j == -1 || p[j] == s[i]) i++, j++;
            else j = next[j];
            if (j == plen) {
                cnt++;
                j = next[j];
            }
        }
        return cnt;
    }

    void getnext(void) {
        next[0] = -1;
        int k = -1, j = 0;
        while (j <= plen) {
            if (k == -1 || p[j] == p[k]) {
                j++, k++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }

};

int main(void) {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    kmp temp;
    temp.input();
}
