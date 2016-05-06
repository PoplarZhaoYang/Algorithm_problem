/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  5/ 6 16:14:59 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
此题难就难在编码,还有题意问的是病毒有多少种不是多少个,注意char已经不能表示解码之后的字符,要用
256的int来表示.
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

const int maxn = 100000 + 13;
const int maxtrie = 520 * 90 + 12; //注意这里为最多500个单词,每个单词最多500个字母,所以节点最多为乘
const int maxcharset = 256; //字符集合
const char charst = 0; //起始字符
int buf[maxn];
int bufcnt;


char base64[maxn];
int bitcnt;
bool bit[maxn * 10];

int getv(char x) {
    if (islower(x)) return x - 'a' + 26;
    else if (isupper(x)) return x - 'A';
    else if (isdigit(x)) return x - '0' + 52;
    else return (x == '+' ? 62 : 63);
}

void pb(int x) {
    for (int i = 5; i >= 0; i--) {
        if (x >> i & 1) bit[bitcnt++] = 1;
        else bit[bitcnt++] = 0;
    }
}

void tobit(char c) {
    int temp = getv(c);
    pb(temp);
}

void decode(void) {
    bufcnt = bitcnt = 0;
    int len = (int)strlen(base64);
    for (int i = 0; i < len; i++) {
        if (base64[i] == '=') bitcnt -= 2;
        else tobit(base64[i]);
    }
    for (int i = 0; i < bitcnt; i += 8) {
        int temp = 0;
        for (int j = i; j < i + 8; j++) {
            if (bit[j]) temp += 1 << (7 - (j - i));
        }
        buf[bufcnt++] = temp;
    }
}

bool used[523];

struct Trie
{
    int next[maxtrie][maxcharset], fail[maxtrie], end[maxtrie];
    int root, L;
    int newnode(void) {
        for (int i = 0;i < maxcharset;i++) next[L][i] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void init(void) {
        L = 0;
        root = newnode();
    }
    void insert(int buf[], int id) {
        int len = bufcnt;
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
    int query(int buf[])
    {
        int len = bufcnt, now = root, ret = 0;

        for(int i = 0;i < len;i++) {
            now = next[now][buf[i] - charst];
            int temp = now;
            while(temp != root) {
                if (end[temp] != -1 && !used[end[temp]]) {
                    ret += 1;
                    used[end[temp]] = true;
                }
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
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m;
    while (~sa(n)) {
        ac.init();
        for (int i = 0; i < n; i++) {
            scanf("%s", base64);
            decode();
            //for (int i = 0; i < bufcnt; i++) cout << (char)buf[i] << " ";
            //cout << endl;
            ac.insert(buf, i);
        }
        sa(m);
        ac.build();
        for (int i = 0; i < m; i++) {
            scanf("%s", base64);
            decode();
            memset(used, 0, sizeof(used));
            //for (int i = 0; i < bufcnt; i++) cout << (char)buf[i] << " ";
            //cout << endl;
            pri(ac.query(buf));
        }
        puts("");
    }
    return 0;
}