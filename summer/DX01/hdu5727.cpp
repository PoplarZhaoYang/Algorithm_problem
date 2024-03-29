#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int n, m;
    bool bad[10][10];
    int yin[10];
    int V;
    vector<int> G[20];
    int match[20];
    bool used[20];

    void init() {
        for (int i = 1; i <= 2 * n; i++) G[i].clear();
    }

    void add(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int v) {
        used[v] = true;
        for (int i = 0; i < (int)G[v].size(); i++) {
            int u = G[v][i], w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int bigmatch() {
        int res = 0;
        memset(match, -1, sizeof(match));
        for (int v = 1; v <= V; v++) {
            if (match[v] < 0) {
                memset(used, 0, sizeof(used));
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }

    void build() {
        set<int> st;
        for (int i = 1; i <= n; i++) {
            int k, c = 231;
            while (true) {
                k = (rand() * rand() * c % n + n)  % n + 1;
                c++;
                if (!st.count(k)) {
                    st.insert(k);
                    break;
                }
            }
            yin[i] = k;
        }
        int ans = 0; 
        do {
            init();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (!bad[i][yin[j]] && 
                        !bad[i][j + 1 > n ? yin[1] : yin[j + 1]]) {
                        add(i, j + n);
                    }
                }
            }
            ans = max(ans, bigmatch());
            if (ans == n) break;
        } while(next_permutation(yin + 1, yin + n));
        printf("%d\n", n - ans);
    }

    void run() {
        while (~scanf("%d%d", &n, &m)) {
            memset(bad, false, sizeof(bad));
            V = n;
            while (m--) {
                int x, y;
                scanf("%d%d", &x, &y);
                bad[x][y] = true;
            }
            build();
        }
    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ac.run();
    return 0;
}
