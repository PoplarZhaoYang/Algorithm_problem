/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 六  4/30 01:27:20 2016
 *File Name     : cf667c.cpp
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;

string str;
int cnt;
pii ans[maxn];
bool anss[maxn * 10];
bool dp[maxn][2][2];


void dfs(int p, int last) {
    if (p - 1 > 4 && !dp[p][last][0]) {
        int seed = (str[p - 1] - 'a' + 1) * 26 + str[p] + 1 - 'a';
        int ls = -12;
        if (last == 2 && p + 2 < (int)str.size()) ls = (str[p + 1] - 'a' + 1) * 26 + str[p + 2] + 1 - 'a' ;
        else if (p + 3 < (int)str.size()) ls = (str[p + 1] - 'a' + 1) * 26 * 26  + (str[p + 2] - 'a' + 1) * 26 + str[p + 3] + 1 - 'a'; 
        
        dp[p][last][0] = true;
        if (ls != seed) {
            if (!anss[seed]) ans[cnt].xx = p - 1, ans[cnt].yy = 2, anss[seed] = true, cnt++;
            dfs(p - 2, 2);
        }
    }
    if (p - 2 > 4 && !dp[p][last][1]) {
        int seed = (str[p - 2] - 'a' + 1) * 26 * 26 + (str[p - 1] - 'a' + 1) * 26 + str[p]  + 1 - 'a';
        int ls = -12;
        if (last == 2 && p + 2 < (int)str.size()) ls = (str[p + 1] - 'a' + 1) * 26 + str[p + 2] + 1 - 'a' ;
        else if (p + 3 < (int)str.size()) ls = (str[p + 1] - 'a' + 1) * 26 * 26  + (str[p + 2] - 'a' + 1) * 26 + str[p + 3] + 1 - 'a'; 
        dp[p][last][1] = true;
        if (ls != seed) {
            if (!anss[seed]) ans[cnt].xx = p - 2, ans[cnt].yy = 3, anss[seed] = true, cnt++;
            dfs(p - 3, 3);
        }
    }
}


int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> str;
    if (str.size() <= 6) cout << 0 << endl;
    else {
        vector<string> vv; 
        dfs(str.size() - 1, 0);
        cout << cnt << endl;
        rep(i, 0, cnt) {
             string temp ;
             rep (j, ans[i].xx, ans[i].xx + ans[i].yy) temp += str[j];
             vv.push_back(temp);
        }
        sort(vv.begin(), vv.end());
        rep (i, 0, vv.size()) cout << vv[i] << endl;
    }
     
    return 0;
}
