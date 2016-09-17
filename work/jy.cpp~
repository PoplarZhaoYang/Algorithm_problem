#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
const int maxn = int(1e5) + 12;


struct jibancanyang
{
    int A[maxn], n;
    int B[maxn];
    long long sum;


    bool judge(int k) {
        long long cost = 0;
        int p = 1;
        int head = 1, tail = 1;
        int mod = (n - 1) % (k - 1) + 1;
        for (int i = 0; i < mod; ++i) {
            cost += A[p++];
        }
        if (cost) B[tail++] = cost;
        while (true) {

            long long  temp = 0;
            for (int i = 0; i < k; ++i) {
                if (p <= n && ( head >= tail || A[p] <= B[head]) ) temp += A[p++];
                else if (head < tail && (p > n || B[head] <= A[p])) temp += B[head++];
            }
            cost += temp;
            if (p > n && head >= tail) break;
            B[tail++] = temp;
        }
        return cost <= sum; 
    }


    void fun()  {
        int T;
        scanf("%d", &T);
        while (T--) {
            scanf("%d%lld", &n, &sum);
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &A[i]);
            }
            int l = 2, r = n;
            sort(A + 1, A + 1 + n);
            while (l < r) {
                int mid = (l + r) / 2;
                if (judge(mid)) r = mid;
                else l = mid + 1;
            }
            printf("%d\n", l);
        }
    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.fun();
    return 0;
}
