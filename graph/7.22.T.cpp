#include <iostream>
using namespace std;

int main() {
    char a[] = "hello", b[] = "world", c[100];
    string A = "hello", B = "world", C;
    C = A + B;
    cout << C << endl;
    strcpy(c, strcat(a, b));
    cout << c << endl;
}
