/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 日  5/ 8 00:09:05 2016
 *File Name*     : zoj3430.cpp
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;
int a[5555], num[5555], n;
int ans[5555];


int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    sa(n);
    for (int i = 1; i <= n; i++) sa(a[i]);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            num[a[j]]++;
            if (num[a[j]] == num[cur] && a[j] < cur) {
                ans[a[j]]++;
                cur = a[j];
            } else if (num[a[j]] > num[cur]) {
                ans[a[j]]++;
                cur = a[j];
            } else ans[cur]++;
        }
        for (int j = 0; j <= n; j++) num[j] = 0;
        cur = 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " "; 
    }
    cout << endl;
    
    return 0;
}
