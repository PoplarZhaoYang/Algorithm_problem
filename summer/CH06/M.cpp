/*
##题意：
有很多模式串每个都有自己的价值，然后求长度为$l$的原串，让所有它的子串价值最大。
##分析：
首先想到最直接的我们肯定要建立一个trie图来形容这个自动机，这个trie图是一个有向图，每一个节点代表一个状态（就是一串前缀字符串$pre$，然后在这些状态之后添加一个字符就转移到新的状态。
然后利用这个状态来进行动态规划,定义$dp[l][i]$为当前长度为$i$的字符串，末尾的后缀状态为trie图中的$i$节点，所能够得
到的最大价值，那么有转移方程$$dp[l][i] = max\{dp[l - 1][k] + b_k\} \ | \ 0<=k<maxtrie\ \ (其中b_k为从k状态转移到i状态所能得到的所有价值的和$$
$b_k$实际上是一系列的后缀价值和。
然后这里的$l<=10^{15}$非常的大，所以我们需要构建矩阵来加快转移速度。
定义$dp[i][j]$矩阵，表示初始从$i$状态到$j$状态所能获得的最大价值，$moves[i][j]$作为转移矩阵表示从$i$状态通过添加一个字母转移到$j$状态所能活得的累积价值和。
这样做快速幂。我们要求得的是$dp[0][i]\ | \ 0<=i<maxtrie$中最大的。
##心得：
对于前缀树，我们用它的节点的前缀字符串来维护当前长度原串的后缀，是这类题的重点。而构造转移矩阵
基本是添加一个字符转移到新的状态说需要进行的价值累积。
*/ 
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl
const int maxn = 200 + 13;

const int maxtrie = 200 + 12; //注意这里为最多500个单词,每个单词最多500个字母,所以节点最多为乘
const int maxcharset = 26; //字符集合
const char charst = 'a'; //起始字符
char buf[maxn];

typedef long long ll;
int n, A[222];
ll moves[maxtrie][maxtrie];
ll l, dp[maxtrie][maxtrie];

struct Trie
{
    int next[maxtrie][maxcharset], fail[maxtrie], end[maxtrie];
    int root, L;
    int newnode(void) {
        for (int i = 0;i < maxcharset;i++) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init(void) {
        L = 0;
        root = newnode();
    }
    void insert(char buf[], int x) {
        int len = (int)strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++) {
            if(next[now][buf[i] - charst] == -1)
                next[now][buf[i] - charst] = newnode();
            now = next[now][buf[i] - charst];
        }
        end[now] += A[x];
    }
    void build(void) {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < maxcharset;i++)
            if(next[root][i] == -1) next[root][i] = root;
            else fail[next[root][i]] = root, Q.push(next[root][i]);
        while (!Q.empty())  {
            int now = Q.front(); Q.pop();
            end[now] += end[fail[now]];
            for(int i = 0;i < maxcharset;i++)
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void makeMoves(void) {
        for (int i = 0; i < L; i++) for (int j = 0; j < L; j++) dp[i][j] = moves[i][j] = -1;
        for (int i = 0; i < L; i++) dp[i][i] = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < maxcharset; j++) {
                int now = next[i][j];
                moves[i][now] = end[now];
            }
        }
    }
}ac;

ll C[maxtrie][maxtrie];

void mul(ll (&a)[maxtrie][maxtrie], ll (&b)[maxtrie][maxtrie]) {
    for (int i = 0; i < ac.L; i++) {
        for (int j = 0; j < ac.L; j++) {
            C[i][j] = -1;
            for (int k = 0; k < ac.L; k++) {
                if (a[i][k] != -1 && b[k][j] != -1) C[i][j] = max(C[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    for (int i = 0; i < ac.L; i++) for (int j = 0; j < ac.L; j++) a[i][j] = C[i][j];
}

int main()
{
#ifdef LOCAL 
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.init();
    cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        ac.insert(buf, i);
    }
    ac.build();
    ac.makeMoves();
    while (l) {
        if (l & 1ll) mul(dp, moves);
        mul(moves, moves);
        l >>= 1;
    }
    ll ans = 0;
    for (int i = 0; i < ac.L; i++) ans = max(ans, dp[0][i]);
    cout << ans << endl;
    return 0;
}
