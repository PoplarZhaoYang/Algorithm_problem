/***
 经典题了，现在自习想一下，想走了，然后再去选择最好加的油，并且最好加的油用一个平衡树这样的
 数据结构维护算是比较经典的数据结构贪心了
 前面碰到的用map维护的也是，先走，等到要选的时候选择满足什么条件什么最小的即可。
 ***/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int M = 10009, INF = 0x3fffffff;
int a[M], n, L, P;
pair<int, int> c[M];

int main(void) {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) scanf("%d%d", &c[n - i + 1].first, &c[n - i + 1].second);
        scanf("%d%d", &L, &P);
        for(int i = 1; i <= n; i++) c[i].first = L - c[i].first;
        sort(c + 1, c + n +1);
        a[n + 1] = L - c[n].first;
        for(int i = 1; i <= n; i++) {
            if(i != 1) a[i] = c[i].first - c[i - 1].first;
            else a[i] = c[i].first;
        }
        priority_queue<int> pq;
        int ans = 0, ok = 1;
        for(int i = 1; i <= n + 1; i++) {
            if(P - a[i] < 0) {
                if(pq.empty()) {ok = 0; puts("-1"); break;}
                while(P - a[i] < 0 && !pq.empty()) {
                    P += pq.top();
                    pq.pop();
                    ans++;
                }
                if(P - a[i] < 0 && pq.empty()) {ok = 0; puts("-1"); break;}
            }
            pq.push(c[i].second);
            P -= a[i];
        }
        if(ok) printf("%d\n", ans);
    }
    return 0;
}
