#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

void down(int *A, int p, int len) {
    if (p == len) return;
    int lson = p * 2 + 1, rson = p * 2 + 2, maxv = A[p], maxp = p;
    if (lson < len && A[lson] > maxv) maxv = A[lson], p = lson; 
    if (rson < len && A[rson] > maxv) maxv = A[rson], p = rson;
    swap(A[maxp], A[p]);
    if (p != maxp) down(A, p, len);
}

void heap_sort(int *A, int len) {
    for (int i = (len - 1) / 2; i >= 0; --i) down(A, i, len);
    for (int i = len - 1; i >= 0; --i) {
        swap(A[i], A[0]);
        down(A, 0, i);
    }
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int A[] = {1, 15, 5, 2, 8, 2, 7, 9, 5, 6, 5};
    heap_sort(A, sizeof(A) / sizeof(int));
    for (auto c: A) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
