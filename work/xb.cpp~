#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

const int maxn = 26;

struct jibancanyang
{
    int n, m, G[maxn][maxn];
    bool t;

    bool check(int x, int y) {
        bool ok = true;
        int jib = 0;
        for(int i = 1; i <= n; i++) {
            swap(G[i][x], G[i][y]);
            int cnt = 0;
            for(int j = 1; j <= m; j++) {
                if(G[i][j] != j) {
                    cnt++;
                    jib += cnt;
                }
            }
            if(cnt > 2) ok = false;
            swap(G[i][x], G[i][y]);
        }
        return ok;
    }


    void fun() {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> G[i][j];
            }
        }
        t = true;
        for (int i = 1; i <= n; ++i) {
            int c = 0;
            for (int j = 1; j <= m; ++j) {
                if (G[i][j] != j) c++;
            }
            if (c > 2) t = false;
        }
        if(t == true) {
            cout << "YES" << endl;
        } else {
            t = false;
            for(int i = 1; i <= m; i++) {
                for(int j = i + 1; j <= m; j++) {
                    if(check(i, j) == true) {
                        t = true;
                        i = m + 1;
                        break;
                    }
                }
            }
            puts(t ? "YES" : "NO");
        }


    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.fun();
    return 0;
}



