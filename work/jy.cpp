#include <iostream>
using namespace std;
const int maxn = 1e5 + 13;
long long A[maxn], B[maxn];
int n, k, ans;

int main()
{
    cin >> n;
    B[0] = ans = A[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> A[i], A[i] += A[i - 1];
    cin >> k;
    for (int i = 1; i < k; ++i) B[i] = maxn * 2;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, i - int(B[A[i] % k]));
        B[A[i] % k] = min(B[A[i] % k], (long long)i);
    }
    cout << ans << endl;
    return 0;
}
