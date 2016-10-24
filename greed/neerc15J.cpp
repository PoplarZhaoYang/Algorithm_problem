#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    bool A[1001], B[1001];
    int n;

    void show(bool a[], int k = 0) {
        a[k] = !a[k];
        for (int i = 1; i <= n; ++i) putchar(a[i] ? '1' : '0');
        a[k] = !a[k];
        cout << endl;
    }

    void fun() {
        scanf("%d", &n);
        srand(time(NULL));

        while (true) {
            for (int i = 1; i <= n; ++i) A[i] = rand() % 2;
            show(A);
            int x; scanf("%d", &x);
            if (x == n / 2) break;
            if (x == n) return;
        }

        A[1] = !A[1];
        for (int i = 2; i <= n; ++i) {
            show(A, i);
            int x; scanf("%d", &x);
            if (x == n) return ;
            if (x == n / 2) B[i] = false;
            else B[i] = true;
        }


        putchar(A[1] ? '1' : '0');
        for (int i = 2; i <= n; ++i) {
            if (B[i]) putchar(!A[i] ? '1' : '0');
            else putchar(A[i] ? '1' : '0');
        }
        cout << endl;
        int x; scanf("%d", &x);
        if (x == n) return ;

        putchar(!A[1] ? '1' : '0');
        for (int i = 2; i <= n; ++i) {
            if (B[i]) putchar(A[i] ? '1' : '0');
            else putchar(!A[i] ? '1' : '0');
        }
        cout << endl;
        scanf("%d", &x);
    }

}ac;

int main()
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.fun();
    return 0;
}
