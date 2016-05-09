/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 9 11:49:40 2016
 *File Name*     : poj2778.cpp
**Problem**:
给你$m$个病毒串,求指定长度n且不含病毒串作为子串的字符串一共有多少种.
**Analyse**:
用AC自动机构建$L$个状态节点,每个节点的end标记记录是否在这里形成病毒串.
这里有个核心就是,如果当前后缀的子后缀(也就是它的fail指针指向的地方)是病毒串的话,
那么它就是病毒串.
然后根据这个AC自动机的$L$个节点来建立有向图的邻接矩阵B,B[i][j]代表从i到j状态的路径数量.
B[0][j]代表的是从初始状态,还没有任何字符的时候转移到$j$状态,因为根节点0就是没有任何限制.
然后$B^k$之后,B[i][j]代表的是,从i到j长度为k的路径有多少条.
我们需要求得就是从根节点出发到任意节点,长度为n的路径的条数.

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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e5) + 0, INF = 0x3fffffff;
const int maxn = 1e5 + 13;

const int maxtrie = 11 * 10 + 12; //注意这里为最多500个单词,每个单词最多500个字母,所以节点最多为乘
const int maxcharset = 4; //字符集合
const int charst = 0;
char buf[11];

class matrix
{
public:
    ll M[maxtrie][maxtrie], n;
    matrix (int N){
        n = N;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                M[i][j] = 0;
    }
    matrix(int N, int x) {
        n = N;
        for (int i = 0; i < N; i++) M[i][i] = x;
    }
    matrix operator* (const matrix &b) {
        matrix &a = *this;
        matrix ret(b.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret.M[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    ret.M[i][j] += a.M[i][k] * b.M[k][j]  % mod;
                }
                ret.M[i][j] = ret.M[i][j] % mod;
            }
        }
        return ret;
    }

    matrix operator^ (int b) {
        matrix ret(this -> n, 1);
        matrix a = *this;
        while (b) {
            if (b & 1) ret = ret * a;
            a = a * a;
            b >>= 1;
        }
        return ret;
    }

};

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
        if (c == 'A') return 0;
        if (c == 'T') return 1;
        if (c == 'C') return 2;
        if (c == 'G') return 3;
        return 0;
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
                    next[now][i] = next[fail[now]][i];
                    end[now] = end[now] || end[fail[now]];
                }
                else {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
}ac;

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int m, k;
    while (~scanf("%d%d", &m, &k)) {
        ac.init();
        for (int i = 0; i < m; i++) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        matrix A(ac.L);
        for (int i = 0; i < ac.L; i++) {
            if (!ac.end[i]) {
                for (int j = 0; j < 4; j++) {
                    int temp = ac.next[i][j];
                    if (!ac.end[temp]) A.M[i][temp]++;
                }
            }
        }
        matrix B = A ^ k;
        /*for (int i = 0; i < ac.L; i++) {
            cout << i << ":  ";
            for (int j = 0; j < ac.L; j++) {
                cout << B.M[i][j] << " ";
            }
            cout << endl;
        }*/
        ll ans = 0;
        for (int i = 0; i < ac.L; i++) ans += B.M[0][i] % mod;
        printf("%lld\n", ans % mod);
    }
    
    return 0;
}
