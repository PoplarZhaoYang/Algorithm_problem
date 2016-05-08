
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))

const int maxn = 100;
int cnt[maxn];
struct node {
    int xx, yy;
    node(){}
    node(int a, int b) :xx(a), yy(b){}
};

class cmp
{
public:
    bool operator()(const node a, const node b) {
        if (a.xx == b.xx) return a.yy < b.yy;
        else return a.xx < b.xx;
    }
};

int main(void)
{
#ifdef LOCAL
   freopen("//Users/zhaoyang/in.txt", "r", stdin);
    freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int Cas = 1; Cas <= T; Cas++) {
        int N;
        memset(cnt, 0, sizeof(cnt));
        sa(N);
        priority_queue<node, vector<node>, cmp> que;
        int tot = 0;
        for (int i = 0; i < N; i++) {
            int x;
            sa(x);
            tot += x;
            que.push(node(x, i));
        }
        printf("Case #%d:", Cas);
        while(tot > 0) {
            node cur = que.top(); que.pop();
            printf(" %c", cur.yy + 'A');
            tot--;
            cur.xx--;
            if(cur.xx != 0) {
                que.push(cur);
            }
            if(tot % 2 == 1) {
               node cur = que.top(); que.pop();
                printf("%c", cur.yy + 'A');
                tot--;
                cur.xx--;
                if(cur.xx != 0) {
                    que.push(cur);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
