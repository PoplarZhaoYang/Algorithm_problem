#include <iostream>
#include <cstdio>
using namespace std;

#define root l, r, rt
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

struct jibancanyang
{
    int flower[51234 << 2], n;

    void push_up(int rt) {
        flower[rt] = flower[rt << 1] + flower[rt << 1 | 1];
    }

    void build(int l, int r, int rt) {
        if (l == r) {
            scanf("%d", &flower[rt]);
            return;
        }
        int m = (l + r) >> 1;
        build(lson), build(rson);
        push_up(rt);
    }

    void update(int a, int b, int l, int r, int rt) {
        if (l == r) {
            flower[rt] += b;
            return;
        }
        int m = (l + r) / 2;
        if (a <= m) update(a, b, lson);
        if (a > m) update(a, b, rson);
        push_up(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) return flower[rt];
        int m = (l + r) / 2;
        int ret = 0;
        if (L <= m) ret += query(L, R, lson);
        if (R > m) ret += query(L, R, rson);
        return ret;
    }

    void run() {
        int T;
        scanf("%d", &T);
        for (int cas = 1; cas <= T; cas++) {
            scanf("%d", &n);
            build(1, n, 1);
            printf("Case %d:\n", cas);
            while (true) {
                int x, y;
                string op;
                cin >> op;
                if (op == "End") break;
                scanf("%d%d", &x, &y);
                if (op == "Query") {
                    printf("%d\n", query(x, y, 1, n, 1));
                } 
                if (op == "Add") update(x, y, 1, n, 1);
                if (op == "Sub") update(x, -y, 1, n, 1);
            }
        }
    }

}ac;

int main() 
{
    freopen("in.txt", "r", stdin);
    ac.run();
    return 0;
}
