/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  5/17 23:44:56 2016
**Problem**: Codeforces Round #353 (Div. 2) C 思维
给你一个数列,本身是一个环且和为0,每次可以执行一个操作就是相邻的成员之间传递值,
问让该环所有成员的值都变为0,需要执行最少多少次操作?

**Analyse**:
> - 可以转化为求环中最多和为0的块的个数.
> - 然后因为没一个块的和都为0,所以在两个相邻的和为0的块之间该数列的前缀和是相同的,我们要求最多的块数,
只需要求最大的相同前缀和的频率即可
**Get**:
比赛的时候已经推出了第一步,不错,应该多思考,多发些性质,说不定就找到关键性质了.
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;



int main(void)
{
#ifdef LOCAL
    //freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    map<ll, ll> mp;
    int n;
    cin >> n;
   ll mins = 0, sum = 0, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[sum += x]++;
        mins = max(mins, mp[sum]);
    }
    cout << n - mins << endl;
    return 0;
}
