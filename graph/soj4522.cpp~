#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#define pr(x) std::cout << #x << ": " << x << " "
#define pl(x) std::cout << #x << ": " << x << std::endl

class Solution 
{
public:
    void input() {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) Graph_matrix[i][j] = false;
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x < y) std::swap(x, y);
            Graph_matrix[x][y] = true;
        }
    }

    void bulid_graph() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (Graph_matrix[i][j] == false) {
                    Graph[i].push_back(j);
                    Graph[j].push_back(i);
                }
            }
        }
    }

    bool dfs(int cur, int c) {
        color[cur] = c; cnt++;
        for (int i = 0; i < (int)Graph[cur].size(); i++) {
            int nxt = Graph[cur][i];
            if (color[nxt] == c) return false;
            if (color[nxt] == 0 && !dfs(nxt, -c)) return false;
        }
        return true;
    }

    void getit(int cur) {
        st.push(cur);
        if (color[cur] == 1) one++;
        else two++;
        vis[cur] = true;
        for (int i = 0; i < (int)Graph[cur].size(); i++) {
            int nxt = Graph[cur][i];
            if (!vis[nxt]) getit(nxt);
        }
    }
    void detect_BipartiteGraph() {
        ans = true;
        for (int i = 1; i <= n; i++) color[i] = 0, vis[i] = false;
        int key = 0;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                cnt = 0;
                ans = dfs(i, 1);
                if (cnt > 1) key++;
            }
            one = 0, two = 0;
            if (!vis[i]) getit(i);
            while (!st.empty()) {
                int cur = st.top();
                if (color[cur] == -1) {
                    if ((int)Graph[cur].size() != one) ans = false;
                } else {
                    if ((int)Graph[cur].size() != two) ans = false;
                }
                st.pop();
            }
            if (!ans) break;
        }
        puts(ans && key <= 1? "Yes" : "No");
    }
private:
    static const int maxn = 503;
    int n, m, one, two, cnt;
    bool Graph_matrix[maxn][maxn], ans, vis[maxn];
    std::vector<int> Graph[maxn];
    std::stack<int> st;
    int color[maxn];
};

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        Solution work;
        work.input();
        work.bulid_graph();
        work.detect_BipartiteGraph();
    }
}
