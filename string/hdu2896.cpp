/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/ 5 10:01:15 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
**Code**:
***********************1599664856@qq.com**********************/

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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;

const int maxn =  200 * 500 + 12;
const int maxcharset = 128;
const char charst = 0;
char buf[10004];
int id;
bool used[510];
bool flag;

struct Trie
{
    int next[maxn][maxcharset], fail[maxn], ids[maxn];
    int root, L;
    int newnode(void) {
        for (int i = charst;i < maxcharset;i++) next[L][i] = -1;
        ids[L++] = -1;
        return L - 1;
    }
    void init(void) {
        L = 0;
        root = newnode();
    }
    void insert(char buf[]) {
        int len = (int)strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++) {
            if(next[now][buf[i] - charst] == -1)
                next[now][buf[i] - charst] = newnode();
            now = next[now][buf[i] - charst];
        }
        ids[now] = id;
    }
    void build(void) {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < maxcharset;i++)
            if(next[root][i] == -1) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())  {
            int now = Q.front(); Q.pop();
            for(int i = 0;i < maxcharset;i++)
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        memset(used, 0, sizeof(used));
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++) {
            now = next[now][buf[i] - charst];
            int temp = now;
            while(temp != root) {
                if (ids[temp] != -1 && !used[ids[temp]]) flag = true, used[ids[temp]] = true;
                temp = fail[temp];
            }
        }
        return res;
    }
};

Trie ac;
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int n, m;
    while (~sa(n)) {
        ac.init();
        rep (i, 0, n) {
            id = i + 1;
            scanf("%s", buf);
            ac.insert(buf);
        }

        sa(m);
        ac.build();
        int total = 0;
        rep (i, 0, m) {
            scanf("%s", buf);
            flag = false;
            ac.query(buf);
            if (flag) total++, printf("web %d:", i + 1);
            rep (j, 1, n + 1) {
                if (used[j]) flag = true, printf(" %d", j);
            }
            if (flag) puts("");
        }
        printf("total: %d\n", total);
    }
    return 0;
}
