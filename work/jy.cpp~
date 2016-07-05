/**
 简单贪心一下就好了
 **/
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
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
const int mod = 835672545, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;
char s[maxn / 10], aim[maxn / 10];

int main(void)
{
    while (~scanf("%s%s", s, aim)) {
        int slen = strlen(s), alen = strlen(aim);
        int k = 0;
        if (slen < alen) {
            k = alen - slen;
            for (int i = 0; i < k; i++) {
                printf("a %c\n", aim[i]);
            }
        } else if (slen > alen) {
            k = slen - alen;
            for (int i = 0; i < k; i++)  printf("d %c\n", s[i]);
            k = 0;
        }
        for (int i = k; i < alen; i++) {
            printf("m %c\n", aim[i]);
        }
    }
    return 0;
}
