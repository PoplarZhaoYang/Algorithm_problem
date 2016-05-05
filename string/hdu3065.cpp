/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  5/ 5 15:51:27 2016
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
vector<int> vi;
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
const int maxn = 2e6 + 13;
const int maxtrie = 50 * 1000 + 12; //注意这里为最多500个单词,每个单词最多500个字母,所以节点最多为乘
const int maxcharset = 26; //字符集合
const char charst = 'A'; //起始字符
char buf[maxn];
char mp[1111][53];
int gs[1111];

struct Trie
{
    int next[maxtrie][maxcharset], fail[maxtrie], end[maxtrie];
    int root, L;
    int newnode(void) {
        for (int i = 0; i < maxcharset; i++) next[L][i] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void init(void) {
        L = 0;
        root = newnode();
    }
    void insert(char buf[], int id) {
        int len = (int)strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++) {
            if(next[now][buf[i] - charst] == -1)
                next[now][buf[i] - charst] = newnode();
            now = next[now][buf[i] - charst];
        }
        end[now] = id;
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
        int len = strlen(buf), now = root, ret = 0;
        for(int i = 0;i < len;i++) {
            if (!isupper(buf[i])) {
                now = root;
                continue;
            }
            now = next[now][buf[i] - charst];
            int temp = now;
            while(temp != root) {
                if (end[temp] != -1) gs[end[temp]]++;
                temp = fail[temp];
            }
        }
        return ret;
    }
}ac;


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    while (~sa(n)) {
        ac.init();
        rep (i, 0, n) {
            scanf("%s", mp[i]);
            ac.insert(mp[i], i);
            gs[i] = 0;
        }
        ac.build();
        scanf("%s", buf);
        ac.query(buf);
        rep (i, 0, n) {
            if (gs[i]) {
                printf("%s: ", mp[i]);
                pri(gs[i]);
            }
        }
    }
    
    return 0;
}
