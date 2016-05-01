/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 日  5/ 1 23:14:58 2016
 *File Name     : sojztb.cpp
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 3e5 + 12;
int s[maxn], l;

int getmins(int n) {
    l = n;
    int i = 0, j = 1, k = 0;
    while (k < l && i < l && j < l) {
        if (s[j] < s[i]) i = j, j = i + 1;
        else if (s[j] > s[i]) j++;
        else {
            k = 0;
            while (k < l) {
                int t = s[(j + k) % l] - s[(i + k) % l];
                if (t > 0) {
                    j = j + k + 1;  //替换1
                    break;
                } else if (t < 0) {
                    i = j;
                    j = i + 1;
                    break;
                } else {
                    k++;
                }
            }
        }
    }
    return i;
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
        int n, ans = 0, x;
        bool ok = false;
        sa(n);
        rep (i, 0, n) {
            sa(s[i]);
            if (!i) x = s[i];
            else if(s[i] != x) ok = true;
        }
        if (ok) ans = getmins(n);
            

        for (int i = ans; ; i++) {
            i = i % n;
            if (i != ans) printf(" ");
            printf("%d", s[i]);
            if (i == (ans - 1 + n) %n) break;
            
        }
        puts("");

    }
    
    return 0;
}
