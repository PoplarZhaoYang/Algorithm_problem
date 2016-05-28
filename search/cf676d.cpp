#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
const int maxn = 1e5 + 13;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};
int n, m;
char G[1002][1002];
int sx, sy, ex, ey;


string mp[4][300];

void pre(void) {
    mp[0][int('+')] = mp[1][int('+')] = mp[2][int('+')] = mp[3][int('+')] = "0123";
    mp[1][(int)'-'] = mp[3][(int)'-'] = mp[0][int('|')] = mp[2][int('|')] = "02";
    mp[0][(int)'-'] = mp[2][(int('-'))] = mp[1][int('|')] = mp[3][int('|')] = "13";
    mp[0][int('^')] =  mp[1][int('<')] = mp[2][(int)'V'] =  mp[3][int('>')] = "0";
    mp[0][int('>')] =  mp[1][int('^')] = mp[2][(int)'<'] =  mp[3][int('V')] = "1";
    mp[0][int('V')] =  mp[1][int('>')] = mp[2][(int)'^'] =  mp[3][int('<')] = "2";
    mp[0][int('<')] =  mp[1][int('V')] = mp[2][(int)'>'] =  mp[3][int('^')] = "3";
    mp[0][int('U')] =  mp[1][int('L')] = mp[2][(int)'D'] =  mp[3][int('R')] = "123";
    mp[0][int('R')] =  mp[1][int('U')] = mp[2][(int)'L'] =  mp[3][int('D')] = "023";
    mp[0][int('D')] =  mp[1][int('R')] = mp[2][(int)'U'] =  mp[3][int('L')] = "013";
    mp[0][int('L')] =  mp[1][int('D')] = mp[2][(int)'R'] =  mp[3][int('U')] = "012";
}

struct node {
    int x, y, t, r;
    node(int X, int Y, int T, int R) : x(X), y(Y), t(T), r(R){}
};

bool check (string aim, char c) {
    for (int i = 0; i < (int)aim.size(); i++) {
        if (c == aim[i]) return true;
    }
    return false;
}

bool vis[1111][1111][4];

int bfs(void)
{
    queue<node> que;
    vis[sx][sy][0] = true;
    if (sx == ex && sy == ey) return 0;
    que.push(node(sx, sy, 0, 0));
    while (!que.empty()) {
        node cur = que.front(); que.pop();
        if (!vis[cur.x][cur.y][(cur.r + 1) % 4]) {
             que.push(node(cur.x, cur.y, cur.t + 1, (cur.r + 1) % 4));
             vis[cur.x][cur.y][(cur.r + 1) % 4] = true;
        }
        string op = mp[cur.r][int(G[cur.x][cur.y])];
        for (int i = 0; i < (int)op.size(); i++) {
            int x = op[i] - '0';
            node nxt(cur.x + dirx[x], cur.y + diry[x], cur.t + 1, cur.r);
            if (nxt.x <= n && nxt.x > 0 && nxt.y <= m && nxt.y > 0 && G[nxt.x][nxt.y] != '*' && !vis[nxt.x][nxt.y][nxt.r]) {
                char c = G[nxt.x][nxt.y];
                string la = mp[cur.r][int(c)];
                if (check(la, char((x + 2) % 4 + '0'))) {
                    if (nxt.x == ex && nxt.y == ey) return nxt.t;
                    que.push(nxt);
                    vis[nxt.x][nxt.y][nxt.r] = true;
                }
            }

        }
    }
    return -1;
}

int main()
{
#ifdef xiaoai
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            G[i][j] = getchar();
            if (G[i][j] == 'v') G[i][j] = 'V';
        }
    }

    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    pre();
    printf("%d\n", bfs());
    return 0;
}
