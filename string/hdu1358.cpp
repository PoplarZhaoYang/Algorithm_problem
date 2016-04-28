/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 五  4/29 01:14:55 2016
 *File Name     : hdu1358.cpp
 *Problem:用kmp的next数组求循环节
 *Get:注意的是我的模板的kmp有一个剪枝优化,导致next数组的本性是改变了的,所以在
 利用next数组的性质来求循环节的时候应该去掉这个剪枝优化.
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
int plen, nexts[maxn];
char p[maxn];

void getnexts(void) {
    nexts[0] = -1;
    int k = -1, j = 0;
    while (j <= plen) {
        if (k == -1 || p[j] == p[k]) {
            j++, k++;
             nexts[j] = k;
            //else nexts[j] = nexts[k];
        } else k = nexts[k];
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    while (sa(plen), plen) {
        scanf("%s", p);
        printf("Test case #%d\n", T++);
        getnexts();


        rep (i, 2, plen + 1) {
            if (nexts[i] > 0) {
                int x = i - nexts[i];
                if (i % x == 0) {
                    printf("%d %d\n", i, i / x);
                }
            }
        }
        puts(""); 
    }
    
    return 0;
}
