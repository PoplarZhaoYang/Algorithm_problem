#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long longs;

struct node {
    int l, r, id;
}Q[int(5e5+ 9)];

int n, q, a[int(5e5 + 9)];
int lefts, rights;
longs  ans, out1[int(5e5 + 9)], cnt[int(1e6 +9)];
int bs;


bool cmp(const node& A, const node& B) {
    //int bs =  int(sqrt(n));
    if (A.l / bs == B.l / bs) return A.r / bs < B.r / bs;
    return A.l / bs < B.l / bs;
}

void del(int x) {
    ans += (1 - (cnt[x] << 1)) * x;
    cnt[x]--;
}


void add(int x) {
    ans += (1 + (cnt[x] << 1)) * x;
    cnt[x]++;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &q)) {
        bs = int(sqrt(n));
        //memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &Q[i].l, &Q[i].r);
            Q[i].id = i;
        }
        lefts = 1, rights = 0, ans = 0;
        sort(Q, Q + q, cmp);
        for (int i = 0; i < q; i++) {
            while (lefts < Q[i].l) del(a[lefts++]);
            while (lefts > Q[i].l) add(a[--lefts]);
            while (rights < Q[i].r) add(a[++rights]);
            while (rights > Q[i].r) del(a[rights--]);
            out1[Q[i].id] = ans;
        }
        for (int i = 0; i < q; i++) {
            printf("%I64d\n", out1[i]);
        }
    }
}
