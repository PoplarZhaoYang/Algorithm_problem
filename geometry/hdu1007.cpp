#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
typedef pair<double, double> P;

struct jibancanyang
{
    int N;
    P A[112345];

    static bool comp(P a, P b) {
        return a.second < b.second;
    }

    double close(P *a, int n) {
        if (n == 1) return 1e20;
        int m = n >> 1;
        double x = a[m].first;
        double d = min(close(a, m), close(a + m, n - m));
        inplace_merge(a, a + m, a + n, comp);
        vector<P> b;
        for (int i = 0; i < n; i++) {
            if (fabs(a[i].first - x) >= d) continue;
            for (int j = 0; j < (int)b.size(); j++) {
                double dx = a[i].first - b[b.size() - j - 1].first;
                double dy = a[i].second - b[b.size() - j - 1].second;
                if (dy >= d) break;
                d = min(d, sqrt(dx * dx + dy * dy));
            }
            b.push_back(a[i]);
        }
        return d;
    }

    void fun() {
        while (~scanf("%d", &N)) {
            if (!N) return;
            for (int i = 0; i < N; i++) scanf("%lf%lf", &A[i].first, &A[i].second);
            sort(A, A + N);
            double ans = close(A, N);
            printf("%.2f\n", ans / 2);
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
