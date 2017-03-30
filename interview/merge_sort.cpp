#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

void merge(int *A, int l, int r, int a, int b) {
    int p = 0, sl = l, sr = b;
    int *B = new int[b - l + 1];
    while (l <= r && a <= b) B[p++] = A[l] < A[a] ? A[l++] : A[a++];
    while (l <= r) B[p++] = A[l++];
    while (a <= b) B[p++] = A[a++];
    for (int i = sl, j = 0; i <= sr; ++i) A[i] = B[j++];
    delete []B;
}

void merge_sort(int A[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    merge_sort(A, l, mid);
    merge_sort(A, mid + 1, r);
    merge(A, l, mid, mid + 1, r);
}


int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int A[] = {1, 5, 5, 2, 8, 2, 7, 9, 5, 6, 5};
    merge_sort(A, 0, sizeof(A) / sizeof(int) - 1);
    for (auto c: A) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
