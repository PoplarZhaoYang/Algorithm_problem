/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 9 11:49:40 2016
 *File Name*     : sojztn.cpp
**Problem**:
给你m个字符串,问长度为n,至少包含其中一个字符串为子串的字符串的个数.
**Analize**:
- 将问题转化为$$26^k - 不包含任意子串的个数$$,这里用AC自动机来建立禁止字符串.
- 所有节点的子节点开始都为根节点,在添加禁止字符串的过程中扩展
- 利用fail指针来扩展禁止字符串,也就是当前字符串的fail指针的字符串如果都是禁止字符串那么当前节点也一定是.


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
typedef int ll;
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e4) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;

const int maxtrie = 6000 + 12; //注意这里为最多500个单词,每个单词最多500个字母,所以节点最多为乘
const int maxcharset = 26; //字符集合
const int charst = 'A';
char buf[111];


struct Trie
{
    int next[maxtrie][maxcharset], fail[maxtrie], end[maxtrie];
    int root, L;
    int newnode(void) {
        for (int i = 0;i < maxcharset;i++) next[L][i] = 0;
        end[L++] = 0;
        return L - 1;
    }
    int getid(char c) {
        return c - charst;
    }
    void init(void) {
        L = 0;
        root = newnode();
    }
    void insert(char buf[]) {
        int len = (int)strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++) {
            if(next[now][getid(buf[i])] == 0)
                next[now][getid(buf[i])] = newnode();
            now = next[now][getid(buf[i])];
        }
        end[now] = true;
    }
    void build(void) {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < maxcharset;i++)
            if(next[root][i] == 0) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())  {
            int now = Q.front(); Q.pop();
            for(int i = 0;i < maxcharset;i++)
                if(next[now][i] == 0) {
                    next[now][i] = next[fail[now]][i]; //trie树的优化
                    end[now] = end[now] || end[fail[now]]; //核心
                }
                else {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
}ac;

ll fastmod(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret % mod;
}

int dp[102][maxtrie];

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int m, K, T;
    sa(T);
    while (T--){
        sa(m), sa(K); 
        ac.init();
        for (int i = 0; i < m; i++) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        ll ans = fastmod(26, K);
        for (int i = 0; i <= K; i++) 
            for (int j = 0; j < ac.L; j++) 
                dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < ac.L; j++) {

                for (int k = 0; k < 26; k++) {
                    int u = ac.next[j][k];
                    if (!ac.end[u])  dp[i + 1][u] = (dp[i + 1][u] + dp[i][j]) % mod;
                }
            }
        }
        int anst = 0;
        for (int i = 0; i < ac.L; i++)  anst = (anst + dp[K][i]) % mod; 
        printf("%d\n", (ans - anst + mod) % mod);
    }
    
    return 0;
}
