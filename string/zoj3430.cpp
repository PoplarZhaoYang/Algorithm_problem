/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 六  5/ 7 21:17:06 2016
 *File Name*     : poj2752.cpp
**Problem**:扩展kmp   
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 4e5 + 13;
char t[maxn], s[maxn];
int nexts[maxn], extend[maxn], slen, tlen;

//计算next数组，保存到next参数中。
void getextendnexts(void)
{
    tlen = slen = strlen(s);
    for (int i = 1, j = -1, a, p; i < tlen; i++, j--)
        if (j < 0 || i + nexts[i - a] >= p) {
            if (j < 0)  j = 0, p = i;
            while (p < tlen && t[j] == t[p]) j++, p++;
            nexts[i] = j, a = i;
        }
        else nexts[i] = nexts[i - a];
}

void getextend (void)
{
    getextendnexts();  //计算next数组。mx是表示最大长度的常数。
    for (int i = 0, j = -1, a, p; i < slen; i++, j--)
        if (j < 0 || i + nexts[i - a] >= p) {
            if (j < 0)  j = 0, p = i;
            while (p < slen && j < tlen && s[p] == t[j]) j++, p++;
            extend[i] = j, a = i;
        }
        else extend[i] = nexts[i - a];
}


int main(void)
{
#ifdef LOCAL
//    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while (~scanf("%s", s)) {
        memcpy(t, s, sizeof(s));
        getextend();
        for (int i = slen - 1; i >= 0; i--) {
            if (extend[i] >= slen - i) {
                printf("%d ", slen - i);
            }
        }
        printf("\n");
    }
    return 0;
}
