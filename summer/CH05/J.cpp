/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  7/14 11:45:57 2016
**Problem**:
**Analyse**:
这个题就是神构造，具体做法如代码，但是如何想到的还不得而知，验证正解容易。
**Get**:
构造题要么小数据打表观察，要么理智猜了。。。
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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for (decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
	int n, k;
	while (~sa(n)) {
        if (n % 4 == 2 || n % 4 == 3) {
            pri(0);
            continue;
        }
		if (n % 4 == 0) {
			k = n / 4;
            printf("%d ", 2 *k + 1);
            for (int i=4*k; i>=3*k+2;i--) printf("%d ",i);
            for (int i=3*k; i>=2*k+2;i--) printf("%d ",i);
            for (int i=2*k; i>=k+1;i--) printf("%d ",i);
            printf("%d ", 3* k + 1); 
            //(3 *k + 1);
            for (int i=k;i>=1;i--) printf("%d ",i);
        } else {
            k = (n - 1) / 4; printf("%d ", 4 *k + 1);
            for (int i=4*k; i>=3*k+2; i--) printf("%d ",i);
            for (int i=3*k; i>=2*k+2;i--) printf("%d ",i);
            for (int i=2*k; i>=k+1;i--) printf("%d ",i);
            if (k)
                printf("%d ", 3* k + 1); 
            for (int i=k;i>=1;i--) printf("%d ",i);
            if(k) printf("%d ",2*k+1);
        }
        puts("");
    }
    return 0;
}
