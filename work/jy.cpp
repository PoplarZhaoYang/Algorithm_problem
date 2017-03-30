#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

void my_quick_sort(int *A, int l, int r) {
    if (l >= r) return;
    int p = l, a = l, b = r;
    bool flag = true;
    while (a < b) {
        if (flag) {
            while (a < b) {
                if (A[b] < A[p]) {
                    swap(A[b], A[p]), a = p + 1, p = b;
                    flag = !flag;
                    break;
                }
                --b;
            }
        } else {
            while (a < b) {
                if (A[a] >= A[p]) {
                    swap(A[a], A[p]), b = p - 1, p = a;
                    flag = !flag;
                    break;
                }
                ++a;
            }
        }
    }
    my_quick_sort(A, l, p - 1);
    my_quick_sort(A, p + 1, r);
}

int main()
{
#ifdef xiaoai
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int A[] = {6, 5, 55, 3, 2, 23, 2, 2, 78, 7, 8};
    my_quick_sort(A, 0, sizeof(A) / sizeof(int) - 1);
    for (auto c: A) cout << c << " ";
    cout << endl;
    return 0;
}
