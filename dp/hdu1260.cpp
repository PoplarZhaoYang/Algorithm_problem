/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 一  4/11 11:52:31 2016
 *File Name     : jy.cpp
 *题目类型:
 *感悟:
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
#include <iomanip>
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
#define sin asd
int dp[2222], sin[2222], dou[2222];
int n, k;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&k);  
        for(int i=1;i<=k;i++)  
            scanf("%d",&sin[i]);  
        for(int i=2;i<=k;i++)  
            scanf("%d",&dou[i]);  
        dp[0]=0;  
        dp[1]=sin[1];  
        for(int i=2;i<=k;i++)  
            dp[i]=min(dp[i-1]+sin[i],dp[i-2]+dou[i]);  
        int h=dp[k]/3600+8;  
        int m=dp[k]/60%60;  
        int s=dp[k]%60;  
        if(h>12)  
            cout<<setiosflags(ios::fixed)<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<" pm"<<endl;  
        else  
            cout<<setiosflags(ios::fixed)<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<" am"<<endl;  
    }  
    return 0;
}

