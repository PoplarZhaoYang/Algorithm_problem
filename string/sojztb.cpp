/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 日  5/ 1 22:03:43 2016
 *File Name     : jy.cpp
 *Problem:
 *Get:
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 5e7 + 12;
int nexts[maxn];
char s[maxn], p[maxn], aim[maxn];
bool vis[maxn];
int slen, plen;

void getnexts(char *p)    //根据模式串p,构建nexts数组
{
    nexts[0] = -1;    //nexts数组就是当前位置前面的子串的最大前缀后缀长度
    int k = -1, j = 0;
    while (j < plen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++k;
            ++j;
            //对于当前值相等的情况进行优化,因为当前值相等,移位匹配也必定失败**注意纯用next数组性质求循环节的时候请去掉这个剪枝优化!

                if (p[j] != p[k]) nexts[j] = k;
                else nexts[j] = nexts[k];
        } else {
            k = nexts[k];
        }
    }
}

int kmp(char* p, char* s)
{
    int i = 0, j = 0;
    rep (i, 0, slen) vis[i] = false;
    while (i < slen) {
        if (j == - 1 || s[i] == p[j]) i++, j++;
        else j = nexts[j];
        if (j == plen) {
            vis[i - j] = true;
            j = nexts[j];
        }
    }
    if (j == plen) return i - j;    //返回匹配串的起始位置
    return -1;
}



int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    sa(T);
    while (T--) {
        scanf("%s%s%s", s, p, aim);
        slen = strlen(s);
        plen = strlen(p);
        getnexts(p);
        kmp(p, s);
        rep (i, 0, slen) {
            if (vis[i]) {
                printf("%s", aim);
                i += plen - 1;
            } else printf("%c", s[i]);
        }
        puts("");
    }

    return 0;
}
