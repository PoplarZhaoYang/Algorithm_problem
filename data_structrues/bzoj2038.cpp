#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;


struct node {
    int l, r, id;
}Q[int(5e4+ 9)];

int n, q, a[int(5e4 + 9)];
int lefts, rights;
long long ans, out1[int(5e4 + 9)], cnt[int(5e4 +9)], out2[int(5e4 + 9)];


bool cmp(const node& A, const node& B) {
    int bs = int(sqrt(n));
    if (A.l / bs == B.l / bs) return A.r / bs < B.r / bs;
    return A.l / bs < B.l / bs;
}

void del(int x) {
    ans -= cnt[x] * cnt[x];
    cnt[x]--;
    ans += cnt[x] * cnt[x];
    ans++;
}


void add(int x) {
    ans -= cnt[x] * cnt[x];
    cnt[x]++;
    ans += cnt[x] * cnt[x];
    ans--;
}

long long gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &q)) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &Q[i].l, &Q[i].r);
            //Q[i].l--;
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
            out2[Q[i].id] = (long long)(rights - lefts + 1) * (rights - lefts);
        }
        for (int i = 0; i < q; i++) {
            if (!out1[i] || !out2[i]) {
                puts("0/1");
            } else {
                long long g = gcd(out1[i], out2[i]);
                printf("%lld/%lld\n", out1[i] / g, out2[i] / g);
            }
        }
    }
}
