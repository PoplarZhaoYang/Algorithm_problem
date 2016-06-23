#include <iostream>
#include <string>
using namespace std;

int *test(int arr[], int n) {
    sort(arr, arr + n);
    return arr;
}

int main()
{
    int arr[] = {3, 1, 2};
    int *sorted_arr = test(arr, 3);
    for (int i = 0; i < 3; i++) {
        cout << *(sorted_arr + i) << endl;
    }
    return 0;
}
