/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/29 13:19:28 2016
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e6 + 12;

char t[maxn];
int nexts[maxn], extend[maxn], slen, tlen;

//计算next数组，保存到next参数中。
void getextendnexts(void)
{
    tlen = strlen(t), slen = tlen;
    for (int i = 1, j = -1, a, p; i < tlen; i++, j--)
        if (j < 0 || i + nexts[i - a] >= p) {
            if (j < 0)  j = 0, p = i;
            while (p < tlen && t[j] == t[p]) j++, p++;
            nexts[i] = j, a = i;
        }
        else nexts[i] = nexts[i - a];
}

void extkmp(void)
{
    getextendnexts();  //计算next数组。mx是表示最大长度的常数。
    for (int i = 0, j = -1, a, p; i < slen; i++, j--)
        if (j < 0 || i + nexts[i - a] >= p) {
            if (j < 0)  j = 0, p = i;
            while (p < slen && j < tlen && t[p] == t[j]) j++, p++;
            extend[i] = j, a = i;
        }
        else extend[i] = nexts[i - a];
}


int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    while (T--) {
        scanf("%s", t);
        extkmp();
        if (tlen < 3) {puts("0"); continue;}
        int maxs = 0;
        rep (i, tlen - tlen / 3, tlen) 
            if (extend[i] == tlen - i) {
                rep (j, extend[i], i - extend[i] + 1) {
                    if (extend[j] >= extend[i]) {
                        maxs = extend[i];
                        break;
                    }
                }
                if (maxs) break; 
            }
        printf("%d\n", maxs);
    }
    
    return 0;
}
