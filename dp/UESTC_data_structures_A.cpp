/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 二  4/19 14:02:08 2016
 *File Name     : 2016 UESTC Training for Data Structures A.cpp
 *Problem: 线段树
 *Get:区间树裸的.
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;

struct node  
{  
    ll mins;  
}tree[4 * maxn];//线段树要开4倍的点的个数  
int n, t, a, b, q;  
  
void updata(int l, int r, int root)  
{  
    if (r < a || l > a)    return;  
    if (r == l)  
    {  
        tree[root].mins -= b;  
        return;  
    }  
    int mid = (l + r) / 2;  
    updata(l, mid, root * 2);  
    updata(mid + 1,r,root * 2 + 1);  
    tree[root].mins = min(tree[root * 2].mins, tree[root * 2 + 1].mins);  
}  
  
  
ll search(int l,int r,int root)  
{  
    if(l > b || r < a)    return ll(1e18);  
    if(l >= a && r <= b)    return tree[root].mins;  
    int mid = (l + r) / 2;  
    return min( search(l, mid, root * 2), search(mid + 1,r,root * 2 + 1));  
}  
  
int main()  
{ 
   // freopen("in.txt", "r", stdin);
   // cin.sync_with_stdio(false);  
    sa(n), sa(q); 
    for(int i = 0; i < q; i++) {  
        scanf("%d%d%d",&t,&a,&b);  
        //cin >> t >> a >> b;
        if(t == 1)  updata(1, n, 1);  
        if(t == 2)  printf("%lld\n", -search(1, n, 1));  
    }  
  
    return 0;  
}  
