#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int n, k;
    double l, v1, v2;

    void run() {
        while (cin >> n >> l >> v1 >> v2 >> k) {
            double a = (v2 - v1) /(v2 + v1) * v1 + v1;
            double b = (k + n - 1) / k - 1;
            double t2 = l / (a * b + v2);
            double t1 = (l - v2 * t2) / v1;
            printf("%.14f\n", t1 + t2);
        }
    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.run();
    return 0;
}
